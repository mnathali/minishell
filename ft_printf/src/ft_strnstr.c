/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:56:17 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/06 20:56:17 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			littlelen;
	size_t			i;
	size_t			biglen;

	biglen = ft_strlen(big);
	littlelen = ft_strlen(little);
	if (len > biglen)
		len = biglen;
	if (littlelen > len)
		return ((void *)0);
	if (littlelen != 0)
	{
		i = 0;
		while (*big && i < len + 1)
		{
			if (i + littlelen > len)
				return ((void *)0);
			if (ft_strncmp(big, little, littlelen) == 0)
				return ((char *) big);
			big++;
			i++;
		}
	}
	return ((char *)big);
}
