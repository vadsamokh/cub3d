/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:41:29 by vbeech            #+#    #+#             */
/*   Updated: 2020/10/29 19:13:22 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;
	unsigned long		count;

	d = dst;
	s = src;
	if (dst <= src)
		ft_memcpy(d, s, len);
	else if (len != 0)
	{
		count = len - 1;
		d = d + count;
		s = s + count;
		while (count > 0)
		{
			*d = *s;
			d--;
			s--;
			count--;
		}
		*d = *s;
	}
	return (dst);
}
