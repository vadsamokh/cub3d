/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:30:42 by vbeech            #+#    #+#             */
/*   Updated: 2020/10/29 20:54:10 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*arr1;
	unsigned const char	*arr2;
	unsigned long		count;

	arr1 = s1;
	arr2 = s2;
	count = 0;
	while (count < n)
	{
		if (*arr1 != *arr2)
			return (*arr1 - *arr2);
		arr1++;
		arr2++;
		count++;
	}
	return (0);
}
