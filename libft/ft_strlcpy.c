/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:36:46 by vbeech            #+#    #+#             */
/*   Updated: 2020/10/30 12:36:48 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	count;
	size_t			len;

	if (dst == NULL)
		return (0);
	len = ft_strlen(src);
	count = 1;
	while ((*src != '\0') && (count < dstsize))
	{
		*dst = *src;
		dst++;
		src++;
		count++;
	}
	if (dstsize != 0)
		*dst = '\0';
	return (len);
}
