/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_getbyid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:52:40 by zyasuo            #+#    #+#             */
/*   Updated: 2022/04/28 17:57:21 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

t_list	*ft_lst_getbyid(t_list *lst, int id)
{
	int		i;
	t_list	*current;

	if (!lst)
		return (NULL);
	current = lst;
	i = 0;
	while (current)
	{
		if (i == id)
			return (current);
		i++;
		current = current->next;
	}
	return (NULL);
}
