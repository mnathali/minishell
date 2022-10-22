/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:51:34 by zyasuo            #+#    #+#             */
/*   Updated: 2022/05/18 20:52:27 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	interrupt(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		if (!g_child)
			rl_redisplay();
		g_child = 130;
	}
}

void	set_shell_attr(void)
{
	struct termios		termios_p;
	struct sigaction	sa;

	sa.sa_handler = &interrupt;
	sigaction(SIGQUIT, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);
	tcgetattr(0, &termios_p);
	termios_p.c_cc[VQUIT] = 0;
	termios_p.c_cc[VINTR] = 3;
	tcsetattr(0, 0, &termios_p);
}

void	silence_signal(int sig)
{
	(void) sig;
	if (sig == SIGQUIT)
		ft_printf("Quit\n");
	else
		write(1, "\n", 1);
}

void	unset_shell_atrr(void)
{
	static struct termios	termios_p;
	struct sigaction		sa;

	sa.sa_handler = &silence_signal;
	sigaction(SIGQUIT, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);
	if (termios_p.c_cflag == 0)
		tcgetattr(0, &termios_p);
	else
		tcsetattr(0, 0, &termios_p);
}
