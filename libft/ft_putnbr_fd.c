/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:46:52 by vbeech            #+#    #+#             */
/*   Updated: 2020/11/06 12:46:54 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	mul;
	int		a;

	mul = 1;
	while ((n / (mul * 10)) != 0)
		mul = mul * 10;
	if (n < 0)
	{
		write(fd, "-", 1);
		mul = -mul;
	}
	while (mul != 0)
	{
		a = ((n / mul) % 10) + 48;
		write(fd, &a, 1);
		mul = mul / 10;
	}
}