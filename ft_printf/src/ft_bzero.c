/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:31:03 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/06 20:31:03 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*pointer;

	pointer = s;
	while (n--)
		*pointer++ = '\0';
	return (s);
}
