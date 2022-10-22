/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 09:53:17 by mnathali          #+#    #+#             */
/*   Updated: 2022/05/18 17:33:13 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*look_var(t_list *envp, char *name)
{
	int		i;
	char	*var;

	while (envp)
	{
		i = 0;
		var = envp->content;
		while (var[i] == name[i] && name[i] != 0)
			i++;
		if (i && name[i] == 0 && (var[i] == '=' || var[i] == 0))
			break ;
		envp = envp->next;
	}
	if (envp)
		return (envp->content);
	return (0);
}

int	add_new_variable(t_mini *shell, t_list *args, t_list *envp)
{
	char	*str;
	char	**var_array;

	str = args->content;
	if (str[0] == '=' || !*(ft_strchr(str, '=') + 1)
		|| !ft_strncmp("?=", str, 2))
		return (0 * ft_putstr_fd("error : command not found\n", 2) + 127);
	var_array = read_variable(str);
	if (!var_array)
		return (1);
	if (get_variable_by_name(shell->var_list, var_array[0]))
		change_var_value(shell->var_list, var_array[0], var_array[1]);
	else
		ft_lstadd_front(&shell->var_list,
			ft_lstnew(new_var(ft_strdup(var_array[0]), var_array[1])));
	args = get_variable_by_name(shell->var_list, var_array[0]);
	if (look_var(envp, var_array[0]))
		move_var_to_env(args->content, envp);
	free(var_array[0]);
	free(var_array);
	return (0);
}

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

t_list	*ft_arrdup_to_lst(char **arr)
{
	t_list	*lst;
	t_list	*new;
	int		i;

	lst = 0;
	i = ft_arrlen(arr);
	if (!i)
		return (0);
	while (i)
	{
		i--;
		new = ft_lstnew(ft_strdup(arr[i]));
		if (!new)
		{
			ft_lstclear(&lst, free);
			return (0);
		}
		ft_lstadd_front(&lst, new);
	}
	return (lst);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return ;
}
