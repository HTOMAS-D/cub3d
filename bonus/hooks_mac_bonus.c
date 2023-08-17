/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:55:11 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 18:33:57 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

struct s_rotation
{
	double	radians;
	double	cos_angle;
	double	sin_angle;
	double	new_dirx;
	double	new_diry;
	double	new_fovx;
	double	new_fovy;
}			t_rotation;

int	close_game(t_cub *cub)
{
	free_exit(cub, "Exit was successfull");
	return (0);
}

int	move_mouse(int x, int y, t_cub *cub)
{
	int	move_x;

	move_x = x - (SCREENW / 2);
	(void) y;
	rotation(&(cub->player), MOUSE_SENSITIVITY * move_x);
	mlx_mouse_move(cub->win, SCREENW / 2, cub->horizon);
	return (1);
}

void	rotation(t_player *player, double angle)
{
	struct s_rotation	data;

	data.radians = angle * (M_PI / 180.0);
	data.cos_angle = cos(data.radians);
	data.sin_angle = sin(data.radians);
	data.new_dirx = player->dirx * data.cos_angle - player->diry * \
	data.sin_angle;
	data.new_diry = player->dirx * data.sin_angle + player->diry * \
	data.cos_angle;
	player->dirx = data.new_dirx;
	player->diry = data.new_diry;
	data.new_fovx = player->fovx * data.cos_angle - player->fovy * \
	data.sin_angle;
	data.new_fovy = player->fovx * data.sin_angle + player->fovy * \
	data.cos_angle;
	player->fovx = data.new_fovx;
	player->fovy = data.new_fovy;
}

int	key_release(int key, t_cub *cub)
{
	if (key == KEY_W)
		cub->player.move.w = 0;
	if (key == KEY_S)
		cub->player.move.s = 0;
	if (key == KEY_A)
		cub->player.move.a = 0;
	if (key == KEY_D)
		cub->player.move.d = 0;
	return (0);
}

int	get_key(int key, t_cub *cub)
{
	if (key == KEY_ESC)
		free_exit(cub, "Exit was successfull");
	if (key == KEY_W)
		cub->player.move.w = 1;
	if (key == KEY_S)
		cub->player.move.s = 1;
	if (key == KEY_A)
		cub->player.move.a = 1;
	if (key == KEY_D)
		cub->player.move.d = 1;
	if (key == KEY_F && cub->door.x >= 0 && cub->press_f)
	{
		if (cub->door.hp)
			cub->door.hp = 0;
		else
			cub->door.hp = 1;
	}
	return (0);
}
