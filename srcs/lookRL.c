/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookRL.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:48:22 by htomas-d          #+#    #+#             */
/*   Updated: 2023/08/17 19:18:03 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	look_right(t_cub *cub)
{
	double	rotspeed;
	double	olddirx;
	double	oldplanex;

	rotspeed = 0.05;
	olddirx = cub->player.dirx;
	oldplanex = cub->player.fovx;
	cub->player.dirx = cub->player.dirx
		* cos(rotspeed) - cub->player.diry * sin(rotspeed);
	cub->player.diry = olddirx * sin(rotspeed)
		+ cub->player.diry * cos(rotspeed);
	cub->player.fovx = cub->player.fovx
		* cos(rotspeed) - cub->player.fovy * sin(rotspeed);
	cub->player.fovy = oldplanex * sin(rotspeed)
		+ cub->player.fovy * cos(rotspeed);
}

void	look_left(t_cub *cub)
{
	double	rotspeed;
	double	olddirx;
	double	oldplanex;

	oldplanex = cub->player.fovx;
	olddirx = cub->player.dirx;
	rotspeed = 0.05;
	cub->player.dirx = cub->player.dirx * cos(-rotspeed)
		- cub->player.diry * sin(-rotspeed);
	cub->player.diry = olddirx * sin(-rotspeed)
		+ cub->player.diry * cos(-rotspeed);
	cub->player.fovx = cub->player.fovx
		* cos(-rotspeed) - cub->player.fovy * sin(-rotspeed);
	cub->player.fovy = oldplanex * sin(-rotspeed)
		+ cub->player.fovy * cos(-rotspeed);
}
