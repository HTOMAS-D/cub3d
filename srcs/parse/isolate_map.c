#include "cub3d.h"

int line_nbr(char **map)
{
	int i;

	i = -1;
	while(map && map[++i])
		;
	return i;
}

void isolate_map(t_map *map)
{
	int i;
	int count;
	int j;

	j = -1;
	count = line_nbr(&(map->map[8]));
	map->mapHeight = count;
	map->iso_map = malloc(sizeof(char *) * (count + 1));
	if (!map->iso_map)
		parse_exit(map, "failed to alloc iso_map");
	map->iso_map[count] = NULL;
	i = 7;
	while (map && map->map[++i])
		map->iso_map[++j] = ft_strdup(map->map[i]);
}