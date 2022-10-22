/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:34:37 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/06 20:34:37 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char			*last;
	int				i;
	int				strlen;
	unsigned char	t;

	strlen = ft_strlen(str) + 1;
	t = c;
	last = (void *)0;
	i = 0;
	while (i < strlen)
	{
		if (str[i] == t)
			last = (char *)(str + i);
		i++;
	}
	return (last);
}
