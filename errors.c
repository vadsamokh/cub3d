/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:34:41 by vbeech            #+#    #+#             */
/*   Updated: 2021/03/06 13:34:43 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

int	inv_args_error(void)
{
	ft_putstr("Error: invalid arguments!\n");
	return (0);
}

int	file_not_found_error(void)
{
	ft_putstr("Error: invalid filename or error with reading file!\n");
	return (0);
}

int	inv_config_file(void)
{
	ft_putstr("Error: invalid configs and/or map!\n");
	return (0);
}

int	malloc_error(void)
{
	ft_putstr("Malloc error\n");
	return (0);
}
