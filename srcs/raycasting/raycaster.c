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
	if (cub->screen.floorPoint >= SCREENH)
		cub->screen.floorPoint = SCREENH - 1;
	if (cub->screen.ceilingpoint < 0)
		cub->screen.ceilingpoint = 0;
	h = cub->screen.ceilingpoint - 1;
	while (++h < cub->screen.floorPoint)
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
		ray->wall_dist = ray->sidedistX - ray->deltaDistX;
	else
		ray->wall_dist = ray->sidedistY - ray->deltaDistY;
	if (ray->side == 0)
		wall_dist = (ray->mapX - cub->player.posX + \
		(1 - ray->stepX) / 2) / ray->rayDirX;
	else
		wall_dist = (ray->mapY - cub->player.posY + \
		(1 - ray->stepY) / 2) / ray->rayDirY;
	door_h = (int)(SCREENH / wall_dist);
	if (ray->side == 0) 
		ray->wallx = cub->player.posY + ray->wall_dist * ray->rayDirY;
	else
		ray->wallx = cub->player.posX + ray->wall_dist * ray->rayDirX;
	ray->wallx -= floor((ray->wallx));
	cub->door.printy = cub->horizon + door_h / 2;
	cub->door.printx = cub->horizon - door_h / 2;
	if (cub->door.hp)
		cub->ZBuffer[cub->screen.x_axis] = ray->wall_dist;
}

void	get_wall(t_cub *cub, t_ray *ray)
{
	double	wall_dist;

	if (ray->side == 0)
	{
		ray->wall_dist = ray->sidedistX - ray->deltaDistX;
		wall_dist = (ray->mapX - cub->player.posX + \
		(1 - ray->stepX) / 2) / ray->rayDirX;
		cub->screen.wallH = (int)(SCREENH / wall_dist);
		cub->ray.wallx = cub->player.posY + ray->wall_dist * ray->rayDirY;
	}
	else
	{
		ray->wall_dist = ray->sidedistY - ray->deltaDistY;
		wall_dist = (ray->mapY - cub->player.posY + \
		(1 - ray->stepY) / 2) / ray->rayDirY;
		cub->screen.wallH = (int)(SCREENH / wall_dist);
		cub->ray.wallx = cub->player.posX + ray->wall_dist * ray->rayDirX;
	}
	cub->ray.wallx -= floor((cub->ray.wallx));
	cub->screen.floorPoint = cub->horizon + cub->screen.wallH / 2;
	cub->screen.text_end = cub->screen.floorPoint;
	cub->screen.ceilingpoint = cub->horizon - cub->screen.wallH / 2;
	cub->screen.text_start = cub->screen.ceilingpoint;
	cub->ZBuffer[cub->screen.x_axis] = ray->wall_dist;
}

void	copy_ray(t_ray *og, int *counter)
{
	*counter += 1;
	cub()->ray.hit = 1;
	cub()->door.ray.hit = 1;
	cub()->door.ray.rayDirX = og->rayDirX;
	cub()->door.ray.rayDirY = og->rayDirY;
	cub()->door.ray.sidedistX = og->sidedistX;
	cub()->door.ray.sidedistY = og->sidedistY;
	cub()->door.ray.deltaDistX = og->deltaDistX;
	cub()->door.ray.deltaDistY = og->deltaDistY;
	cub()->door.ray.mapX = og->mapX;
	cub()->door.ray.mapY = og->mapY;
	cub()->door.ray.stepX = og->stepX;
	cub()->door.ray.stepY = og->stepY;
	cub()->door.ray.side = og->side;
	cub()->door.ray.wallside = og->wallside;
}
