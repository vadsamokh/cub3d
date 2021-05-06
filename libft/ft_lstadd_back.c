/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:41:35 by vbeech            #+#    #+#             */
/*   Updated: 2020/11/11 19:41:37 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*copy;

	if (lst != NULL)
	{
		copy = *lst;
		if (copy == NULL)
			*lst = new;
		else
		{
			while (copy->next != NULL)
				copy = copy->next;
			copy->next = new;
		}
	}
}
