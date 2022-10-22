/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:34:36 by mnathali          #+#    #+#             */
/*   Updated: 2022/05/12 15:25:05 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	remove_var_frst(t_list **lst, char *str)
{
	t_list	*elem;
	t_list	*envp;

	envp = *lst;
	if (!ft_strcmp(envp->content, str) || ft_strcmp(envp->content, str) == 61)
	{
		*lst = envp->next;
		free(envp->content);
		free(envp);
		return ;
	}
	while (envp->next)
	{
		if (!ft_strcmp(envp->next->content, str)
			|| ft_strcmp(envp->next->content, str) == 61)
		{
			elem = envp->next;
			envp->next = elem->next;
			free(elem->content);
			free(elem);
			break ;
		}
		envp = envp->next;
	}
	return ;
}

void	remove_var_scnd(t_list **env_lst, char *str)
{
	t_list		*lst;
	t_list		*var_lst;
	t_variable	*var;

	var_lst = *env_lst;
	if (!ft_strcmp(((t_variable *)(var_lst->content))->name, str))
	{
		*env_lst = var_lst->next;
		destroy_var(var_lst->content);
		free(var_lst);
		return ;
	}	
	while (var_lst->next)
	{
		var = var_lst->next->content;
		if (!ft_strcmp(var->name, str))
		{
			lst = var_lst->next;
			var_lst->next = lst->next;
			destroy_var(lst->content);
			free(lst);
			break ;
		}
		var_lst = var_lst->next;
	}
}

int	mini_unset(t_mini *shell, t_list *envp)
{
	t_list	*lst;

	lst = shell->args->content;
	lst = lst->next;
	while (lst)
	{
		if (!ft_strcmp("?", lst->content))
			return (0 * ft_putstr_fd("mshell: unset: '?' not valid\n", 2) + 1);
		remove_var_frst(&envp, lst->content);
		remove_var_scnd(&shell->var_list, lst->content);
		lst = lst->next;
	}
	return (0);
}
