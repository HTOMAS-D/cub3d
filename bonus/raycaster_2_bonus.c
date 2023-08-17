/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:32:19 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 18:59:11 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(t_ray *ray)
{
	if (ray->sidedistx < ray->sidedisty)
	{
		ray->sidedistx += ray->deltadistx;
		ray->mapx += ray->stepx;
		ray->side = 0;
		if (ray->stepx < 0)
			ray->wallside = 0;
		else
			ray->wallside = 2;
	}
	else
	{
		ray->sidedisty += ray->deltadisty;
		ray->mapy += ray->stepy;
		ray->side = 1;
		if (ray->stepy < 0)
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
		if (cub->map.iso_map[ray->mapy][ray->mapx] == '1')
			i = 1;
		else if (cub->map.iso_map[ray->mapy][ray->mapx] == 'D')
			copy_ray(ray, &d);
	}
	if (!d)
		cub->door.ray.hit = 0;
}

void	calc_step(t_cub *cub, t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (cub->player.posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - cub->player.posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (cub->player.posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - cub->player.posy) * ray->deltadisty;
	}
}

void	calc_directions(t_cub *cub)
{
	double	viewx;

	viewx = 2 * cub->screen.x_axis / (double)SCREENW -1;
	cub->ray.raydirx = cub->player.dirx + cub->player.fovx * viewx;
	cub->ray.raydiry = cub->player.diry + cub->player.fovy * viewx;
	cub->ray.mapx = (int)cub->player.posx;
	cub->ray.mapy = (int)cub->player.posy;
	if (cub->ray.raydirx == 0)
		cub->ray.deltadistx = 1e30;
	else
		cub->ray.deltadistx = fabs(1 / cub->ray.raydirx);
	if (cub->ray.raydiry == 0)
		cub->ray.deltadisty = 1e30;
	else
		cub->ray.deltadisty = fabs(1 / cub->ray.raydiry);
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
