/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:40:53 by vbeech            #+#    #+#             */
/*   Updated: 2020/10/28 18:49:53 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	unsigned long		count;

	count = 0;
	d = dst;
	s = src;
	if (dst == src)
		return (dst);
	while (count < n)
	{
		*d = *s;
		d++;
		s++;
		count++;
	}
	return (dst);
}
