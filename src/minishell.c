/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:39:28 by zyasuo            #+#    #+#             */
/*   Updated: 2022/05/18 21:00:38 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	loop_shell(t_mini *shell, t_list *envp)
{
	char	*input;

	if (!envp)
		return ;
	while (1)
	{
		if (!read_input(&input, shell, envp))
			continue ;
		if (g_child == 130)
			change_var_value(shell->var_list, "?", ft_itoa(130));
		shell->args = get_args(parse_args(input));
		if (!shell->args)
		{
			ft_lstclear(&shell->args, clear_content);
			print_error("Bad syntax.\n");
			free(input);
			continue ;
		}
		set_variables(shell, envp);
		expand_variables(shell);
		ft_lstiter(shell->args, remove_quotes);
		action_branch(shell, envp);
		ft_lstclear(&shell->args, clear_content);
		free(input);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mini				*shell;

	(void) argv;
	if (argc > 1)
		return (0 * ft_printf(ARGERROR));
	if (create_shell(&shell, envp))
		return (1);
	unset_shell_atrr();
	set_shell_attr();
	g_child = 0;
	loop_shell(shell, ft_arrdup_to_lst(envp));
	unset_shell_atrr();
	return (0);
}
