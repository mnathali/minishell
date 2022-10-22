/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:34:20 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/06 20:34:20 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	length;
	size_t	srclen;

	length = 0;
	srclen = ft_strlen(src);
	while (*dest && size > 0)
	{
		dest++;
		length++;
		size--;
	}
	while (*src && size-- > 1)
		*dest++ = *src++;
	if (size == 0 || *src == 0)
		*dest = '\0';
	return (srclen + length);
}
