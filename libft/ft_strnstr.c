/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:37:19 by vbeech            #+#    #+#             */
/*   Updated: 2020/10/30 14:38:04 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	unsigned long	count;
	unsigned long	lcount;

	count = 0;
	lcount = 0;
	while ((count < len) || (n[lcount] == '\0'))
	{
		if ((*h == n[lcount]) && (n[lcount] != '\0'))
			lcount++;
		else if ((*h != n[lcount]) || (n[lcount] == '\0'))
		{
			if ((*h == '\0') && (n[lcount] != '\0'))
				break ;
			h = h - lcount;
			if (n[lcount] == '\0')
				return ((char *)h);
			count = count - lcount;
			lcount = 0;
		}
		h++;
		count++;
	}
	return (0);
}
