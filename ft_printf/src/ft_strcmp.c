/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:17:29 by zyasuo            #+#    #+#             */
/*   Updated: 2022/03/09 20:10:38 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *str1, char *str2)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)str1;
	ps2 = (unsigned char *)str2;
	while ((*ps1 && *ps2) && (*ps1 == *ps2))
	{
		ps1++;
		ps2++;
	}
	return (*ps1 - *ps2);
}
