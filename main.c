/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:03:35 by vbeech            #+#    #+#             */
/*   Updated: 2021/03/06 13:03:37 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

t_params	*params_init(void)
{
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
	if (params == NULL)
		return (NULL);
	params->filename = NULL;
	params->save = -1;
	params->rx = -1;
	params->ry = -1;
	params->no = NULL;
	params->so = NULL;
	params->we = NULL;
	params->ea = NULL;
	params->spr_addr = NULL;
	params->fr = -1;
	params->fg = -1;
	params->fb = -1;
	params->cr = -1;
	params->cg = -1;
	params->cb = -1;
	params->flagW = 0;
	params->flagA = 0;
	params->flagS = 0;
	params->flagD = 0;
	return (params);
}

int	win_close(t_params *params)
{
	mlx_destroy_window(params->mlx, params->win);
	free(params->mlx);
	exit(0);
}

int	check_filename(t_params *params)
{
	params->ext = ft_substr(params->filename, ft_strlen(params->filename) - 4,
			4);
	if (ft_strcmp(params->ext, ".cub") != 0)
		return (-3);
	return (0);
}

int	main(int ac, char **av)
{
	t_params	*params;
	int			a;

	if (ac < 2 || ac > 3 || (ac == 3 && ft_strcmp(av[2], "--save") != 0))
		return (inv_args_error());
	params = params_init();
	if (params == NULL)
		return (malloc_error());
	if (ac == 3)
		params->save = 1;
	params->filename = ft_strdup(av[1]);
	if (params->filename == NULL)
		return (malloc_error());
	a = parser(params);
	if (a == -1)
		return (malloc_error());
	if (a == -2)
		return (inv_config_file());
	if (a == -3)
		return (file_not_found_error());
	a = window(params);
	if (a == -1)
		return (malloc_error());
	if (a == -2)
		return (file_not_found_error());
}
