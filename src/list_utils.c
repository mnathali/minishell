/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:18:47 by zyasuo            #+#    #+#             */
/*   Updated: 2022/05/18 21:00:34 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void	print_content(void *content)
// {
// 	ft_printf("%s --- %d ", (char *)content, ft_strlen((char *)content));
// }

// void	print_args(void *args)
// {
// 	ft_lstiter((t_list *) args, print_content);
// 	ft_printf("\n");
// }

void	clear_content(void *lst)
{
	ft_lstclear((t_list **)&lst, free);
}

t_list	*get_variable_by_name(t_list *var_list, char *name)
{
	t_list		*current;

	if (!var_list)
		return (NULL);
	current = var_list;
	while (current)
	{
		if (!ft_strcmp(((t_variable *)current->content)->name, name))
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	str_remove_cage_quotes(void *content)
{
	char	*str;

	str = (char *)content;
	if (str[0] == '\'' || str[0] == '\"')
	{
		ft_memmove(&str[0], &str[1], ft_strlen(str));
		str[ft_strlen(str + 1)] = '\0';
	}
}

void	remove_quotes(void *content)
{
	ft_lstiter((t_list *) content, str_remove_cage_quotes);
}
