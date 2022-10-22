/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:46:34 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/07 21:46:34 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"../include/libft.h"

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

static int	ft_nbrlen(unsigned int n)
{
	int				nbrlen;

	nbrlen = 0;
	while (n > 0)
	{
		nbrlen++;
		n /= 10;
	}
	return (nbrlen);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				nbrlen;
	char			*number;
	int				i;

	nbr = ft_abs(n);
	nbrlen = ft_nbrlen(nbr);
	number = malloc(nbrlen + 1 + (n < 0) + (n == 0));
	if (!number)
		return ((void *)0);
	i = 0;
	if (n == 0)
		number[i++] = '0';
	if (n < 0)
		number[i++] = '-';
	while (nbrlen > 0)
		number[i++] = (nbr / pow(10, nbrlen-- - 1) % 10) + '0';
	number[i] = '\0';
	return (number);
}
