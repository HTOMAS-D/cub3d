/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:46:39 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 17:35:09 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_w(t_cub *cub)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cub->player.posX + cub->player.dirX * MOVE_SPEED;
	new_pos_y = cub->player.posY + cub->player.dirY * MOVE_SPEED;
	if (cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != '1' && \
	cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != 'Z' && \
	((cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != 'D') || \
	(cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] == 'D' && \
	cub->door.animation.frame == cub->door.animation.max)))
	{
		cub->player.posX = new_pos_x;
		cub->player.posY = new_pos_y;
	}
}

void	move_s(t_cub *cub)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cub->player.posX - cub->player.dirX * MOVE_SPEED;
	new_pos_y = cub->player.posY - cub->player.dirY * MOVE_SPEED;
	if (cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != '1' && \
	cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != 'Z' && \
	((cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != 'D') || \
	(cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] == 'D' && \
	cub->door.animation.frame == cub->door.animation.max)))
	{
		cub->player.posX = new_pos_x;
		cub->player.posY = new_pos_y;
	}
}

void	move_a(t_cub *cub)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cub->player.posX - cub->player.fovX * MOVE_SPEED;
	new_pos_y = cub->player.posY - cub->player.fovY * MOVE_SPEED;
	if (cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != '1' && \
	cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != 'Z' && \
	((cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != 'D') || \
	(cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] == 'D' && \
	cub->door.animation.frame == cub->door.animation.max)))
	{
		cub->player.posX = new_pos_x;
		cub->player.posY = new_pos_y;
	}
}

void	move_d(t_cub *cub)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cub->player.posX + cub->player.fovX * MOVE_SPEED;
	new_pos_y = cub->player.posY + cub->player.fovY * MOVE_SPEED;
	if (cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != '1' && \
	cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != 'Z' && \
	((cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] != 'D') || \
	(cub->map.iso_map[(int)new_pos_y][(int)new_pos_x] == 'D' && \
	cub->door.animation.frame == cub->door.animation.max)))
	{
		cub->player.posX = new_pos_x;
		cub->player.posY = new_pos_y;
	}
}
