#include "cub3d.h"

void draw_square(t_cub *cub, int pX, int pY, int color)
{
    int i = -1;
    int j = -1;
    while(++i < 20)
    {
        j = -1;
        while(++j < 20)
            my_mlx_pixel_put(&cub->screen, pX + j, pY + i, color); 
    }
}


void get_map_around(t_cub *cub, char **map)
{
    int mY = (int)cub->player.posY - 6;
    int mX;
    int mapPosY = 10;
    int mapPosX;

    while (mY <= (int)cub->player.posY + 5 && mY < cub->map.mapHeight)
    {
        if (mY >= 0)
        {
            mX = (int)cub->player.posX - 6;
            mapPosX = 10;

            while (mX <= (int)cub->player.posX + 5)
            {
                if (mX >= 0 && mX < ft_lenstr(map[mY]) && map[mY][mX] == '1')
                    draw_square(cub, mapPosX, mapPosY, 0x21212b);
                mapPosX += 18; 
                mX++;
            }
        }
        mapPosY += 18; 
        mY++;
    }
}


void get_player(t_cub * cub)
{
    int i;
    int j;
    int startX;
    int startY;
    i = -1;
    startX = 10 + (MM_W / 2) - 10;
    startY = 10 + (MM_H / 2) - 10;
    while (++i < 17)
    {
        j = -1;
        while (++j < 17)
            my_mlx_pixel_put(&cub->screen, startX + j, startY + i, 0xeb1b0c); 
    }
}
void get_borders(t_cub *cub)
{
    int i;
    int j;

    i = -1;
    j = -1;
    while (++i <= MM_W - 22)
    {
        if (i == 0 || i == MM_W - 22)
        {    
            while (++j <= MM_H - 22) 
                my_mlx_pixel_put(&cub->screen, j + 10, i + 10, 0x050303);
            j = -1;
        }
        my_mlx_pixel_put(&cub->screen, 10, i + 10, 0x050303);
        my_mlx_pixel_put(&cub->screen, MM_W - 22 + 10, i + 10, 0x050303); 
    }
}



void minimap(t_cub *cub, char **map)
{
    (void) map;
    get_borders(cub);
    get_map_around(cub, map);
    get_player(cub);
}
