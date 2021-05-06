/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_fill_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:00:30 by vbeech            #+#    #+#             */
/*   Updated: 2021/03/07 12:00:32 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

int	check_sym(char *str)
{
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (-2);
		str++;
	}
	return (0);
}

int	resolution_p(char **spl, t_params *params)
{
	if (params->rx != -1 || params->ry != -1)
		return (-2);
	if (spl[1] == NULL || spl[2] == NULL || spl[3] != NULL || check_sym(spl[1])
		!= 0 || check_sym(spl[2]) != 0)
		return (-2);
	params->rx = ft_atoi(spl[1]);
	params->ry = ft_atoi(spl[2]);
	if (params->rx <= 0 || params->ry <= 0)
		return (-2);
	params->ZBuffer = (int *)malloc(params->rx * sizeof(int));
	if (params->ZBuffer == NULL)
		return (-1);
	return (0);
}

int	floor_p(char **spl, t_params *params)
{
	char	**spl1;

	if (params->fr != -1 || params->fg != -1 || params->fb != -1)
		return (-2);
	if (spl[2] != NULL)
		return (-2);
	spl1 = ft_split(spl[1], ',');
	if (spl1 == NULL)
		return (-1);
	if (spl1[3] != NULL || check_sym(spl1[0]) != 0 || check_sym(spl1[1]) != 0
		|| check_sym(spl1[2]) != 0)
		return (-2);
	params->fr = ft_atoi(spl1[0]);
	params->fg = ft_atoi(spl1[1]);
	params->fb = ft_atoi(spl1[2]);
	if (params->fr > 255 || params->fg > 255 || params->fb > 255
		|| params->fr < 0 || params->fg < 0 || params->fb < 0)
		return (-2);
	splfree(spl1);
	params->floor = def_color(params->fr, params->fg, params->fb);
	return (0);
}

int	ceiling_p(char **spl, t_params *params)
{
	char	**spl1;

	if (params->cr != -1 || params->cg != -1 || params->cb != -1)
		return (-2);
	if (spl[2] != NULL)
		return (-2);
	spl1 = ft_split(spl[1], ',');
	if (spl1 == NULL)
		return (-1);
	if (spl1[3] != NULL || check_sym(spl1[0]) != 0 || check_sym(spl1[1]) != 0
		|| check_sym(spl1[2]) != 0)
		return (-2);
	params->cr = ft_atoi(spl1[0]);
	params->cg = ft_atoi(spl1[1]);
	params->cb = ft_atoi(spl1[2]);
	if (params->cr > 255 || params->cg > 255 || params->cb > 255
		|| params->cr < 0 || params->cg < 0 || params->cb < 0)
		return (-2);
	splfree(spl1);
	params->ceiling = def_color(params->cr, params->cg, params->cb);
	return (0);
}

int	def_color(int a, int b, int c)
{
	int	num[6];
	int	x;
	int	i;

	num[0] = a / 16;
	num[1] = a % 16;
	num[2] = b / 16;
	num[3] = b % 16;
	num[4] = c / 16;
	num[5] = c % 16;
	x = 0;
	i = 0;
	while (i < 6)
	{
		x += (int)pow(16, 6 - 1 - i) * num[i];
		i++;
	}
	return (x);
}
