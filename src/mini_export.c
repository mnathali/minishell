/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:53:12 by zyasuo            #+#    #+#             */
/*   Updated: 2022/05/12 15:39:17 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	move_var_to_env(t_variable *found, t_list *envp)
{
	t_list	*lst;
	char	*content;

	lst = envp;
	while (lst)
	{
		if (ft_strcmp(lst->content, found->name) == 61
			|| !ft_strcmp(lst->content, found->name))
			break ;
		lst = lst->next;
	}
	content = ft_double_join(found->name, "=", found->value);
	if (!lst && content)
	{
		lst = ft_lstnew(content);
		if (lst)
			ft_lstadd_back(&envp, lst);
		else
			free(content);
	}
	else if (content)
	{
		free(lst->content);
		lst->content = content;
	}
}

void	put_var_to_env(t_mini *shell, t_list *envp, char *var)
{
	char	*str;
	t_list	*new;

	str = ft_strdup(var);
	if (!str)
		return ;
	new = ft_lstnew(str);
	if (!new)
	{
		free(str);
		return ;
	}
	ft_lstadd_back(&envp, new);
	if (ft_strchr(var, '=') && *(ft_strchr(var, '=') + 1) != 0)
		add_new_variable(shell,
			((t_list *)(shell->args->content))->next, envp);
	return ;
}

int	mini_export(t_mini *shell, t_list *envp)
{
	char	*var;
	t_list	*found;

	if (((t_list *)(shell->args->content))->next == 0)
		return (0 * mini_env(envp, "declare -x "));
	var = ((t_list *)(shell->args->content))->next->content;
	found = get_variable_by_name(shell->var_list, var);
	if (found)
		move_var_to_env(found->content, envp);
	else
		put_var_to_env(shell, envp, var);
	return (0);
}
