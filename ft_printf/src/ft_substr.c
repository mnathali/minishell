/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:38:45 by zyasuo            #+#    #+#             */
/*   Updated: 2022/04/19 18:59:16 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"
#include<stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;
	size_t	strlen;
	char	*psub;

	if (!s)
		return ((void *)0);
	strlen = ft_strlen(s);
	if (start > strlen)
		len = 0;
	if (len > strlen)
		len = strlen;
	substr = (char *) malloc(len + 1);
	if (!substr)
		return ((void *)0);
	psub = substr;
	s += start;
	i = 0;
	while (len--)
		*psub++ = *s++;
	*psub = '\0';
	return (substr);
}
