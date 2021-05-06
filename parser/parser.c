/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:57:06 by vbeech            #+#    #+#             */
/*   Updated: 2021/03/05 12:57:09 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

int	write_param(char **spl, t_params *params)
{
	int	a;

	if (ft_strcmp(spl[0], "R") == 0)
		a = resolution_p(spl, params);
	else if (ft_strcmp(spl[0], "F") == 0)
		a = floor_p(spl, params);
	else if (ft_strcmp(spl[0], "C") == 0)
		a = ceiling_p(spl, params);
	else if (ft_strcmp(spl[0], "NO") == 0)
		a = north_p(spl, params);
	else if (ft_strcmp(spl[0], "SO") == 0)
		a = south_p(spl, params);
	else if (ft_strcmp(spl[0], "WE") == 0)
		a = west_p(spl, params);
	else if (ft_strcmp(spl[0], "EA") == 0)
		a = east_p(spl, params);
	else
		a = sprite_p(spl, params);
	return (a);
}

void	splfree(char **spl)
{
	int	i;

	i = 0;
	while (spl[i] != NULL)
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}

int	params_work(char *line, t_params *params)
{
	char	**spl;
	int		a;

	spl = ft_split(line, ' ');
	if (spl == NULL)
		return (-1);
	if (spl[0] == NULL)
	{
		splfree(spl);
		return (0);
	}
	if (ft_strcmp(spl[0], "R") != 0 && ft_strcmp(spl[0], "NO") != 0
		&& ft_strcmp(spl[0], "SO") != 0 && ft_strcmp(spl[0], "WE") != 0
		&& ft_strcmp(spl[0], "EA") != 0 && ft_strcmp(spl[0], "S") != 0
		&& ft_strcmp(spl[0], "F") != 0 && ft_strcmp(spl[0], "C") != 0)
	{
		splfree(spl);
		return (1);
	}
	else
	{
		a = write_param(spl, params);
		splfree(spl);
		return (a);
	}
}

int	check_params(t_params *params)
{
	if (params->rx < 0 || params->ry < 0 || params->fr < 0 || params->fg < 0
		|| params->fb < 0 || params->cr < 0 || params->cg < 0 || params->cb < 0
		|| params->no == NULL || params->so == NULL || params->we == NULL
		|| params->ea == NULL || params->spr_addr == NULL)
		return (-2);
	return (0);
}

int	parser(t_params *params)
{
	int		fd;
	char	*line;
	int		a;
	int		b;

	line = NULL;
	fd = open(params->filename, O_RDONLY);
	if (fd < 0 || check_filename(params) < 0)
		return (-3);
	b = get_next_line(fd, &line);
	while (b != 0)
	{
		a = params_work(line, params);
		if (a == 1)
			break ;
		free(line);
		if (a < 0)
			return (a);
		b = get_next_line(fd, &line);
	}
	if (b == 0 && a != 1)
		return (-2);
	return (parser_checks(params, fd, line));
}
