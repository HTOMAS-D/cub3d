#include "cub3d.h"

void move_w(t_cub *cub)
{
	double newPosX = cub->player.posX + cub->player.dirX * MOVE_SPEED;
	double newPosY = cub->player.posY + cub->player.dirY * MOVE_SPEED;
	if (cub->map.iso_map[(int)newPosY][(int)newPosX] != '1' && cub->map.iso_map[(int)newPosY][(int)newPosX] != 'Z' && ((cub->map.iso_map[(int)newPosY][(int)newPosX] != 'D') || (cub->map.iso_map[(int)newPosY][(int)newPosX] == 'D' && cub->door.animation.frame == cub->door.animation.max))) // Check if the new position is a valid location
	{
		cub->player.posX = newPosX;
		cub->player.posY = newPosY;
	}
}

void move_s(t_cub *cub)
{
	double newPosX = cub->player.posX - cub->player.dirX * MOVE_SPEED;
	double newPosY = cub->player.posY - cub->player.dirY * MOVE_SPEED;
	if (cub->map.iso_map[(int)newPosY][(int)newPosX] != '1' && cub->map.iso_map[(int)newPosY][(int)newPosX] != 'Z' && ((cub->map.iso_map[(int)newPosY][(int)newPosX] != 'D') || (cub->map.iso_map[(int)newPosY][(int)newPosX] == 'D' && cub->door.animation.frame == cub->door.animation.max))) // Check if the new position is a valid location
	{
		cub->player.posX = newPosX;
		cub->player.posY = newPosY;
	}
}

void move_a(t_cub *cub)
{
	//printf("{POS X} = %f\n{POS Y} = %f\n{FOV X} = %f\n{FOV Y} = %f\n", cub->player.posX, cub->player.posY, cub->player.fovX, cub->player.fovY);
	double newPosX = cub->player.posX - cub->player.fovX * MOVE_SPEED;
	double newPosY = cub->player.posY - cub->player.fovY * MOVE_SPEED;
	if (cub->map.iso_map[(int)newPosY][(int)newPosX] != '1' && cub->map.iso_map[(int)newPosY][(int)newPosX] != 'Z' && ((cub->map.iso_map[(int)newPosY][(int)newPosX] != 'D') || (cub->map.iso_map[(int)newPosY][(int)newPosX] == 'D' && cub->door.animation.frame == cub->door.animation.max))) // Check if the new position is a valid location
	{
		cub->player.posX = newPosX;
		cub->player.posY = newPosY;
	}
}

void move_d(t_cub *cub)
{
	double newPosX = cub->player.posX + cub->player.fovX * MOVE_SPEED;
	double newPosY = cub->player.posY + cub->player.fovY * MOVE_SPEED;
	if (cub->map.iso_map[(int)newPosY][(int)newPosX] != '1' && cub->map.iso_map[(int)newPosY][(int)newPosX] != 'Z' && ((cub->map.iso_map[(int)newPosY][(int)newPosX] != 'D') || (cub->map.iso_map[(int)newPosY][(int)newPosX] == 'D' && cub->door.animation.frame == cub->door.animation.max))) // Check if the new position is a valid location
	{
		cub->player.posX = newPosX;
		cub->player.posY = newPosY;
	}
}

void	jump(t_cub *cub)
{
	cub->horizon += cub->player.move.jump;
	cub->player.move.jump -= 2;
	if (cub->player.move.jump < 0)
		cub->player.move.jump = 0;
	cub->player.move.gravity = 0;
}
