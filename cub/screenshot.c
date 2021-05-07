/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:55:20 by vbeech            #+#    #+#             */
/*   Updated: 2021/05/06 12:55:22 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp_header(t_params *params)
{
	params->screenshot.size = 54 + params->rx
		* params->ry * params->img.bits_per_pixel / 8;
	params->screenshot.hdr[0] = 'B';
	params->screenshot.hdr[1] = 'M';
	params->screenshot.hdr[2] = (unsigned char)params->screenshot.size;
	params->screenshot.hdr[3] = (unsigned char)(params->screenshot.size >> 8);
	params->screenshot.hdr[4] = (unsigned char)(params->screenshot.size >> 16);
	params->screenshot.hdr[5] = (unsigned char)(params->screenshot.size >> 24);
	params->screenshot.hdr[10] = (unsigned char)(54);
	params->screenshot.hdr[14] = (unsigned char)(40);
	params->screenshot.hdr[18] = (unsigned char)(params->rx);
	params->screenshot.hdr[19] = (unsigned char)(params->rx >> 8);
	params->screenshot.hdr[20] = (unsigned char)(params->rx >> 16);
	params->screenshot.hdr[21] = (unsigned char)(params->rx >> 24);
	params->screenshot.hdr[22] = (unsigned char)(-params->ry);
	params->screenshot.hdr[23] = (unsigned char)(-params->ry >> 8);
	params->screenshot.hdr[24] = (unsigned char)(-params->ry >> 16);
	params->screenshot.hdr[25] = (unsigned char)(-params->ry >> 24);
	params->screenshot.hdr[26] = (unsigned char)(1);
	params->screenshot.hdr[28] = (unsigned char)(params->img.bits_per_pixel);
}

void	make_screenshot(t_params *params)
{
	int	fd;

	ft_bzero(params->screenshot.hdr, 54);
	bmp_header(params);
	params->screenshot.count = 0;
	params->screenshot.length = params->img.bits_per_pixel / 8 * params->rx;
	fd = open("cub3D.bmp", O_RDWR | O_CREAT, 0777);
	if (fd < 0)
		return ;
	write(fd, params->screenshot.hdr, 54);
	while (params->screenshot.count < (unsigned int)params->ry)
	{
		write(fd, params->img.addr
			+ params->screenshot.count * params->img.line_length,
			params->screenshot.length);
		params->screenshot.count++;
	}
	close(fd);
	exit(0);
}
