/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 01:11:34 by mnathali          #+#    #+#             */
/*   Updated: 2022/05/14 01:32:06 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	set_new_pwd(t_mini *shell, t_list *envp, char *pwd)
{
	char	*new_var;

	new_var = ft_strjoin("PWD=", pwd);
	if (!new_var)
		return (1);
	ft_lstclear(&shell->args, clear_content);
	shell->args = get_args(parse_args(new_var));
	set_variables(shell, envp);
	return (0);
}

int	mini_cd(t_mini *shell, t_list *envp)
{
	int		i;
	int		code;
	char	*home_dir;
	t_list	*args;

	code = 1;
	args = shell->args->content;
	home_dir = look_var(envp, "HOME");
	i = ft_lstsize(args);
	if (i == 1 && home_dir)
		home_dir = ft_strchr(home_dir, '=') + 1;
	if (i > 2)
		print_error("cd : too many arguments\n");
	else if (i == 2 && chdir(args->next->content))
		perror("cd ");
	else if (i == 1 && chdir(home_dir))
		ft_putstr_fd("mshell : cd : HOME not set\n", 2);
	else
	{
		home_dir = getcwd(0, 0);
		code = set_new_pwd(shell, envp, home_dir);
		if (home_dir)
			free(home_dir);
	}
	return (code);
}
