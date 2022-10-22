/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:27:50 by                   #+#    #+#             */
/*   Updated: 2021/10/05 19:27:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*srccopy;
	char			*destcopy;
	unsigned int	i;

	if (!src && !dest)
		return ((void *)0);
	srccopy = (char *)src;
	destcopy = (char *)dest;
	i = 0;
	while (i < n)
	{
		destcopy[i] = srccopy[i];
		i++;
	}
	return (dest);
}
