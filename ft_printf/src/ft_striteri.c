/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:59:12 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/09 15:59:12 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"
#include<stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	char	*ps;
	int		i;
	char	*cps;

	if (!s)
		return ;
	ps = s;
	i = 0;
	while (*ps)
	{
		cps = ps;
		(*f)(i, cps);
		i++;
		ps++;
	}
}
