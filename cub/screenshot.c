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

#include "./../headers/cub3d.h"

void	screenshot_recording(t_params *params)
{
	params->screenshot.count = 0;
	params->screenshot.length = params->img.bits_per_pixel
		/ 8 * params->rx;
	params->screenshot.fd = open("cub3D.bmp", O_RDWR | O_CREAT, 0755);
	if (params->screenshot.fd < 0)
		return ;
	write(params->screenshot.fd, params->screenshot.bfh, 14);
	write(params->screenshot.fd, params->screenshot.bih, 40);
	while (params->screenshot.count < params->ry)
	{
		write(params->screenshot.fd, params->img.addr
			+ params->screenshot.count * params->img.line_length,
			params->screenshot.length);
		params->screenshot.count++;
	}
	close(params->screenshot.fd);
}

void	bmp_meta_info(t_params *params)
{
	params->screenshot.size_of_file = 54 + params->rx
		* params->ry * params->img.bits_per_pixel / 8;
	params->screenshot.bfh[0] = 'B';
	params->screenshot.bfh[1] = 'M';
	params->screenshot.bfh[2] = (unsigned char)params->screenshot.size_of_file;
	params->screenshot.bfh[3] = (unsigned char)
		(params->screenshot.size_of_file >> 8);
	params->screenshot.bfh[4] = (unsigned char)
		(params->screenshot.size_of_file >> 16);
	params->screenshot.bfh[5] = (unsigned char)
		(params->screenshot.size_of_file >> 24);
	params->screenshot.bfh[10] = (unsigned char)(54);
	params->screenshot.bih[0] = (unsigned char)(40);
	params->screenshot.bih[4] = (unsigned char)(params->rx);
	params->screenshot.bih[5] = (unsigned char)(params->rx >> 8);
	params->screenshot.bih[6] = (unsigned char)(params->rx >> 16);
	params->screenshot.bih[7] = (unsigned char)(params->rx >> 24);
	params->screenshot.bih[8] = (unsigned char)(-params->ry);
	params->screenshot.bih[9] = (unsigned char)(-params->ry >> 8);
	params->screenshot.bih[10] = (unsigned char)(-params->ry >> 16);
	params->screenshot.bih[11] = (unsigned char)(-params->ry >> 24);
	params->screenshot.bih[12] = (unsigned char)(1);
	params->screenshot.bih[14] = (unsigned char)(params->img.bits_per_pixel);
}

void	make_screenshot(t_params *params)
{
	ft_bzero(params->screenshot.bih, 40);
	ft_bzero(params->screenshot.bfh, 14);
	bmp_meta_info(params);
	screenshot_recording(params);
	exit(0);
}
