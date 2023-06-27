#include "cub3d.h"

int all_color(t_data *data)
{
	if (data->F != 1 || data->C != 1)
		return 1;
	else
		return 0;
}

int check_color_letters(char *str)
{
	if (str[0] == 'F' && str[1] == ' ')
	{
		cub()->map.data.F++;
		return 0;
	}
	else if (str[0] == 'C' && str[1] == ' ')
	{
		cub()->map.data.C++;
		return 0;
	}
	else
		return 1;	
}

void get_colors(t_map *map)
{
	int i;
	int j;

	i = 4;
	j = -1;
	map->color_str = calloc(sizeof(char *), 3);
	if(!map->color_str)
		parse_exit(map, "failed to alloc color strings");
	map->color_str[3] = NULL;
	while(map->map[++i] && i < 7)
	{
		if(check_color_letters(map->map[i]))
			parse_exit(map, "Wrong identifier");
	}
	if (all_color(&(map->data)))
		parse_exit(map, "Missing identifier");
	i = 4;
	while(map->map[++i] && i < 7)
		map->color_str[++j] = ft_strdup(&map->map[i][2]);
}

