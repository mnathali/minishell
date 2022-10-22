/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:08:42 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/06 21:08:42 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

static int	out_of_bounds(char c, int sign)
{
	if (c == '8' && sign == 1)
		return (-1);
	else if (c >= '8' && sign == -1)
		return (0);
	else if (c == '7' && sign == 1)
		return (-1);
	else if (c == '7' && sign == -1)
		return (1);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	while (ft_isdigit(str[i]))
	{
		if (i == 19)
			return (out_of_bounds(str[i], sign));
		if (i > 19)
		{
			if (sign == 1)
				return (-1);
			if (sign == -1)
				return (0);
		}
		result = result * 10 + (str[i++] - '0');
	}
	return (sign * result);
}
