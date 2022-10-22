/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:34:16 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/06 20:34:16 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	t;
	int				strlen;
	int				i;

	strlen = ft_strlen(str) + 1;
	t = c;
	i = 0;
	while (i < strlen)
	{
		if (str[i] == t)
			return ((char *)(str + i));
		i++;
	}
	return ((void *)0);
}
