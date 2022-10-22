/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_in_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 00:27:19 by mnathali          #+#    #+#             */
/*   Updated: 2022/05/13 23:42:49 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**get_args_to_exec(t_list *lst)
{
	int		i;
	char	**args;

	i = 0;
	args = malloc(sizeof(*args) * (ft_lstsize(lst) + 1));
	if (!args)
		return (0);
	while (lst)
	{
		args[i] = lst->content;
		lst = lst->next;
		i++;
		if (lst && !lst->next && !ft_strlen(lst->content))
		{
			args[i + 1] = 0;
			break ;
		}
	}
	args[i] = 0;
	return (args);
}

void	remove_elements(t_list *column, t_list	*lst_1)
{
	t_list	*lst_2;

	lst_2 = column->content;
	if (lst_1 == lst_2)
		column->content = lst_1->next->next;
	while (lst_2 != lst_1 && lst_2->next != lst_1)
		lst_2 = lst_2->next;
	if (lst_2 != lst_1)
		lst_2->next = lst_1->next->next;
	lst_1->next->next = 0;
	ft_lstclear(&lst_1, free);
	return ;
}

char	**change_in(t_list *column)
{
	int		fd;
	t_list	*lst_1;

	lst_1 = column->content;
	while (ft_strcmp(lst_1->content, "<"))
		lst_1 = lst_1->next;
	if (check_bad_syntax(lst_1->next))
		return (0);
	fd = open(lst_1->next->content, O_RDONLY);
	if (fd < 0)
	{
		perror(lst_1->next->content);
		return (0);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	remove_elements(column, lst_1);
	return (get_args_to_exec(column->content));
}

char	**change_out(t_list *column)
{
	int		fd;
	t_list	*lst_1;

	lst_1 = column->content;
	while (ft_strcmp(lst_1->content, ">") && ft_strcmp(lst_1->content, ">>"))
		lst_1 = lst_1->next;
	if (check_bad_syntax(lst_1->next))
		return (0);
	if (ft_strcmp(lst_1->content, ">") == 0)
		fd = open(lst_1->next->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(lst_1->next->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		perror(lst_1->next->content);
		return (0);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	remove_elements(column, lst_1);
	return (get_args_to_exec(column->content));
}

char	**change_in_out_delim(t_list *column)
{
	char	**arr;

	arr = 0;
	if (look_var(column->content, "<<"))
		arr = set_delim(column);
	else if (look_var(column->content, "<"))
		arr = change_in(column);
	else if (look_var(column->content, ">") || look_var(column->content, ">>"))
		arr = change_out(column);
	return (arr);
}
