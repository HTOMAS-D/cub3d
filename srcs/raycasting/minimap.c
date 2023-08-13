#include "cub3d.h"

// # define MM_W				250
// # define MM_H				250

void get_player(t_cub * cub)
{
    // int playerX = (MM_W / 2) - 10;
    // int playerY = (MM_H / 2) - 10;
    int i = -1;
    int j = -1;
    while(++i <= 10)
    {
        while (++j <=10)
        {
            my_mlx_pixel_put(&cub->screen, (MM_W / 2) + (j + 5), (MM_W / 2) + i, 0xeb1b0c); 
        }
        my_mlx_pixel_put(&cub->screen, MM_W / 2, (MM_W / 2) + (i+5), 0xeb1b0c); 
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

    (void) map;
    get_borders(cub);
    get_player(cub);
}
