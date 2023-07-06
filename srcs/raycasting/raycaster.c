#include "cub3d.h"

void calc_step(t_cub *cub, t_ray *ray)
{
	if(ray->rayDirX < 0)
	{
		ray->stepY = -1;
		ray->sidedistY = (cub->player.posY - ray->mapY) * ray->deltaDistY
	}
	else
	{
		ray->stepY = 1;
		ray->sidedistY = (ray->mapY + 1 - cub->player.posY) * ray->deltaDistY;
	}
	if(ray->rayDirY < 0)
	{
		ray->stepX = -1;
		ray->sidedistX = (cub->player.posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sidedistX = (ray->mapX + 1 - cub->player.posX) *ray->deltaDistX;
	}	
}

void raycaster(t_cub * cub)
{
	double viewx;

	cub->screen.x_axis = -1;
	while(cub->screen.x_axis < SCREENW)
	{
		//calculate ray position and direction
		viewx = 2 * cub->screen.x_axis / (double)SCREENW - 1; //x-coordinate in camera space
		cub->ray.rayDirX = cub->player.dirX + cub->player.fovX * viewx;
		cub->ray.rayDirY = cub->player.dirY + cub->player.fovY * viewx;
		cub->ray.mapX = (int)cub->player.posX;
		cub->ray.mapY = (int)cub->player.posY;
		cub->ray.deltaDistX = (cub->ray.rayDirX == 0) ? 1e30 : fabs(1 / cub->ray.rayDirX);
		cub->ray.deltaDistY = (cub->ray.rayDirY == 0) ? 1e30 : fabs(1 / cub->ray.rayDirY);
		calc_step(cub, &(cub->ray));
	}
}