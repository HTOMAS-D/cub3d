/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:52:03 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 17:32:38 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_door(t_cub *cub)
{
	int	h;

	cub->screen.text_start = cub->door.printx;
	cub->screen.text_end = cub->door.printy;
	if (cub->door.printy >= SCREENH)
		cub->door.printy = SCREENH - 1;
	if (cub->door.printx < 0)
		cub->door.printx = 0;
	h = cub->door.printx -1;
	cub->ray.wallside = cub->door.ray.wallside;
	cub->ray.wallx = cub->door.ray.wallx;
	while (++h < cub->door.printy)
	{
		if (!check_color(cub->screen.x_axis, h, 89, &cub->door.animation.img))
			my_mlx_pixel_put(&cub->screen, cub->screen.x_axis, h, \
			get_color(cub->screen.x_axis, h, 64));
	}
	cub->ray.wallside = -2;
	h = cub->door.printx -1;
	while (++h < cub->door.printy)
		my_mlx_pixel_put(&cub->screen, cub->screen.x_axis, h, \
		get_color(cub->screen.x_axis, h, 89));
}

void	put_screen(t_cub *cub)
{
	int	h;

	h = -1;
	while (++h < cub->horizon)
		my_mlx_pixel_put(&cub->screen, cub->screen.x_axis, h, cub->map.ceiling);
	h = cub->horizon -1;
	while (++h < SCREENH)
		my_mlx_pixel_put(&cub->screen, cub->screen.x_axis, h, cub->map.floor);
	if (cub->screen.floorpoint >= SCREENH)
		cub->screen.floorpoint = SCREENH - 1;
	if (cub->screen.ceilingpoint < 0)
		cub->screen.ceilingpoint = 0;
	h = cub->screen.ceilingpoint - 1;
	while (++h < cub->screen.floorpoint)
		my_mlx_pixel_put(&cub->screen, cub->screen.x_axis, h, \
		get_color(cub->screen.x_axis, h, 64));
	if (cub->door.ray.hit)
		put_door(cub);
}

void	get_door(t_cub *cub, t_ray *ray)
{
	double	wall_dist;
	double	door_h;

	if (!cub->door.ray.hit)
		return ;
	if (ray->side == 0)
		ray->wall_dist = ray->sidedistx - ray->deltadistx;
	else
		ray->wall_dist = ray->sidedisty - ray->deltadisty;
	if (ray->side == 0)
		wall_dist = (ray->mapx - cub->player.posx + \
		(1 - ray->stepx) / 2) / ray->raydirx;
	else
		wall_dist = (ray->mapy - cub->player.posy + \
		(1 - ray->stepy) / 2) / ray->raydiry;
	door_h = (int)(SCREENH / wall_dist);
	if (ray->side == 0) 
		ray->wallx = cub->player.posy + ray->wall_dist * ray->raydiry;
	else
		ray->wallx = cub->player.posx + ray->wall_dist * ray->raydirx;
	ray->wallx -= floor((ray->wallx));
	cub->door.printy = cub->horizon + door_h / 2;
	cub->door.printx = cub->horizon - door_h / 2;
	if (cub->door.hp)
		cub->zbuffer[cub->screen.x_axis] = ray->wall_dist;
}

void	get_wall(t_cub *cub, t_ray *ray)
{
	double	wall_dist;

	if (ray->side == 0)
	{
		ray->wall_dist = ray->sidedistx - ray->deltadistx;
		wall_dist = (ray->mapx - cub->player.posx + \
		(1 - ray->stepx) / 2) / ray->raydirx;
		cub->screen.wallh = (int)(SCREENH / wall_dist);
		cub->ray.wallx = cub->player.posy + ray->wall_dist * ray->raydiry;
	}
	else
	{
		ray->wall_dist = ray->sidedisty - ray->deltadisty;
		wall_dist = (ray->mapy - cub->player.posy + \
		(1 - ray->stepy) / 2) / ray->raydiry;
		cub->screen.wallh = (int)(SCREENH / wall_dist);
		cub->ray.wallx = cub->player.posx + ray->wall_dist * ray->raydirx;
	}
	cub->ray.wallx -= floor((cub->ray.wallx));
	cub->screen.floorpoint = cub->horizon + cub->screen.wallh / 2;
	cub->screen.text_end = cub->screen.floorpoint;
	cub->screen.ceilingpoint = cub->horizon - cub->screen.wallh / 2;
	cub->screen.text_start = cub->screen.ceilingpoint;
	cub->zbuffer[cub->screen.x_axis] = ray->wall_dist;
}

void	copy_ray(t_ray *og, int *counter)
{
	*counter += 1;
	cub()->ray.hit = 1;
	cub()->door.ray.hit = 1;
	cub()->door.ray.raydirx = og->raydirx;
	cub()->door.ray.raydiry = og->raydiry;
	cub()->door.ray.sidedistx = og->sidedistx;
	cub()->door.ray.sidedisty = og->sidedisty;
	cub()->door.ray.deltadistx = og->deltadistx;
	cub()->door.ray.deltadisty = og->deltadisty;
	cub()->door.ray.mapx = og->mapx;
	cub()->door.ray.mapy = og->mapy;
	cub()->door.ray.stepx = og->stepx;
	cub()->door.ray.stepy = og->stepy;
	cub()->door.ray.side = og->side;
	cub()->door.ray.wallside = og->wallside;
}
