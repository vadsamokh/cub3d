/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:06:29 by vbeech            #+#    #+#             */
/*   Updated: 2021/03/13 15:06:31 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

int	move(t_params *params)
{
	if (params->flagW == 1 && check_pos_x(params) == 0)
		params->pos_x += cos(params->dir);
	if (params->flagW == 1 && check_pos_y(params) == 0)
		params->pos_y += sin(params->dir);
	if (params->flagS == 1 && check_pos_x(params) == 0)
		params->pos_x -= cos(params->dir);
	if (params->flagS == 1 && check_pos_y(params) == 0)
		params->pos_y -= sin(params->dir);
	if (params->flagA == 1)
		params->dir -= TURN;
	if (params->flagD == 1)
		params->dir += TURN;
	return (0);
}

int	check_pos_x(t_params *params)
{
	if (params->flagW == 1 && ((params->map)[(int)floor(params->pos_y / SCL)]
		[(int)floor((params->pos_x + 2 * cos(params->dir)) / SCL)] == '1'))
		return (-1);
	if (params->flagS == 1 && ((params->map)[(int)floor(params->pos_y / SCL)]
		[(int)floor((params->pos_x - 2 * cos(params->dir)) / SCL)] == '1'))
		return (-1);
	return (0);
}

int	check_pos_y(t_params *params)
{
	if (params->flagW == 1 && (params->map)[(int)floor((params->pos_y + 2
				* sin(params->dir)) / SCL)]
				[(int)floor(params->pos_x / SCL)] == '1')
		return (-1);
	if (params->flagS == 1 && (params->map)[(int)floor((params->pos_y - 2
				* sin(params->dir)) / SCL)]
				[(int)floor(params->pos_x / SCL)] == '1')
		return (-1);
	return (0);
}

int	keypress(int keycode, t_params *params)
{
	if (keycode == ESC)
		win_close(params);
	if (keycode == W && params->flagS == 0)
		params->flagW = 1;
	if (keycode == S && params->flagW == 0)
		params->flagS = 1;
	if (keycode == A && params->flagD == 0)
		params->flagA = 1;
	if (keycode == D && params->flagA == 0)
		params->flagD = 1;
	return (0);
}

int	keyrelease(int keycode, t_params *params)
{
	if (keycode == W)
		params->flagW = 0;
	if (keycode == S)
		params->flagS = 0;
	if (keycode == A)
		params->flagA = 0;
	if (keycode == D)
		params->flagD = 0;
	return (0);
}
