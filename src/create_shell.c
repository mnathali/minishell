/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:06:52 by zyasuo            #+#    #+#             */
/*   Updated: 2022/04/25 18:25:40 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_mini	*new_shell(void)
{
	t_mini	*shell;

	shell = malloc(sizeof(*shell));
	if (!shell)
		return (NULL);
	shell->args = NULL;
	shell->var_list = NULL;
	return (shell);
}

int	create_shell(t_mini **pointer, char **envp)
{
	t_mini				*shell;

	*pointer = new_shell();
	if (!(*pointer))
		return (1);
	shell = *pointer;
	mini_clear();
	shell->var_list = get_environ(envp);
	if (!shell->var_list)
		return (1);
	ft_printf("Welcome to Minishell!\n");
	return (0);
}
