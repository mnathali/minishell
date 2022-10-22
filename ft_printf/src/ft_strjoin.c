/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:45:55 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/07 16:45:55 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"
#include<stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		s1len;
	int		s2len;
	char	*pdest;

	if (!s1 || !s2)
		return ((void *)0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	dest = malloc(s1len + s2len + 1);
	if (!dest)
		return ((void *)0);
	pdest = dest;
	while (*s1)
		*pdest++ = *s1++;
	while (*s2)
		*pdest++ = *s2++;
	*pdest = '\0';
	return (dest);
}
