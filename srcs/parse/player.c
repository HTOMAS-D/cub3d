#include "cub3d.h"

void add_vars()
{
	
}

void get_player_vars(char **map)
{
	int i;
	int j;

	j = -1;
	while(map[++j])
	{
		i = -1;
		while(map[j][++i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'E' ||
				map[j][i] == 'W')
				add_vars();
			else if (map[j][i] != '1' || map[j][i] != '0')
				free_exit(cub(), "Invalid character on map file");
		}
	}
}