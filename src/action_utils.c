/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 00:31:54 by mnathali          #+#    #+#             */
/*   Updated: 2022/05/18 21:19:50 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_double_join(char *s1, char *s2, char *s3)
{
	char	*str;
	char	*folder;

	folder = ft_strjoin(s1, s2);
	if (!folder)
		return (0);
	str = ft_strjoin(folder, s3);
	free(folder);
	if (!str)
		return (0);
	return (str);
}

void	find_bin_in_path(char **arr, t_list *envp)
{
	char	**path;
	int		i;
	char	*str;

	i = 0;
	if (!arr || !arr[0] || !look_var(envp, "PATH"))
		return ;
	path = ft_split(ft_strchr(look_var(envp, "PATH"), '=') + 1, ':');
	while (path && path[i])
	{
		str = ft_double_join(path[i], "/", arr[0]);
		if (!str)
			break ;
		if (!access(str, F_OK))
		{
			free(arr[0]);
			arr[0] = str;
			break ;
		}
		free(str);
		i++;
	}
	free_arr(path);
}

void	set_variables(t_mini *shell, t_list *envp)
{
	t_list	*arg_list;
	t_list	*lst;
	int		status;

	status = 0;
	arg_list = shell->args->content;
	if (!ft_strchr(arg_list->content, '='))
		return ;
	while (arg_list && ft_strchr(arg_list->content, '='))
	{
		expand_variable(arg_list, shell->var_list);
		str_remove_cage_quotes(arg_list->content);
		status = add_new_variable(shell, arg_list, envp);
		lst = arg_list;
		arg_list = arg_list->next;
		shell->args->content = arg_list;
		free(lst->content);
		free(lst);
	}
	expand_variables(shell);
	change_var_value(shell->var_list, "?", ft_itoa(status));
}

void	change_var_value(t_list *env_list, char *name, char *value)
{
	t_variable	*var;
	t_list		*lst;

	lst = env_list;
	while (lst)
	{
		var = lst->content;
		if (!ft_strcmp(var->name, name))
			break ;
		lst = lst->next;
	}
	if (var->value)
		free(var->value);
	var->value = value;
	return ;
}

void	close_fd(int *fd, int size)
{
	if (fd == 0)
		return ;
	size--;
	while (size > 0)
	{
		size--;
		close(fd[2 * size + 1]);
		close(fd[2 * size]);
	}
	free(fd);
}

/*int	ft_isstr(t_list *column, char *str)
{
	t_list	*lst;

	lst = column->content;
	while (lst)
	{
		if (!ft_strcmp(lst->content, str))
			return (1);
		lst = lst->next;
	}
	return (0);
}*/