/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:29:29 by                   #+#    #+#             */
/*   Updated: 2021/10/05 19:29:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*pdest;
	char	*psrc;

	if (dest == (void *)0 && src == (void *)0)
		return ((void *)0);
	pdest = (char *)dest;
	psrc = (char *)src;
	if ((psrc < pdest) && (pdest < psrc + n))
	{
		pdest += n;
		psrc += n;
		while (n--)
			*--pdest = *--psrc;
	}
	else
		while (n--)
			*pdest++ = *psrc++;
	return (dest);
}
