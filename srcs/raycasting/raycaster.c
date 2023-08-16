#include "cub3d.h"

void put_screen(t_cub *cub)
{
    int h;

    h = -1;
    // Draw the sky
    while(++h < cub->horizon)
        my_mlx_pixel_put(&cub->screen, cub->screen.x_axis, h, cub->map.ceiling);
    // Draw the ground
    h = cub->horizon -1;
    while(++h < SCREENH)
        my_mlx_pixel_put(&cub->screen, cub->screen.x_axis, h, cub->map.floor);
    // Render the walls
    h = cub->screen.ceilingpoint - 1;
    while (++h < cub->screen.floorPoint)
        my_mlx_pixel_put(&cub->screen, cub->screen.x_axis, h, get_color(cub->screen.x_axis, h, 64));
    // Render Door
    if (!cub->door.ray.hit)
        return ;
    cub->screen.text_start = cub->door.printx; //top
    cub->screen.text_end = cub->door.printy; //bottom 
    if (cub->door.printy >= SCREENH)
        cub->door.printy = SCREENH - 1;
    if (cub->door.printx < 0)
        cub->door.printx = 0;
    h = cub->door.printx -1;
    cub->ray.wallside = cub->door.ray.wallside;
    cub->ray.wallx = cub->door.ray.wallx;
    while (++h < cub->door.printy)
    {
        if (!check_color(cub->screen.x_axis, h, 89, &cub->door.animation.img))
            my_mlx_pixel_put(&cub->screen, cub->screen.x_axis, h, get_color(cub->screen.x_axis, h, 64));
    }
    cub->ray.wallside = -2;
    h = cub->door.printx -1;
    //printf("%f %f\n", cub->door.printx, cub->door.printy);
    while (++h < cub->door.printy)
        my_mlx_pixel_put(&cub->screen, cub->screen.x_axis, h, get_color(cub->screen.x_axis, h, 89));
    //exit(1);
}

void get_door(t_cub *cub, t_ray *ray)
{
    double wallDist;
    double  doorH;
    
    if (!cub->door.ray.hit)
        return ;
    if (ray->side == 0)
        ray->wall_dist = ray->sidedistX - ray->deltaDistX;
    else
        ray->wall_dist = ray->sidedistY - ray->deltaDistY;
    if (ray->side == 0)
        wallDist = (ray->mapX - cub->player.posX + (1 - ray->stepX) / 2) / ray->rayDirX;
    else
        wallDist = (ray->mapY - cub->player.posY + (1 - ray->stepY) / 2) / ray->rayDirY;
    doorH = (int)(SCREENH / wallDist);
    if (ray->side == 0) 
        ray->wallx = cub->player.posY + ray->wall_dist * ray->rayDirY;
    else
        ray->wallx = cub->player.posX + ray->wall_dist * ray->rayDirX;
    ray->wallx -= floor((ray->wallx));
    cub->door.printy = cub->horizon + doorH / 2; //floor point
    cub->door.printx = cub->horizon - doorH / 2;
    if (cub->door.hp)
        cub->ZBuffer[cub->screen.x_axis] = ray->wall_dist;
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
    cub->ZBuffer[cub->screen.x_axis] = ray->wall_dist;
}


void ray_hit(t_cub *cub, t_ray *ray)
{
    int i = 0;
    int d = 0;

    while (i == 0)
    {
        if (ray->sidedistX < ray->sidedistY)
        {
            ray->sidedistX += ray->deltaDistX;
            ray->mapX += ray->stepX;
            ray->side = 0;
            if (ray->stepX < 0)
                ray->wallside = 0;
            else
                ray->wallside = 2;
        }
        else
        {
            ray->sidedistY += ray->deltaDistY;
            ray->mapY += ray->stepY;
            ray->side = 1;
            if (ray->stepY < 0)
                ray->wallside = 1;
            else
                ray->wallside = 3;
        }
        if (cub->map.iso_map[ray->mapY][ray->mapX] == '1')
            i = 1;
        else if (cub->map.iso_map[ray->mapY][ray->mapX] == 'D')
        {
            d++;
            cub->ray.hit = 1;
            cub->door.ray.hit = 1;
            cub->door.ray.rayDirX = ray->rayDirX;
            cub->door.ray.rayDirY = ray->rayDirY;
            cub->door.ray.sidedistX = ray->sidedistX;
            cub->door.ray.sidedistY = ray->sidedistY;
            cub->door.ray.deltaDistX = ray->deltaDistX;
            cub->door.ray.deltaDistY = ray->deltaDistY;
            cub->door.ray.mapX = ray->mapX;
            cub->door.ray.mapY = ray->mapY;
            cub->door.ray.stepX = ray->stepX;
            cub->door.ray.stepY = ray->stepY;
            cub->door.ray.side = ray->side;
            cub->door.ray.wallside = ray->wallside;
        }
    }
    if (!d)
        cub->door.ray.hit = 0;
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
    cub->ray.hit = 0;
    // int y = -1;
    // int x;
    // while (cub->map.iso_map[++y])
    // {
    //     x = -1;
    //     while (cub->map.iso_map[y][++x])
    //         printf("%c", cub->map.iso_map[y][x]);
    //     printf("\n");
    // }
    // exit(1);
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
        get_door(cub, &(cub->door.ray));
        // if (cub->wizard.hit)
        //     get_wizard(cub);
        put_screen(cub);
    }
    print_object(cub);
}
