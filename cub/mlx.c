/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:06:40 by vbeech            #+#    #+#             */
/*   Updated: 2021/03/13 14:06:27 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

int	window(t_params *params)
{
	int		x;
	int		y;
	int		a;

	params->mlx = mlx_init();
	if (params->mlx == NULL)
		return (-1);
	mlx_get_screen_size(params->mlx, &x, &y);
	if (x < params->rx)
		params->rx = x;
	if (y < params->ry)
		params->ry = y;
	a = load_textures(params);
	if (a < 0)
		return (a);
	a = load_sprite_tex(params);
	if (a < 0)
		return (a);
	image(params);
	if (params->save == 1)
		make_screenshot(params);
	params->win = mlx_new_window(params->mlx, params->rx, params->ry, "cub3D");
	mlx_put_image_to_window(params->mlx, params->win, params->img.img, 0, 0);
	loops_hooks(params);
	return (0);
}

void	loops_hooks(t_params *params)
{
	mlx_hook(params->win, 3, 1L << 1, keyrelease, params);
	mlx_hook(params->win, 2, 1L << 17, keypress, params);
	mlx_hook(params->win, 17, 0, win_close, params);
	mlx_loop_hook(params->mlx, engine, params);
	mlx_loop(params->mlx);
}

int	engine(t_params *params)
{
	int	flag;

	flag = 0;
	if (params->flagW == 1 || params->flagA == 1 || params->flagS == 1
		|| params->flagD == 1)
	{
		flag = 1;
		move(params);
	}
	if (flag == 1)
	{
		mlx_destroy_image(params->mlx, params->img.img);
		image(params);
		mlx_put_image_to_window(params->mlx, params->win, params->img.img,
			0, 0);
		flag = 0;
	}
	return (0);
}

void	image(t_params *params)
{
	params->img.img = mlx_new_image(params->mlx, params->rx, params->ry);
	params->img.addr = mlx_get_data_addr(params->img.img,
			&params->img.bits_per_pixel, &params->img.line_length,
			&params->img.endian);
	init_sprites(params);
	floor_ceiling(&params->img, params);
	new_ray0(&params->img, params);
	draw_sprites(&params->img, params);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}
