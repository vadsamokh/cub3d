/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:36:09 by vbeech            #+#    #+#             */
/*   Updated: 2020/11/11 20:36:11 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new;
	t_list	*elem;

	new = NULL;
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			elem = ft_lstnew(f(lst->content));
			if (elem != NULL)
				ft_lstadd_back(&new, elem);
			else
			{
				ft_lstclear(&new, del);
				break ;
			}
			lst = lst->next;
		}
		elem = ft_lstnew(f(lst->content));
		if (elem != NULL)
			ft_lstadd_back(&new, elem);
		else
			ft_lstclear(&new, del);
	}
	return (new);
}
