/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:17:31 by vbeech            #+#    #+#             */
/*   Updated: 2021/05/05 13:17:33 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

int	load_sprite_tex(t_params *params)
{
	params->tex[4].img = mlx_xpm_file_to_image(params->mlx, params->spr_addr,
			&(params->tex[4].img_width), &(params->tex[4].img_height));
	params->tex[4].addr = mlx_get_data_addr(params->tex[4].img,
			&(params->tex[4].bits_per_pixel), &(params->tex[4].line_length),
			&(params->tex[4].endian));
	if (params->tex[4].img == NULL)
	{
		mlx_destroy_window(params->mlx, params->win);
		free(params->mlx);
		return (-2);
	}
	return (0);
}

void	init_sprites(t_params *params)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = -1;
	k = 0;
	while (i < params->map_y)
	{
		while (++j < params->map_x)
		{
			if ((params->map)[i][j] == '2')
			{
				params->spr[k].y = i * SCL;
				params->spr[k].x = j * SCL;
				params->spr[k].dist = pow(params->pos_x - params->spr[k].x, 2)
					+ pow(params->pos_y - params->spr[k].y, 2);
				k++;
			}
		}
		j = -1;
		i++;
	}
}

void	sort_sprites(t_params *params)
{
	t_sprites	tmp;
	int			i;

	i = 0;
	while (i < params->sprite_ct - 1)
	{
		if (params->spr[i].dist < params->spr[i + 1].dist)
		{
			tmp = params->spr[i + 1];
			params->spr[i + 1] = params->spr[i];
			params->spr[i] = tmp;
			i = -1;
		}
		i++;
	}
}
