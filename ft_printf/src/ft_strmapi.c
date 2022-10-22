/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:44:11 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/09 15:44:11 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"
#include<stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	unsigned int		len;
	char				*string;
	char				*pstring;

	if (!s || !(*f))
		return ((void *)0);
	len = ft_strlen(s);
	string = (char *) malloc(len + 1);
	if (!string)
		return ((void *)0);
	i = 0;
	pstring = string;
	while (s[i])
	{
		pstring[i] = (*f)(i, s[i]);
		i++;
	}
	pstring[i] = '\0';
	return (string);
}
