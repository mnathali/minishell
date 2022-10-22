/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 00:25:00 by mnathali          #+#    #+#             */
/*   Updated: 2022/05/14 01:31:50 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_bad_syntax(t_list *lst)
{
	if (!lst || !ft_strcmp(lst->content, "<<") || !ft_strcmp(lst->content, ">")
		|| !ft_strcmp(lst->content, "<") || !ft_strcmp(lst->content, ">>"))
	{
		ft_putstr_fd("Error : bad syntax\n", 2);
		return (1);
	}
	return (0);
}

void	write_to_the_file(int fd, t_list *lst_1)
{
	char	*str[2];

	str[0] = readline("> ");
	while (ft_strcmp(str[0], lst_1->next->content))
	{
		write(fd, str[0], ft_strlen(str[0]));
		write(fd, "\n", 1);
		free(str[0]);
		str[0] = readline("> ");
	}
	free(str[0]);
	close(fd);
	return ;
}

char	**set_delim(t_list *column)
{
	int		fd;
	t_list	*lst_1;

	lst_1 = column->content;
	while (ft_strcmp(lst_1->content, "<<"))
		lst_1 = lst_1->next;
	if (check_bad_syntax(lst_1->next))
		return (0);
	fd = open("/tmp/here-doc-minishell", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (0);
	write_to_the_file(fd, lst_1);
	remove_elements(column, lst_1);
	if (look_var(column->content, "<<"))
		return (get_args_to_exec(column->content));
	fd = open("/tmp/here-doc-minishell", O_RDONLY);
	if (fd < 0)
	{
		perror(lst_1->next->content);
		return (0);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (get_args_to_exec(column->content));
}
