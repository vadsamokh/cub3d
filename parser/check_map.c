/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:31:23 by vbeech            #+#    #+#             */
/*   Updated: 2021/04/26 13:52:16 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

int	check_map(t_params *params)
{
	int	i;

	params->map_x = find_length(params->map_y, params->map);
	i = modify_map(params);
	if (i == -1)
		return (-1);
	params->sprite_ct = check1(params->map_x, params->map_y, params->map);
	if (params->sprite_ct == -2)
		return (-2);
	params->spr = (t_sprites *)malloc(params->sprite_ct
			* sizeof(t_sprites));
	if (params->spr == NULL)
		return (-1);
	if (check2(params->map_x, params->map_y, params->map) == -2)
		return (-2);
	if (check3(params) == -2)
		return (-2);
	return (0);
}

int	find_length(int y, char **map)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (i < y)
	{
		if (ft_strlen(map[i]) > x)
			x = ft_strlen(map[i]);
		i++;
	}
	return (x);
}

int	modify_map(t_params *params)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < params->map_y)
	{
		j = ft_strlen((params->map)[i]);
		while (j < params->map_x)
		{
			tmp = ft_strjoin((params->map)[i], " ");
			if (tmp == NULL)
				return (-1);
			free((params->map)[i]);
			(params->map)[i] = tmp;
			j++;
		}
		i++;
	}
	return (0);
}

int	check1(int x, int y, char **map)
{
	int	i;
	int	j;
	int	sprite_ct;

	i = 0;
	j = -1;
	sprite_ct = 0;
	while (i < y)
	{
		while (++j < x)
		{
			if (map[i][j] != ' ' && map[i][j] != '0' && map[i][j] != '1' &&
			map[i][j] != '2' && map[i][j] != 'N' && map[i][j] != 'S' &&
			map[i][j] != 'W' && map[i][j] != 'E')
				return (-2);
			if (map[i][j] == '2')
				sprite_ct++;
		}
		j = -1;
		i++;
	}
	return (sprite_ct);
}

int	check2(int x, int y, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < x)
		{
			if (i == 0 || j == 0 || i == (y - 1) || j == (x - 1))
			{
				if (map[i][j] != ' ' && map[i][j] != '1')
					return (-2);
			}
			else if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
			|| map[i][j] == 'E' || map[i][j] == '0' || map[i][j] == '2')
			&& (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' ||
			map[i][j - 1] == ' ' || map[i][j + 1] == ' '))
				return (-2);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
