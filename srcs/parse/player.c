/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:40:55 by htomas-d          #+#    #+#             */
/*   Updated: 2023/08/17 09:40:57 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player_vars(t_cub *cub)
{
	cub->player.fovx = 0;
	cub->player.fovy = 0;
	cub->player.dirx = 0;
	cub->player.diry = 0;
	if (cub->player.orientation == 'N')
	{
		cub->player.diry = -1;
		cub->player.fovx = 0.66;
	}
	else if (cub->player.orientation == 'S')
	{
		cub->player.diry = 1;
		cub->player.fovx = -0.66;
	}
	else if (cub->player.orientation == 'E')
	{
		cub->player.dirx = 1;
		cub->player.fovy = 0.66;
	}
	else if (cub->player.orientation == 'W')
	{
		cub->player.dirx = -1;
		cub->player.fovy = -0.66;
	}
}

void	add_vars(int x, int y, char **map)
{
	cub()->player.posx = x + 0.5;
	cub()->player.posy = y + 0.5;
	cub()->numb_players++;
	cub()->player.orientation = map[y][x];
	map[y][x] = '0';
}

void	get_player_vars(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' ||
				map[y][x] == 'W')
				add_vars(x, y, map);
			else if (!(map[y][x] == '1' || map[y][x] == '0' ||
				map[y][x] == ' ' || map[y][x] == 'Z' || map[y][x] == 'D'))
				free_exit(cub(), "Invalid character on map file");
		}
	}
	if (cub()->numb_players != 1)
		free_exit(cub(), "Number of players is not 1");
}
