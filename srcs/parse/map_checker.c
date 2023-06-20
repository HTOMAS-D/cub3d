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
	{
		// printf("NO: %d\n", cub()->map.data.NO);
		// printf("SO: %d\n", cub()->map.data.SO);
		// printf("WE: %d\n", cub()->map.data.WE);
		// printf("EA: %d\n", cub()->map.data.EA);
		return 1;
	}
	
}

void get_img(t_map *map)
{
	// make a image struct (maybe?) to store each path to images, call the free stuff function if it fails to allocate
	// the strings to store the paths.
	int i;
	// int j;

	i = -1;
	map->img_paths = calloc(sizeof(char*), 5);
	if (!map->img_paths)
		parse_exit(map, "failed to alloc image paths");
	map->img_paths[4] = NULL;
	while(map->map[++i] && i < 4)
	{
		if(check_path_letters(map->map[i]))
			parse_exit(map, "wrong identifier");
		printf("NO: %d\n", map->data.NO);
		printf("SO: %d\n", map->data.SO);
		printf("WE: %d\n", map->data.WE);
		printf("EA: %d\n\n", map->data.EA);
	}
	if (letters_check(&(map->data)))
		parse_exit(map, "Missing identifiers");
	
}

void check_map(t_map *map)
{
	map->data.NO = 0;
	map->data.SO = 0;
	map->data.WE = 0;
	map->data.EA = 0;
	get_img(map);
}