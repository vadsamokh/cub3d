/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:16:37 by vbeech            #+#    #+#             */
/*   Updated: 2020/11/04 18:16:39 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ctdigits(int n)
{
	size_t	count;
	long	mul;

	count = 1;
	mul = 10;
	if (n < 0)
		count++;
	while ((n / mul) != 0)
	{
		count++;
		mul = mul * 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	mul;

	str = (char *)malloc(sizeof(char) * (ctdigits(n) + 1));
	if (str == NULL)
		return (NULL);
	mul = 1;
	if (n < 0)
	{
		*str = '-';
		str++;
		mul = -1;
	}
	while ((n / (mul * 10)) != 0)
		mul = mul * 10;
	while (mul != 0)
	{
		*str = (n / mul) % 10 + 48;
		str++;
		mul = mul / 10;
	}
	*str = '\0';
	return (str - ctdigits(n));
}
