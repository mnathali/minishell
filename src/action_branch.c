/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_branch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 23:07:22 by mnathali          #+#    #+#             */
/*   Updated: 2022/05/18 20:49:48 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**replace_fd(t_list *column, int *fd, int i, int size)
{
	char	**arr;
	int		n;

	n = 2;
	arr = 0;
	if (column->next)
		dup2(fd[2 * i + 1], STDOUT_FILENO);
	while (2 * i + n < 2 * size - 2)
		close(2 * i + n++);
	if (i)
		dup2(fd[2 * i - 2], STDIN_FILENO);
	while (look_var(column->content, "<") || look_var(column->content, ">")
		|| look_var(column->content, ">>") || look_var(column->content, "<<"))
	{
		if (arr)
			free(arr);
		arr = change_in_out_delim(column);
		if (!arr)
			return (0);
	}
	if (!arr)
		arr = get_args_to_exec(column->content);
	return (arr);
}

void	run_bins(char **arr, t_list *envp)
{
	char	**arr_envp;

	arr_envp = get_args_to_exec(envp);
	exec_input(arr, envp);
	if (arr[0][0] != '.' && arr[0][0] != '/')
	{
		find_bin_in_path(arr, envp);
		if (execve(arr[0], arr, arr_envp))
		{
			print_error(arr[0]);
			print_error(" : command not found\n");
		}
	}
	else if (arr && arr[0] && execve(arr[0], arr, arr_envp))
		perror(arr[0]);
	free_arr(arr);
	free_arr(arr_envp);
	exit(127);
}

int	*create_pipes(t_list *columns)
{
	int	i;
	int	*fd;
	int	size;

	i = 0;
	size = ft_lstsize(columns);
	if (size < 2)
		return (0);
	fd = malloc(sizeof(*fd) * (size * 2 - 2));
	if (!fd)
		return (0);
	while (i / 2 != size - 1)
	{
		pipe(&fd[i]);
		i += 2;
	}
	return (fd);
}

int	children_to_exec(t_list *columns, int *fd, t_list *envp)
{
	int	i;
	int	size;
	int	pid;

	i = 0;
	size = ft_lstsize(columns);
	while (columns)
	{
		pid = fork();
		if (pid < 0)
			break ;
		else if (pid == 0)
			run_bins(replace_fd(columns, fd, i, size), envp);
		if (columns->next)
			close(fd[2 * i + 1]);
		if (i)
			close(fd[2 * i - 2]);
		i++;
		columns = columns->next;
		wait(&pid);
		if (WEXITSTATUS(pid) == 127 || WIFSIGNALED(pid) == 1)
			break ;
	}
	return (ft_status(fd, 2 * i, size, &pid));
}

void	action_branch(t_mini *shell, t_list *envp)
{
	int		*fd;
	int		status;
	t_list	*arg_list;

	arg_list = (t_list *)(shell->args->content);
	if (!arg_list || !ft_strlen(arg_list->content))
		return ;
	g_child = 1;
	unset_shell_atrr();
	fd = create_pipes(shell->args);
	if (!fd && shell->args->next)
		return ;
	if (shell->args->next == 0 && !ft_strcmp(arg_list->content, "cd"))
		status = mini_cd(shell, envp);
	else if (shell->args->next == 0 && !ft_strcmp(arg_list->content, "export"))
		status = mini_export(shell, envp);
	else if (shell->args->next == 0 && !ft_strcmp(arg_list->content, "unset"))
		status = mini_unset(shell, envp);
	else if (shell->args->next == 0 && !ft_strcmp(arg_list->content, "exit"))
		status = shell_exit(shell, envp);
	else
		status = children_to_exec(shell->args, fd, envp);
	change_var_value(shell->var_list, "?", ft_itoa(status));
	g_child = 0;
	set_shell_attr();
}
