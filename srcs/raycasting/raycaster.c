#include "cub3d.h"

void put_screen(t_cub *cub)
{
    int skyColor = 0x0000FF;   // Blue color for the sky
    int groundColor = 0x808080; // Grey color for the ground
    int h;

    h = -1;
    // Draw the sky
    while(++h < cub->horizon)
        my_mlx_pixel_put(&cub->screen, cub->screen.x_axis, h, skyColor);
    // Draw the ground
    h = cub->horizon -1;
    while(++h < SCREENH)
        my_mlx_pixel_put(&cub->screen, cub->screen.x_axis, h, groundColor);
    // Render the walls
    h = cub->screen.ceilingpoint -1;
    while (++h < cub->screen.floorPoint)
        my_mlx_pixel_put(&cub->screen, cub->screen.x_axis, h, get_color(&cub->wall, cub->screen.x_axis, h));
}


void get_wall(t_cub *cub, t_ray *ray)
{
    double wallDist;
    
    if (ray->side == 0)
        ray->wall_dist = ray->sidedistX - ray->deltaDistX;
    else
        ray->wall_dist = ray->sidedistY - ray->deltaDistY;
    if (ray->side == 0)
        wallDist = (ray->mapX - cub->player.posX + (1 - ray->stepX) / 2) / ray->rayDirX;
    else
        wallDist = (ray->mapY - cub->player.posY + (1 - ray->stepY) / 2) / ray->rayDirY;
    cub->screen.wallH = (int)(SCREENH / wallDist);
    if (cub->ray.side == 0) 
        cub->ray.wallx = cub->player.posY  + ray->wall_dist * ray->rayDirY;
    else  
        cub->ray.wallx = cub->player.posX + ray->wall_dist * ray->rayDirX;
    cub->ray.wallx -= floor((cub->ray.wallx));
    cub->screen.floorPoint = cub->horizon + cub->screen.wallH / 2;
    cub->screen.text_end = cub->screen.floorPoint;
    if (cub->screen.floorPoint >= SCREENH)
        cub->screen.floorPoint = SCREENH - 1;
    cub->screen.ceilingpoint = cub->horizon - cub->screen.wallH / 2;
    cub->screen.text_start = cub->screen.ceilingpoint;
    if (cub->screen.ceilingpoint < 0)
        cub->screen.ceilingpoint = 0;
}


void ray_hit(t_cub *cub, t_ray *ray)
{
    int i = 0;
    while (i == 0)
    {
        if (ray->sidedistX < ray->sidedistY)
        {
            ray->sidedistX += ray->deltaDistX;
            ray->mapX += ray->stepX;
            ray->side = 0;
        }
        else
        {
            ray->sidedistY += ray->deltaDistY;
            ray->mapY += ray->stepY;
            ray->side = 1;
        }
        if (cub->map.iso_map[ray->mapY][ray->mapX] != '0')
            i = 1;
    }
}

void calc_step(t_cub *cub, t_ray *ray)
{
    if (ray->rayDirX < 0)
    {
        ray->stepX = -1;
        ray->sidedistX = (cub->player.posX - ray->mapX) * ray->deltaDistX;
    }
    else
    {
        ray->stepX = 1;
        ray->sidedistX = (ray->mapX + 1.0 - cub->player.posX) * ray->deltaDistX;
    }
    if (ray->rayDirY < 0)
    {
        ray->stepY = -1;
        ray->sidedistY = (cub->player.posY - ray->mapY) * ray->deltaDistY;
    }
    else
    {
        ray->stepY = 1;
        ray->sidedistY = (ray->mapY + 1.0 - cub->player.posY) * ray->deltaDistY;
    }
}

void raycaster(t_cub *cub)
{
    double viewx;

    cub->screen.x_axis = -1;
    while (++cub->screen.x_axis < SCREENW)
    {
        // Calculate ray position and direction
        viewx = 2 * cub->screen.x_axis / (double)SCREENW - 1; // x-coordinate in camera space
        cub->ray.rayDirX = cub->player.dirX + cub->player.fovX * viewx;
        cub->ray.rayDirY = cub->player.dirY + cub->player.fovY * viewx;
        cub->ray.mapX = (int)cub->player.posX;
        cub->ray.mapY = (int)cub->player.posY;
        if (cub->ray.rayDirX == 0)
            cub->ray.deltaDistX = 1e30;
        else
            cub->ray.deltaDistX = fabs(1 / cub->ray.rayDirX);
        if (cub->ray.rayDirY == 0)
            cub->ray.deltaDistY = 1e30;
        else
            cub->ray.deltaDistY = fabs(1 / cub->ray.rayDirY);
        calc_step(cub, &(cub->ray));
        ray_hit(cub, &(cub->ray));
        get_wall(cub, &(cub->ray));
        put_screen(cub);
    }
}
