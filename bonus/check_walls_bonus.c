/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:53:47 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/16 12:51:17 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_square(t_map *map, int i, int j)
{
	int	res;

	res = 0;
	if (i == 0 || j == 0 || !map->iso_map[i][j + 1] || !map->iso_map[i + 1])
		res++;
	else
	{
		if (i > 0 && (map->iso_map[i - 1][j] == ' ' || \
		map->iso_map[i - 1][j + 1] == ' '))
			res++;
		if (j > 0 && (map->iso_map[i][j - 1] == ' ' || \
		map->iso_map[i + 1][j - 1] == ' '))
			res++;
		if (j > 0 && i > 0 && (map->iso_map[i - 1][j - 1] == ' '))
			res++;
		if ((map->iso_map[i + 1] && (map->iso_map[i + 1][j + 1] == ' ' \
		|| map->iso_map[i + 1][j] == ' ')) || map->iso_map[i][j + 1] == ' ')
			res++;
	}
	if (res)
		parse_exit(map, "Map needs to be surrounded by walls");
	return (res);
}

int	check_door(t_map *map, int y, int x)
{
	if (map->iso_map[y][x + 1] == '1' && map->iso_map[y][x - 1] == '1')
	{
		if (map->iso_map[y + 1][x] != '1' && map->iso_map[y - 1][x] != '1')
			return (0);
	}
	if (map->iso_map[y + 1][x] == '1' && map->iso_map[y - 1][x] == '1')
	{
		if (map->iso_map[y][x + 1] != '1' && map->iso_map[y][x - 1] != '1')
			return (0);
	}
	parse_exit(map, "Cannot place door here");
	return (1);
}

int	check_doors(t_map *map)
{
	int	y;
	int	x;
	int	hmany;

	y = -1;
	hmany = 0;
	while (map->iso_map[++y])
	{
		x = -1;
		while (map->iso_map[y][++x])
		{
			if (map->iso_map[y][x] == 'D' && ++hmany)
				check_door(map, y, x);
		}
	}
	if (hmany > 1)
		parse_exit(map, "This game only handles one door");
	return (0);
}

int	check_walls(t_map *map)
{
	int	i;
	int	j;
	int	wizard;

	i = -1;
	wizard = 0;
	while (map->iso_map[++i])
	{
		j = -1;
		while (map->iso_map[i][++j])
		{
			if (map->iso_map[i][j] != ' ' && map->iso_map[i][j] != '1')
				check_square(map, i, j);
			if (map->iso_map[i][j] == 'Z')
				wizard++;
		}
	}
	if (wizard > 1)
		parse_exit(map, "Can only be one wizard");
	check_doors(map);
	return (0);
}
