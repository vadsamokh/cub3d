/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:08:16 by vbeech            #+#    #+#             */
/*   Updated: 2020/10/30 13:08:18 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	mini(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	dstlen;
	size_t	srclen;

	count = 1;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	while (*dst != '\0')
	{
		dst++;
		count++;
	}
	while ((*src != '\0') && (count < dstsize))
	{
		*dst = *src;
		dst++;
		src++;
		count++;
	}
	if ((dstsize != 0) && (dstlen <= dstsize))
		*dst = '\0';
	return (mini(dstsize, dstlen) + srclen);
}
