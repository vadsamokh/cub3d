/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 10:41:15 by vbeech            #+#    #+#             */
/*   Updated: 2021/04/28 10:41:17 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

int	define_side(t_rays *ray)
{
	if (ray->side == 0 && ray->rayDirX < 0)
		return (0);
	if (ray->side == 0 && ray->rayDirX > 0)
		return (1);
	if (ray->side == 1 && ray->rayDirY < 0)
		return (2);
	if (ray->side == 1 && ray->rayDirY > 0)
		return (3);
	return (0);
}

int	x_tex_coordinate(t_params *params, t_rays *ray, t_data *tex)
{
	double	wallX;
	int		texX;

	if (ray->side == 0)
		wallX = params->pos_y + ray->perpWallDist * ray->rayDirY;
	else
		wallX = params->pos_x + ray->perpWallDist * ray->rayDirX;
	wallX -= floor(wallX);
	texX = (int)(wallX * tex->img_width);
	if ((ray->side == 0 && ray->rayDirX > 0) || (ray->side == 1
			&& ray->rayDirX < 0))
		texX = tex->img_width - texX - 1;
	return (texX);
}

int	y_tex_coordinate(t_params *params, double height, int y, t_data *tex)
{
	double	step;
	double	texPos;
	int		texY;
	double	top_point;

	top_point = (params->ry / 2) - (height / 2);
	if (top_point < 0)
		top_point = 0;
	top_point = floor(top_point);
	step = tex->img_height / height;
	texPos = (top_point - params->ry / 2 + height / 2) * step
		+ step * (y - (int)top_point);
	texY = (int)texPos;
	if (texY > tex->img_height - 1)
		texY = tex->img_height - 1;
	if (texY < 0)
		texY = 0;
	return (texY);
}
