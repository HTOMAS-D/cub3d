/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:50:15 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 16:51:33 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(t_cub *cub)
{
	raycaster(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->screen.ptr, 0, 0);
	fps_counter(cub);
	minimap(cub, cub->map.iso_map);
	if (cub->press_f && !cub->door.animation.frame)
		print_phrase(cub, "Press F to open");
	if (cub->press_f && cub->door.animation.frame == cub->door.animation.max)
		print_phrase(cub, "Press F to close");
	cub->n_renders++;
	return (0);
}

int	update_game(t_cub *cub)
{
	update_player(cub);
	update_wizard_animation(cub);
	if (cub->door.x >= 0)
		press_f(cub);
	update_door_animation(cub);
	return (0);
}

int game_loop(t_cub* cub)
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
	return (0);
}
