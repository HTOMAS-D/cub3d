#include "cub3d.h"

void add_vars(int x, int y, char **map) //is this *static void* ?
{
	cub()->player.posX = x;
	cub()->player.posY = y;
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
			else if (!(map[y][x] == '1' || map[y][x] == '0' || map[y][x] == ' '))
				free_exit(cub(), "Invalid character on map file");
		}
	}
	// printf("player posX: %f\n", cub()->player.posX);
	// printf("player posY: %f\n", cub()->player.posY);
	// printf("player orientation: %c\n", cub()->player.orientation);
	// printf("number of players: %d\n", cub()->numb_players);
	// printf("map player position: %c\n", map[(int)cub()->player.posY][(int)cub()->player.posX]);
	if (cub()->numb_players != 1)
		free_exit(cub(), "Number of players is not 1");
	// map[(int)cub()->player.posY][(int)cub()->player.posX] = cub()->player.orientation;
}