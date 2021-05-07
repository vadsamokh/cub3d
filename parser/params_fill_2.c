/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_fill_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:46:33 by vbeech            #+#    #+#             */
/*   Updated: 2021/03/07 12:46:35 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	north_p(char **spl, t_params *params)
{
	if (params->no != NULL)
		return (-2);
	if (spl[2] != NULL)
		return (-2);
	params->no = ft_strdup(spl[1]);
	if (params->no == NULL)
		return (-1);
	return (0);
}

int	south_p(char **spl, t_params *params)
{
	if (params->so != NULL)
		return (-2);
	if (spl[2] != NULL)
		return (-2);
	params->so = ft_strdup(spl[1]);
	if (params->so == NULL)
		return (-1);
	return (0);
}

int	west_p(char **spl, t_params *params)
{
	if (params->we != NULL)
		return (-2);
	if (spl[2] != NULL)
		return (-2);
	params->we = ft_strdup(spl[1]);
	if (params->we == NULL)
		return (-1);
	return (0);
}

int	east_p(char **spl, t_params *params)
{
	if (params->ea != NULL)
		return (-2);
	if (spl[2] != NULL)
		return (-2);
	params->ea = ft_strdup(spl[1]);
	if (params->ea == NULL)
		return (-1);
	return (0);
}

int	sprite_p(char **spl, t_params *params)
{
	if (params->spr_addr != NULL)
		return (-2);
	if (spl[2] != NULL)
		return (-2);
	params->spr_addr = ft_strdup(spl[1]);
	if (params->spr_addr == NULL)
		return (-1);
	return (0);
}
