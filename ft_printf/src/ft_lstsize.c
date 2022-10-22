/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:50:08 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/09 19:50:08 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*current;

	if (!lst)
		return (0);
	current = lst;
	len = 1;
	while (current->next)
	{
		len++;
		current = current->next;
	}
	return (len);
}
