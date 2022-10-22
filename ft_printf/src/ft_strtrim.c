/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 23:21:55 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/08 23:21:55 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"
#include<stdlib.h>

static int	findchr(char *set, char c)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		starttrim;
	int		endtrim ;
	int		strlen;
	char	*result;
	char	*presult;

	if (!s1 || !set)
		return ((void *)0);
	starttrim = 0;
	strlen = ft_strlen((char *)s1);
	while (findchr((char *)set, s1[starttrim]))
		starttrim++;
	endtrim = strlen - 1;
	while (findchr((char *)set, s1[endtrim]) && endtrim > starttrim)
		endtrim--;
	result = (char *)malloc (endtrim - starttrim + 2);
	if (!result)
		return ((void *)0);
	presult = result;
	while (starttrim < endtrim + 1)
		*presult++ = s1[starttrim++];
	*presult = '\0';
	return (result);
}
