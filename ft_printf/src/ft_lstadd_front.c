/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:24:45 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/09 19:24:45 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *element)
{
	if (!lst)
		return ;
	element->next = *lst;
	*lst = element;
}
