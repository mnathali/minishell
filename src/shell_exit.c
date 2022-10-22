/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:28:02 by mnathali          #+#    #+#             */
/*   Updated: 2022/05/14 00:39:17 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	clear_shell(t_mini *shell)
{
	ft_lstclear(&shell->var_list, destroy_var);
	ft_lstclear(&shell->args, clear_content);
}

int	shell_exit(t_mini *shell, t_list *envp)
{
	int		i;
	int		code;
	char	*str;

	i = 0;
	code = 1;
	str = 0;
	if (shell->args && ((t_list *)(shell->args->content))->next)
		str = ((t_list *)(shell->args->content))->next->content;
	while (str && str[i] && code == 1)
	{
		if (!ft_isdigit(str[i]))
			code = 2;
		i++;
	}
	if (shell->args && ft_lstsize(shell->args->content) > 2 && code == 1)
		return (0 * printf("mshell: exit: too many arguments\n") + 1);
	if (code == 1 && str)
		code = ft_atoi(str);
	clear_shell(shell);
	ft_lstclear(&envp, free);
	free(shell);
	write(1, "exit\n", 5);
	unset_shell_atrr();
	exit(code);
}
