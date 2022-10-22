/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:50:34 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/07 08:50:34 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"
#include<stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == 0 && size == 0)
	{
		p = malloc(0);
		if (!p)
			return ((void *)0);
		else
			return (p);
	}
	p = malloc (nmemb * size);
	if (!p)
		return ((void *)0);
	ft_bzero(p, nmemb * size);
	return (p);
}
