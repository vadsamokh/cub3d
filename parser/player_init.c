/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:30:09 by vbeech            #+#    #+#             */
/*   Updated: 2021/03/17 14:30:11 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

int	check3(t_params *params)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	j = -1;
	player = 0;
	while (i < params->map_y)
	{
		while (++j < params->map_x)
		{
			if ((params->map)[i][j] == 'N' || (params->map)[i][j] == 'S' ||
			(params->map)[i][j] == 'W' || (params->map)[i][j] == 'E')
			{
				player_init(j * SCL, i * SCL, (params->map)[i][j], params);
				player++;
			}
		}
		j = -1;
		i++;
	}
	if (player != 1)
		return (-2);
	return (0);
}

void	player_init(int pos_x, int pos_y, char dir, t_params *params)
{
	params->fov = M_PI / 3;
	if (dir == 'N')
	{
		params->pos_x = pos_x + (int)(SCL / 2);
		params->pos_y = pos_y + (int)(SCL / 2);
		params->dir = -M_PI / 2;
	}
	if (dir == 'S')
	{
		params->pos_x = pos_x + (int)(SCL / 2);
		params->pos_y = pos_y + (int)(SCL / 2);
		params->dir = M_PI / 2;
	}
	if (dir == 'E')
	{
		params->pos_x = pos_x + (int)(SCL / 2);
		params->pos_y = pos_y + (int)(SCL / 2);
		params->dir = 0;
	}
	if (dir == 'W')
	{
		params->pos_x = pos_x + (int)(SCL / 2);
		params->pos_y = pos_y + (int)(SCL / 2);
		params->dir = M_PI;
	}
}

int	parser_checks(t_params *params, int fd, char *line)
{
	int	a;

	a = check_params(params);
	if (a < 0)
		return (a);
	a = parse_map(fd, line, params);
	if (a < 0)
		return (a);
	return (0);
}
