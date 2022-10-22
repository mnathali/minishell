/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:30:05 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/08 12:30:05 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"
#include<unistd.h>

static int	pow(int n, int power)
{
	int	i;
	int	nbr;

	if (power == 0)
		return (1);
	if (power == 1)
		return (n);
	i = 1;
	nbr = n;
	while (i < power)
	{
		nbr *= n;
		i++;
	}
	return (nbr);
}

static unsigned int	ft_abs(int n)
{
	unsigned int	res;

	if (n < 0)
		res = -n;
	else
		res = n;
	return (res);
}

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	unsigned int	cnbr;
	int				nlen;
	char			current;
	int				printed;

	if (n == 0)
		return ((write(fd, "0", 1)));
	nbr = ft_abs(n);
	printed = 0;
	if (n < 0)
		printed += write(fd, "-", 1);
	nlen = 0;
	cnbr = nbr;
	while (cnbr > 0)
	{
		cnbr /= 10;
		nlen++;
	}
	while (nlen > 0)
	{
		current = (nbr / pow(10, nlen-- - 1) % 10) + '0';
		printed += ft_putchar_fd(current, 1);
	}
	return (printed);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned int	nbr;
	int				nlen;
	char			current;
	int				printed;

	printed = 0;
	if (n == 0)
		return ((write(fd, "0", 1)));
	nbr = n;
	nlen = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		nlen++;
	}
	while (nlen > 0)
	{
		current = (n / pow(10, nlen-- - 1) % 10) + '0';
		printed += ft_putchar_fd(current, 1);
	}
	return (printed);
}
