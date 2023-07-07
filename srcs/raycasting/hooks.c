#include "cub3d.h"

int close_game(t_cub *cub)
{
	free_exit(cub, "Exit was successfull");
	return 0;
}


int move_mouse(int x, int y, t_cub *cub)
{
	double move;

	mlx_mouse_get_pos(cub->win, &x, &y);
	if (x != SCREENW / 2)
	{
		move = (double)(x - SCREENW / 2) / MOUSE_SENSITIVITY;
		rotation(cub, move);
		raycaster(cub);
		mlx_mouse_move(cub->win, SCREENW / 2, SCREENH / 2);
	}
	return 0;
}


void rotation(t_cub *cub, double move)
{
	double old_dirX, old_fovX;
	double cos_move, sin_move;

	old_dirX = cub->player.dirX;
	old_fovX = cub->player.fovX;

	cos_move = cos(move);
	sin_move = sin(move);

	// Rotate the player's direction vector
	cub->player.dirX = old_dirX * cos_move - cub->player.dirY * sin_move;
	cub->player.dirY = old_dirX * sin_move + cub->player.dirY * cos_move;

	// Rotate the player's FOV vector
	cub->player.fovX = old_fovX * cos_move - cub->player.fovY * sin_move;
	cub->player.fovY = old_fovX * sin_move + cub->player.fovY * cos_move;
}


int get_key(int key, t_cub *cub)
{
	if(key == KEY_ESC)
		free_exit(cub, "Exit was successfull");
	return 0;
}