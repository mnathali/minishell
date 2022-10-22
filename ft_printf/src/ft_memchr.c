/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:31:43 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/06 20:31:43 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*pstr;

	pstr = (const unsigned char *)str;
	while (n-- > 0)
	{
		if (*pstr == (unsigned char)c)
			return ((unsigned char *)pstr);
		pstr++;
	}
	return ((void *)0);
}
