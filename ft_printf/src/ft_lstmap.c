/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:27:13 by zyasuo            #+#    #+#             */
/*   Updated: 2022/04/21 23:27:11 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"
#include<stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*res;

	if (!lst || !f)
		return ((void *)0);
	res = ft_lstnew((*f)(lst->content));
	if (!res)
	{
		ft_lstclear(&lst, del);
		return ((void *)0);
	}
	lst = lst->next;
	while (lst)
	{
		elem = ft_lstnew((*f)(lst->content));
		if (!elem)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&res, del);
			break ;
		}
		ft_lstadd_back(&res, elem);
		lst = lst->next;
	}
	return (res);
}
