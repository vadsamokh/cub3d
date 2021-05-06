/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:41:28 by vbeech            #+#    #+#             */
/*   Updated: 2020/11/02 16:41:38 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	check_overflow(int sign, long sum, char ch)
{
	if (sum != 0)
	{
		if ((((sum * 10 + (sign * (ch - 48))) / sum) < 0) && (sign == 1))
			return (-1);
		if ((((sum * 10 + (sign * (ch - 48))) / sum) < 0) && (sign == -1))
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	sum;

	sign = 1;
	sum = 0;
	while ((*str == '\t') || (*str == '\n') || (*str == '\v') || (*str == '\f')
		|| (*str == '\r') || (*str == ' '))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		if (check_overflow(sign, sum, *str) < 1)
			return (check_overflow(sign, sum, *str));
		sum = sum * 10 + (sign * (*str - 48));
		str++;
	}
	return ((int)sum);
}
