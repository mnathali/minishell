/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:50:40 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/07 08:50:40 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

#include<stdlib.h>

char	*ft_strdup(const char *str)
{
	int		strlen;
	char	*dest;
	char	*pdest;

	strlen = ft_strlen(str);
	dest = malloc(strlen + 1);
	if (!dest)
		return ((void *)0);
	pdest = dest;
	while (*str)
		*pdest++ = *str++;
	*pdest = '\0';
	return (dest);
}
