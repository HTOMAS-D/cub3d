#include "cub3d.h"

int close_game(t_cub *cub)
{
	free_exit(cub, "Exit was successfull");
	return 0;
}

int move_mouse(int x, int y, t_cub *cub)
{
	// if (cub->game_won)
	// 	return 0;
	
	(void)y;
	mlx_mouse_get_pos(cub->win, &x, &y);
	
	if (x != SCREENW / 2)
	{
		double move_x = MOUSE_SENSITIVITY * (x - SCREENW / 2) / (double)SCREENW;
		rotation(&cub->player, move_x);
		raycaster(cub);
		render(cub);
		mlx_mouse_move(cub->win, SCREENW / 2, SCREENH / 2);
	}
	
	return 1;
}

void rotation(t_player *player, double angle)
{
	double	x;
	double	y;

	angle *= 3.14159 / 180;
	x = player->dirY * cos(angle) + player->dirX * sin(angle);
	y = player->dirY * -sin(angle) + player->dirX * cos(angle);
	player->dirY = x;
	player->dirX = y;
	x = player->fovX * cos(angle) + player->fovY * sin(angle);
	y = player->fovX * -sin(angle) + player->fovY * cos(angle);
	player->fovX = x;
	player->fovY = y;
}



int get_key(int key, t_cub *cub)
{
	if(key == KEY_ESC)
		free_exit(cub, "Exit was successfull");
	return 0;
}