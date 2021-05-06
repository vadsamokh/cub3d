/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:13:59 by vbeech            #+#    #+#             */
/*   Updated: 2020/10/29 20:10:12 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned const char	*s;
	unsigned long		count;

	s = src;
	count = 0;
	while (count < n)
	{
		if (*s == (unsigned char)c)
			return ((void *)s);
		s++;
		count++;
	}
	return (0);
}
