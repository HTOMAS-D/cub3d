/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:32:19 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 17:35:18 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(t_ray *ray)
{
	if (ray->sidedistX < ray->sidedistY)
	{
		ray->sidedistX += ray->deltaDistX;
		ray->mapX += ray->stepX;
		ray->side = 0;
		if (ray->stepX < 0)
			ray->wallside = 0;
		else
			ray->wallside = 2;
	}
	else
	{
		ray->sidedistY += ray->deltaDistY;
		ray->mapY += ray->stepY;
		ray->side = 1;
		if (ray->stepY < 0)
			ray->wallside = 1;
		else
			ray->wallside = 3;
	}
}

void	ray_hit(t_cub *cub, t_ray *ray)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while (i == 0)
	{
		dda(ray);
		if (cub->map.iso_map[ray->mapY][ray->mapX] == '1')
			i = 1;
		else if (cub->map.iso_map[ray->mapY][ray->mapX] == 'D')
			copy_ray(ray, &d);
	}
	if (!d)
		cub->door.ray.hit = 0;
}

void	calc_step(t_cub *cub, t_ray *ray)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sidedistX = (cub->player.posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sidedistX = (ray->mapX + 1.0 - cub->player.posX) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sidedistY = (cub->player.posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sidedistY = (ray->mapY + 1.0 - cub->player.posY) * ray->deltaDistY;
	}
}

void	calc_directions(t_cub *cub)
{
	double	viewx;

	viewx = 2 * cub->screen.x_axis / (double)SCREENW -1;
	cub->ray.rayDirX = cub->player.dirX + cub->player.fovX * viewx;
	cub->ray.rayDirY = cub->player.dirY + cub->player.fovY * viewx;
	cub->ray.mapX = (int)cub->player.posX;
	cub->ray.mapY = (int)cub->player.posY;
	if (cub->ray.rayDirX == 0)
		cub->ray.deltaDistX = 1e30;
	else
		cub->ray.deltaDistX = fabs(1 / cub->ray.rayDirX);
	if (cub->ray.rayDirY == 0)
		cub->ray.deltaDistY = 1e30;
	else
		cub->ray.deltaDistY = fabs(1 / cub->ray.rayDirY);
}

void	raycaster(t_cub *cub)
{
	cub->screen.x_axis = -1;
	cub->ray.hit = 0;
	while (++cub->screen.x_axis < SCREENW)
	{
		calc_directions(cub);
		calc_step(cub, &(cub->ray));
		ray_hit(cub, &(cub->ray));
		get_wall(cub, &(cub->ray));
		get_door(cub, &(cub->door.ray));
		put_screen(cub);
	}
	print_object(cub);
}
