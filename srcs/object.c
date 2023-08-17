/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:20:07 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 18:09:15 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_phrase(t_cub *cub, char *str)
{
	if (str)
		mlx_string_put(cub->mlx, cub->win, (SCREENW / 2) - \
		(ft_strlen(str) * 5), SCREENH / 2, \
	0xFFFFF, str);
	return (0);
}

int	press_f(t_cub *cub)
{
	if (cub->ray.hit)
	{
		if ((int)cub->player.posx == (int)(cub->door.x) && \
		((int)cub->player.posy == (int)cub->door.y + 1 \
		|| (int)cub->player.posy == (int)cub->door.y - 1))
		{
			cub->press_f = 1;
			return (1);
		}
		if ((int)cub->player.posy == (int)(cub->door.y) && \
		((int)cub->player.posx == (int)cub->door.x + 1 || \
		(int)cub->player.posx == (int)cub->door.x - 1))
		{
			cub->press_f = 1;
			return (1);
		}
	}
	cub->press_f = 0;
	return (0);
}

int	init_door(t_cub *cub)
{
	int	y;
	int	x;

	y = -1;
	cub->door.hp = 0;
	while (cub->map.iso_map[++y])
	{
		x = -1;
		while (cub->map.iso_map[y][++x])
		{
			if (cub->map.iso_map[y][x] == 'D')
			{
				cub->door.x = (double)(x);
				cub->door.y = (double)(y);
				cub->door.hp = 1;
				return (1);
			}
		}
	}
	cub->door.x = -1.0;
	return (0);
}

int	init_object(t_cub *cub)
{
	int	y;
	int	x;

	y = -1;
	init_door(cub);
	cub->wizard.hp = 0;
	while (cub->map.iso_map[++y])
	{
		x = -1;
		while (cub->map.iso_map[y][++x])
		{
			if (cub->map.iso_map[y][x] == 'Z')
			{
				cub->wizard.x = (double)(x + 0.5);
				cub->wizard.y = (double)(y + 0.5);
				cub->wizard.hp = 1;
				return (1);
			}
		}
	}
	cub->wizard.x = -1.0;
	return (0);
}
