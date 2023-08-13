#include "cub3d.h"

void init_player_vars(t_cub *cub)
{
	cub->player.fovX = 0;
	cub->player.fovY = 0;
	cub->player.dirX = 0;
	cub->player.dirY = 0;
	printf("%c\n", cub->player.orientation);
	 if (cub->player.orientation == 'N')
    {
        cub->player.dirY = -1;
        cub->player.fovX = 0.66;
    }
    else if (cub->player.orientation == 'S')
    {
        cub->player.dirY = 1;
        cub->player.fovX = -0.66;
    }
    else if (cub->player.orientation == 'E')
    {
        cub->player.dirX = 1;
        cub->player.fovY = 0.66;
    }
    else if (cub->player.orientation == 'W')
    {
        cub->player.dirX = -1;
        cub->player.fovY = -0.66;
    }
}

void add_vars(int x, int y, char **map) //is this *static void* ?
{
	cub()->player.posX = x + 0.5; // + 0.5
	cub()->player.posY = y+ 0.5; // + 0.5
	cub()->numb_players++;
	cub()->player.orientation = map[y][x];
	map[y][x] = '0';
}

void get_player_vars(char **map)
{
	int x;
	int y;

	y = -1;
	while(map[++y])
	{
		x = -1;
		printf("%s\n", map[y]);
		while(map[y][++x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' ||
				map[y][x] == 'W')
				add_vars(x, y, map);
			else if (!(map[y][x] == '1' || map[y][x] == '0' || map[y][x] == ' ' || map[y][x] == 'Z'))
				free_exit(cub(), "Invalid character on map file");
		}
	}
	printf("player posX: %f\n", cub()->player.posX);
	printf("player posY: %f\n", cub()->player.posY);
	printf("player orientation: %c\n", cub()->player.orientation);
	printf("number of players: %d\n", cub()->numb_players);
	printf("map player position: %c\n", map[(int)cub()->player.posY][(int)cub()->player.posX]);
	if (cub()->numb_players != 1)
		free_exit(cub(), "Number of players is not 1");
	// map[(int)cub()->player.posY][(int)cub()->player.posX] = cub()->player.orientation;
}

