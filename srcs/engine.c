/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <htomas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:50:15 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 19:05:14 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(t_cub *cub)
{
	raycaster(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->screen.ptr, 0, 0);
	return (0);
}

int	update_game(t_cub *cub)
{
	update_player(cub);
	return (0);
}

int	game_loop(t_cub *cub)
{
	update_game(cub);
	render(cub);
	return (0);
}

int	update_player(t_cub *cub)
{
	if (cub->player.move.w)
		move_w(cub);
	if (cub->player.move.s)
		move_s(cub);
	if (cub->player.move.a)
		move_a(cub);
	if (cub->player.move.d)
		move_d(cub);
	if (cub->player.move.a_left)
		look_left(cub);
	if (cub->player.move.a_right)
		look_right(cub);
	return (0);
}
