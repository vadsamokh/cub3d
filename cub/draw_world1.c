/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:10:15 by vbeech            #+#    #+#             */
/*   Updated: 2021/04/13 15:10:21 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_tex_color(t_data data, int x, int y)
{
	char	*dst;

	dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	draw_world(t_data *img, t_params *params, t_rays *ray, double x)
{
	double			height;
	double			top_point;
	double			y;
	unsigned int	color;
	t_data			tex;

	ray->perpWallDist = ray->perpWallDist * cos(params->dir - params->curr_ray);
	params->ZBuffer[(int)x] = ray->perpWallDist;
	height = (SCL / ray->perpWallDist) * ((params->rx / 2) / tan(params->fov));
	top_point = (params->ry / 2) - (height / 2);
	if (top_point < 0)
		top_point = 0;
	y = floor(top_point);
	tex = params->tex[define_side(ray)];
	while ((y < (top_point + height)) && (y < params->ry))
	{
		color = get_tex_color(tex, x_tex_coordinate(params, ray, &tex),
				y_tex_coordinate(params, height, y, &tex));
		my_mlx_pixel_put(img, x, y, color);
		y++;
	}
}

int	load_textures(t_params *params)
{
	params->tex[0].img = mlx_xpm_file_to_image(params->mlx, params->no,
			&(params->tex[0].img_width), &(params->tex[0].img_height));
	params->tex[1].img = mlx_xpm_file_to_image(params->mlx, params->so,
			&(params->tex[1].img_width), &(params->tex[1].img_height));
	params->tex[2].img = mlx_xpm_file_to_image(params->mlx, params->we,
			&(params->tex[2].img_width), &(params->tex[2].img_height));
	params->tex[3].img = mlx_xpm_file_to_image(params->mlx, params->ea,
			&(params->tex[3].img_width), &(params->tex[3].img_height));
	error_textures(params);
	params->tex[0].addr = mlx_get_data_addr(params->tex[0].img,
			&(params->tex[0].bits_per_pixel), &(params->tex[0].line_length),
			&(params->tex[0].endian));
	params->tex[1].addr = mlx_get_data_addr(params->tex[1].img,
			&(params->tex[1].bits_per_pixel), &(params->tex[1].line_length),
			&(params->tex[1].endian));
	params->tex[2].addr = mlx_get_data_addr(params->tex[2].img,
			&(params->tex[2].bits_per_pixel), &(params->tex[2].line_length),
			&(params->tex[2].endian));
	params->tex[3].addr = mlx_get_data_addr(params->tex[3].img,
			&(params->tex[3].bits_per_pixel), &(params->tex[3].line_length),
			&(params->tex[3].endian));
	return (0);
}

int	error_textures(t_params *params)
{
	if (params->tex[0].img == NULL || params->tex[1].img == NULL
		|| params->tex[2].img == NULL || params->tex[3].img == NULL)
	{
		free(params->mlx);
		file_not_found_error();
		exit(0);
	}
	return (0);
}

void	floor_ceiling(t_data *img, t_params *params)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (params->ry / 2))
	{
		while (j < params->rx)
		{
			my_mlx_pixel_put(img, j, i, params->ceiling);
			j++;
		}
		j = 0;
		i++;
	}
	while (i < params->ry)
	{
		while (j < params->rx)
		{
			my_mlx_pixel_put(img, j, i, params->floor);
			j++;
		}
		j = 0;
		i++;
	}
}
