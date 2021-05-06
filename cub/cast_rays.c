/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:18:07 by vbeech            #+#    #+#             */
/*   Updated: 2021/03/26 16:18:09 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

void	new_ray0(t_data *img, t_params *params)
{
	int		x;

	params->curr_ray = params->dir - params->fov / 2;
	x = 0;
	while (x < params->rx)
	{
		new_ray1(img, params, x);
		params->curr_ray += params->fov / params->rx;
		x++;
	}
}

void	new_ray1(t_data *img, t_params *params, int x)
{
	t_rays	ray;

	ray.rayDirX = cos(params->curr_ray);
	ray.rayDirY = sin(params->curr_ray);
	ray.mapX = params->pos_x;
	ray.mapY = params->pos_y;
	ray.hit = 0;
	if (ray.rayDirX == 0)
	{
		ray.deltaDistX = 1;
		ray.deltaDistY = 0;
	}
	else if (ray.rayDirY == 0)
	{
		ray.deltaDistX = 0;
		ray.deltaDistY = 1;
	}
	else
	{
		ray.deltaDistX = fabs(1 / ray.rayDirX);
		ray.deltaDistY = fabs(1 / ray.rayDirY);
	}
	new_ray2(img, params, &ray, x);
}

void	new_ray2(t_data *img, t_params *params, t_rays *ray, int x)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (params->pos_x - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1 - params->pos_x) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (params->pos_y - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1 - params->pos_y) * ray->deltaDistY;
	}
	new_ray3(img, params, ray, x);
}

void	new_ray3(t_data *img, t_params *params, t_rays *ray, int x)
{
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if ((params->map)[(int)floor(ray->mapY / SCL)][(int)floor(ray->mapX
		/ SCL)] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpWallDist = (ray->mapX - params->pos_x + (1 - ray->stepX) / 2)
			/ ray->rayDirX;
	else
		ray->perpWallDist = (ray->mapY - params->pos_y + (1 - ray->stepY) / 2)
			/ ray->rayDirY;
	draw_world(img, params, ray, x);
}
