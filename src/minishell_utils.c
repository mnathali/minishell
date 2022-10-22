/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:46:47 by zyasuo            #+#    #+#             */
/*   Updated: 2022/05/12 14:14:54 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_error(char *error)
{
	write(2, error, ft_strlen(error));
}

void	exec_input(char **input, t_list *envp)
{
	int	i;

	i = 0;
	if (!ft_strcmp("pwd", input[0]))
		mini_pwd();
	else if (!ft_strcmp("clear", input[0]))
		mini_clear();
	else if (!ft_strcmp("echo", input[0]))
		mini_echo(input);
	else if (!ft_strcmp("env", input[0]))
		mini_env(envp, "");
	else if (!ft_strcmp("export", input[0]) && !input[1])
		mini_env(envp, "declare -x ");
	else if (!ft_strcmp("exit", input[0]) || !ft_strcmp("export", input[0])
		|| !ft_strcmp("unset", input[0]) || !ft_strcmp("cd", input[0]))
		i = 1;
	else
		return ;
	free_arr(input);
	ft_lstclear(&envp, free);
	exit(i);
}
