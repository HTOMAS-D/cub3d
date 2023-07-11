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

	// Calculate the mouse movement in the X direction
	int move_x = x - (SCREENW / 2);
	(void) y;
	// Rotate the player's view based on the mouse movement
	rotation(&(cub->player), MOUSE_SENSITIVITY * move_x);

	// Update the raycasting and render the scene
	raycaster(cub);
	render(cub);

	// Reset the mouse position to the center of the screen
	mlx_mouse_move(cub->win, SCREENW / 2, SCREENH / 2);

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
	//printf("pressed\n");
	if(key == KEY_ESC)
		free_exit(cub, "Exit was successfull");
	if(key == KEY_W)
		move_w(cub);
	if(key == KEY_S)
		move_s(cub);
	if(key == KEY_A)
		move_a(cub);
	if(key == KEY_D)
		move_d(cub);
	return 0;
}