/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:52:03 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 18:29:41 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
