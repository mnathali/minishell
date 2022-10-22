/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:50:01 by zyasuo            #+#    #+#             */
/*   Updated: 2022/05/18 20:55:25 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_status(int *fd, int i, int size, int *pid)
{
	if (fd)
	{
		while (i != 2 * size)
			close(fd[i++]);
		free(fd);
	}
	if (pid < 0)
		return (127);
	else if (WIFSIGNALED(*pid) == 1)
		return (128 + WTERMSIG(*pid));
	return (WEXITSTATUS(*pid));
}
