#include "cub3d.h"

int letters_check(t_data *data)
{
	if (data->NO != 1 || data->SO != 1 || data->WE != 1 || data->EA != 1)
		return 1;
	else
		return 0;
}

int check_path_letters(char *str)
{
	if(str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
	{
		cub()->map.data.NO++;
		return 0;
	}
	else if(str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
	{
		cub()->map.data.SO++;
		return 0;
	}
	else if(str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
	{
		cub()->map.data.WE++;
		return 0;
	}
	else if(str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
	{
		cub()->map.data.EA++;
		return 0;
	}
	else
		return 1;
}

void get_img(t_map *map)
{
	int i;
	// int fd;

	i = -1;
	map->img_paths = calloc(sizeof(char*), 5);
	if (!map->img_paths)
		parse_exit(map, "failed to alloc image paths");
	map->img_paths[4] = NULL;
	while(map->map[++i] && i < 4)
	{
		if(check_path_letters(map->map[i]))
			parse_exit(map, "wrong identifier");
	}
	if (letters_check(&(map->data)))
		parse_exit(map, "Missing identifiers");
	i = -1;
	// while(map->map[++i] && i < 4)
	// {
	// 	map->img_paths[i] = ft_strdup(&map->map[i][3]);
	// 	fd = open(map->img_paths[i], O_RDONLY);
	// 	if (fd == -1)
	// 		parse_exit(map, "Cannot open image");
	// 	else
	// 		close(fd);
	// }
}

void check_map(t_map *map)
{
	map->data.NO = 0;
	map->data.SO = 0;
	map->data.WE = 0;
	map->data.EA = 0;
	map->data.F = 0;
	map->data.C = 0;
	get_img(map);
	get_colors(map);
	isolate_map(map);
	get_player_vars(map); //inside the player.c will be readung the iso_map to get player starting vars
}