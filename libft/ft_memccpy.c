/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:33:49 by vbeech            #+#    #+#             */
/*   Updated: 2020/10/28 19:04:43 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	unsigned long		count;

	count = 0;
	d = dst;
	s = src;
	while (count < n)
	{
		*d = *s;
		if (*s == (unsigned char)c)
		{
			d++;
			return (d);
		}
		d++;
		s++;
		count++;
	}
	return (0);
}
