/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:20:52 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 17:36:09 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map_around_loop(int map_pos_y, char **map, int m_y)
{
	int	m_x;
	int	map_pos_x;

	m_x = (int)cub()->player.posX - 6;
	map_pos_x = 10;
	while (m_x <= (int)cub()->player.posX + 5)
	{
		if (m_x >= 0 && m_x < ft_lenstr(map[m_y]) \
		&& map[m_y][m_x] == '1')
			draw_square(map_pos_x, map_pos_y, 0x21212b);
		else if (m_x >= 0 && m_x < ft_lenstr(map[m_y]) \
		&& map[m_y][m_x] == 'Z')
			draw_square(map_pos_x, map_pos_y, 0xeb1b0c);
		else if (m_x >= 0 && m_x < ft_lenstr(map[m_y]) \
		&& map[m_y][m_x] == 'D' && cub()->door.hp)
			draw_square(map_pos_x, map_pos_y, 0xABABAB);
		else if (m_x >= 0 && m_x < ft_lenstr(map[m_y]) \
		&& map[m_y][m_x] == 'D')
			draw_square(map_pos_x, map_pos_y, 0xEAEAEA);
		else if (m_x >= 0 && m_x < ft_lenstr(map[m_y]))
			draw_square(map_pos_x, map_pos_y, 0xffffff);
		map_pos_x += 18; 
		m_x++;
	}
}

void	get_map_around(t_cub *cub, char **map)
{
	int	m_y;
	int	map_pos_y;

	m_y = (int)cub->player.posY - 6;
	map_pos_y = 10;
	while (m_y <= (int)cub->player.posY + 5 && m_y < cub->map.mapHeight)
	{
		if (m_y >= 0)
			get_map_around_loop(map_pos_y, map, m_y);
		map_pos_y += 18; 
		m_y++;
	}
}

void	get_player(t_cub *cub)
{
	int	i;
	int	j;
	int	start_x;
	int	start_y;

	i = -1;
	start_x = 10 + (MM_W / 2) - 11;
	start_y = 10 + (MM_H / 2) - 11;
	while (++i < 16)
	{
		j = -1;
		while (++j < 16)
			my_mlx_pixel_put(&cub->screen, start_x + j, start_y + i, 0x2ED030); 
	}
}

void	get_borders(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i <= MM_W - 22)
	{
		if (i == 0 || i == MM_W - 22)
		{
			while (++j <= MM_H - 22) 
				my_mlx_pixel_put(&cub->screen, j + 10, i + 10, 0x050303);
			j = -1;
		}
		my_mlx_pixel_put(&cub->screen, 10, i + 10, 0x050303);
		my_mlx_pixel_put(&cub->screen, MM_W - 22 + 10, i + 10, 0x050303); 
	}
}

void	minimap(t_cub *cub, char **map)
{
	(void) map;
	get_borders(cub);
	get_map_around(cub, map);
	get_player(cub);
}
