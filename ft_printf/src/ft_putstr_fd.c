/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 23:29:27 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/07 23:29:27 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include"../include/libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	printed;

	if (!s)
		return (write(fd, &"(null)", 6));
	printed = 0;
	while (*s)
		printed += write(fd, s++, 1);
	return (printed);
}
