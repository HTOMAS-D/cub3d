/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isolate_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:36:37 by htomas-d          #+#    #+#             */
/*   Updated: 2023/08/17 09:36:39 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	double_check(char *map)
{
	int	i;

	i = ft_lenstr(map);
	if (i < 4)
		return (1);
	if (map[i - 1] == 'm' && map[i - 2] == 'p'
		&& map[i - 3] == 'x' && map[i - 4] == '.'
		&& map[i - 5])
		return (0);
	return (1);
}

int	line_nbr(char **map)
{
	int	i;

	i = -1;
	while (map && map[++i])
		;
	return (i);
}

void	isolate_map(t_map *map)
{
	int	i;
	int	count;
	int	j;

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
	j = -1;
	while (map->img_paths[++j])
	{
		if (double_check(map->img_paths[j]))
			parse_exit(map, "file not a .xpm");
	}
}
