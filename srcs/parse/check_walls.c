/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:53:47 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/02 18:53:32 by mtiago-s         ###   ########.fr       */
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

int	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->iso_map[++i])
	{
		j = -1;
		while (map->iso_map[i][++j])
		{
			if (map->iso_map[i][j] != ' ' && map->iso_map[i][j] != '1')
				check_square(map, i, j);
		}
	}
	return (0);
}