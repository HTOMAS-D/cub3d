#include "cub3d.h"

// # define MM_W				250
// # define MM_H				250


// struct s_player
// {
// 	double posX;
// 	double posY;
// 	double	dirY;
// 	double	dirX;
// 	double	fovX;
// 	double	fovY;
// 	char	orientation;
// 	struct s_move	move;
// };

void get_map_around(t_cub *cub, char **map)
{
    
}

void get_player(t_cub * cub)
{
    int i;
    int j;
    int startX;
    int startY;
    i = -1;
    startX = 10 + (MM_W / 2) - 5;
    startY = 10 + (MM_H / 2) - 5;
    while (++i <= 10)
    {
        j = -1;
        while (++j <= 10)
            my_mlx_pixel_put(&cub->screen, startX + j, startY + i, 0xeb1b0c); 
    }
}

void get_borders(t_cub * cub)
{
    int i;
    int j;

    i = -1;
    j = -1;
    while (++i <= MM_W)
    {
        if (i == 0 || i == MM_W)
        {    
            while(++j <= MM_H)
                my_mlx_pixel_put(&cub->screen, j+10, i + 10, 0x050303);
            j = -1;
        }
        my_mlx_pixel_put(&cub->screen, 10, i+10, 0x050303);
        my_mlx_pixel_put(&cub->screen, MM_W + 10, i+10, 0x050303);
    }

}

void minimap(t_cub *cub, char **map)
{
    get_borders(cub);
    get_map_around(cub, map);
    get_player(cub);
}
