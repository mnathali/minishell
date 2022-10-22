/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:00:08 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/09 20:00:08 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *element)
{
	t_list	*last;

	if (!(*lst))
	{
		*lst = element;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = element;
}
