/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:27:27 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/28 19:27:27 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	is_repeated(char *str)
{
	int	i;
	int	j;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int		b;
	int		i;
	int		number[19];
	int		printed;

	printed = 0;
	if (!base)
		return (printed);
	if (nbr == 0)
		printed += ft_putchar_fd('0', 1);
	b = ft_strlen(base);
	if (is_repeated(base) || ft_strlen(base) < 2
		|| ft_strchr(base, '+') || ft_strchr(base, '-'))
		return (0);
	i = 0;
	while (nbr > 0)
	{
		number[i] = base[nbr % b];
		nbr /= b;
		i++;
	}
	while (i-- > 0)
		printed += ft_putchar_fd(number[i], 1);
	return (printed);
}
