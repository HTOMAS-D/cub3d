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
	// raycaster(cub);
	// render(cub);

	// Reset the mouse position to the center of the screen
	mlx_mouse_move(cub->mlx, cub->win, SCREENW / 2, cub->horizon);

	return (1);
}

void rotation(t_player *player, double angle)
{
    // Convert the angle from degrees to radians
    double radians = angle * (M_PI / 180.0);

    // Compute the sine and cosine of the angle
    double cosAngle = cos(radians);
    double sinAngle = sin(radians);

    // Rotate the player's direction vector
    double newDirX = player->dirX * cosAngle - player->dirY * sinAngle;
    double newDirY = player->dirX * sinAngle + player->dirY * cosAngle;
    player->dirX = newDirX;
    player->dirY = newDirY;

    // Rotate the player's FOV vector
    double newFovX = player->fovX * cosAngle - player->fovY * sinAngle;
    double newFovY = player->fovX * sinAngle + player->fovY * cosAngle;
    player->fovX = newFovX;
    player->fovY = newFovY;
}

int	key_release(int key, t_cub *cub)
{
	if(key == KEY_W)
		cub->player.move.w = 0;
	if(key == KEY_S)
		cub->player.move.s = 0;
	if(key == KEY_A)
		cub->player.move.a = 0;
	if(key == KEY_D)
		cub->player.move.d = 0;
	return (0);
}

int get_key(int key, t_cub *cub)
{
	if(key == KEY_ESC)
		free_exit(cub, "Exit was successfull");
	if(key == KEY_W)
		cub->player.move.w = 1;
	if(key == KEY_S)
		cub->player.move.s = 1;
	if(key == KEY_A)
		cub->player.move.a = 1;
	if(key == KEY_D)
		cub->player.move.d = 1;
	if(key == KEY_ESPACE && !cub->player.move.gravity && !cub->player.move.jump)
		cub->player.move.jump = JUMP_HEIGHT;
		//printf("pressed\n");
	//printf("%d\n", key);
	return 0;
}