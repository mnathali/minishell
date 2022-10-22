/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 00:07:18 by zyasuo            #+#    #+#             */
/*   Updated: 2022/05/08 00:51:08 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	add_arg(t_list **list, char *arg)
{
	int	len;

	if (!arg)
		return (1);
	ft_lstadd_back(list, ft_lstnew(arg));
	len = ft_strlen((char *)ft_lstlast(*list)->content);
	return (len);
}

void	remove_backslash(void *p)
{
	char	*src;
	char	*dst;
	char	garbage;

	garbage = '\\';
	src = (char *)p;
	dst = src;
	while (*src)
	{
		*dst = *src;
		if (*dst != garbage)
			dst++;
		src++;
	}
	*dst = '\0';
}
