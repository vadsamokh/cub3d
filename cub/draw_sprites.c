/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 12:52:41 by vbeech            #+#    #+#             */
/*   Updated: 2021/04/30 12:52:43 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprites(t_data *img, t_params *params)
{
	int		i;
	double	planeX;
	double	planeY;
	double	dirX;
	double	dirY;

	i = 0;
	sort_sprites(params);
	dirX = cos(params->dir);
	dirY = sin(params->dir);
	planeX = -dirY * params->fov / 2;
	planeY = dirX * params->fov / 2;
	while (i < params->sprite_ct)
	{
		params->spr[i].sprX = params->spr[i].x - params->pos_x;
		params->spr[i].sprY = params->spr[i].y - params->pos_y;
		params->invDet = 1 / (planeX * dirY - dirX * planeY);
		params->spr[i].transX = params->invDet
			* (dirY * params->spr[i].sprX - dirX * params->spr[i].sprY);
		params->spr[i].transY = params->invDet
			* (planeX * params->spr[i].sprY - planeY * params->spr[i].sprX);
		draw_sprites2(params, i);
		draw_sprites3(img, params, i);
		i++;
	}
}

void	draw_sprites2(t_params *params, int i)
{
	params->spr[i].sprScreenX = (int)((params->rx / 2)
			* (1 + params->spr[i].transX / params->spr[i].transY));
	params->spr[i].sprH = abs((int)((SCL / params->spr[i].transY)
				* ((params->rx / 2) / tan(params->fov))));
	params->spr[i].drawStartY = -params->spr[i].sprH / 2 + params->ry / 2;
	if (params->spr[i].drawStartY < 0)
		params->spr[i].drawStartY = 0;
	params->spr[i].drawEndY = params->spr[i].sprH / 2 + params->ry / 2;
	if (params->spr[i].drawEndY >= params->ry)
		params->spr[i].drawEndY = params->ry - 1;
	params->spr[i].sprW = abs((int)(params->ry / params->spr[i].transY))
		* SCL / 2;
	params->spr[i].drawStartX = -params->spr[i].sprW / 2
		+ params->spr[i].sprScreenX;
	if (params->spr[i].drawStartX < 0)
		params->spr[i].drawStartX = 0;
	params->spr[i].drawEndX = params->spr[i].sprW / 2
		+ params->spr[i].sprScreenX;
	if (params->spr[i].drawEndX >= params->rx)
		params->spr[i].drawEndX = params->rx - 1;
}

void	draw_sprites3(t_data *img, t_params *params, int i)
{
	int				x;
	int				y;
	unsigned int	color;

	x = params->spr[i].drawStartX;
	y = params->spr[i].drawStartY;
	while (x < params->spr[i].drawEndX)
	{
		if ((params->spr[i].transY > 0) && (x > 0) && (x < params->rx)
			&& (params->spr[i].transY < params->ZBuffer[x]))
		{
			while (y < params->spr[i].drawEndY)
			{
				color = get_tex_color(params->tex[4],
						  sprite_texX(params, x, i), sprite_texY(params, y, i));
				if (color != 0x000000)
					my_mlx_pixel_put(img, x, y, color);
				y++;
			}
		}
		y = params->spr[i].drawStartY;
		x++;
	}
}

int	sprite_texX(t_params *params, int x, int i)
{
	int	texX;

	texX = (int)((256 * (x - (-params->spr[i].sprW / 2
						+ params->spr[i].sprScreenX)) * params->tex[4].img_width
				/ params->spr[i].sprW) / 256);
	return (texX);
}

int	sprite_texY(t_params *params, int y, int i)
{
	int	texY;

	texY = (int)((((y * 256 - params->ry * 128 + params->spr[i].sprH * 128)
					* params->tex[4].img_height) / params->spr[i].sprH) / 256);
	return (texY);
}
