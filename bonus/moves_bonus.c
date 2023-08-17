/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:46:39 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 18:30:44 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_w(t_cub *cub)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cub->player.posx + cub->player.dirx * MOVE_SPEED;
	new_pos_y = cub->player.posy + cub->player.diry * MOVE_SPEED;
	if (cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != '1' && \
	cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != 'Z' && \
	((cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != 'D') || \
	(cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] == 'D' && \
	cub->door.animation.frame == cub->door.animation.max)))
	{
		cub->player.posx = new_pos_x;
		cub->player.posy = new_pos_y;
	}
}

void	move_s(t_cub *cub)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cub->player.posx - cub->player.dirx * MOVE_SPEED;
	new_pos_y = cub->player.posy - cub->player.diry * MOVE_SPEED;
	if (cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != '1' && \
	cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != 'Z' && \
	((cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != 'D') || \
	(cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] == 'D' && \
	cub->door.animation.frame == cub->door.animation.max)))
	{
		cub->player.posx = new_pos_x;
		cub->player.posy = new_pos_y;
	}
}

void	move_a(t_cub *cub)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cub->player.posx - cub->player.fovx * MOVE_SPEED;
	new_pos_y = cub->player.posy - cub->player.fovy * MOVE_SPEED;
	if (cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != '1' && \
	cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != 'Z' && \
	((cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != 'D') || \
	(cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] == 'D' && \
	cub->door.animation.frame == cub->door.animation.max)))
	{
		cub->player.posx = new_pos_x;
		cub->player.posy = new_pos_y;
	}
}

void	move_d(t_cub *cub)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cub->player.posx + cub->player.fovx * MOVE_SPEED;
	new_pos_y = cub->player.posy + cub->player.fovy * MOVE_SPEED;
	if (cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != '1' && \
	cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != 'Z' && \
	((cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != 'D') || \
	(cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] == 'D' && \
	cub->door.animation.frame == cub->door.animation.max)))
	{
		cub->player.posx = new_pos_x;
		cub->player.posy = new_pos_y;
	}
}
