#include "cub3d.h"

void move_w(t_cub *cub)
{
	double newPosX = cub->player.posX + cub->player.dirX * MOVE_SPEED;
	double newPosY = cub->player.posY + cub->player.dirY * MOVE_SPEED;
	if (cub->map.iso_map[(int)newPosY][(int)newPosX] != '1') // Check if the new position is a valid location
	{
		cub->player.posX = newPosX;
		cub->player.posY = newPosY;
	}
}

void move_s(t_cub *cub)
{
	double newPosX = cub->player.posX - cub->player.dirX * MOVE_SPEED;
	double newPosY = cub->player.posY - cub->player.dirY * MOVE_SPEED;
	if (cub->map.iso_map[(int)newPosY][(int)newPosX] != '1') // Check if the new position is a valid location
	{
		cub->player.posX = newPosX;
		cub->player.posY = newPosY;
	}
}

void move_a(t_cub *cub)
{
	double newPosX = cub->player.posX - cub->player.fovX * MOVE_SPEED;
	double newPosY = cub->player.posY - cub->player.fovY * MOVE_SPEED;
	if (cub->map.iso_map[(int)newPosY][(int)newPosX] != '1') // Check if the new position is a valid location
	{
		cub->player.posX = newPosX;
		cub->player.posY = newPosY;
	}
}

void move_d(t_cub *cub)
{
	double newPosX = cub->player.posX + cub->player.fovX * MOVE_SPEED;
	double newPosY = cub->player.posY + cub->player.fovY * MOVE_SPEED;
	if (cub->map.iso_map[(int)newPosY][(int)newPosX] != '1') // Check if the new position is a valid location
	{
		cub->player.posX = newPosX;
		cub->player.posY = newPosY;
	}
}


