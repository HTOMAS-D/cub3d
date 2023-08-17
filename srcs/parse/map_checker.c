/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:29:04 by htomas-d          #+#    #+#             */
/*   Updated: 2023/08/17 09:30:41 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	letters_check(t_data *data)
{
	if (data->no != 1 || data->so != 1 || data->we != 1 || data->ea != 1)
		return (1);
	else
		return (0);
}

int	check_path_letters(char *str)
{
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
	{
		cub()->map.data.no++;
		return (0);
	}
	else if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
	{
		cub()->map.data.so++;
		return (0);
	}
	else if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
	{
		cub()->map.data.we++;
		return (0);
	}
	else if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
	{
		cub()->map.data.ea++;
		return (0);
	}
	else
		return (1);
}

void	get_files(t_map *map)
{
	int	i;
	int	fd;

	i = -1;
	while (map->map[++i] && i < 4)
	{
		if (map->map[i][0] == 'N')
			map->img_paths[0] = ft_strdup(&map->map[i][3]);
		else if (map->map[i][0] == 'S')
			map->img_paths[1] = ft_strdup(&map->map[i][3]);
		else if (map->map[i][0] == 'W')
			map->img_paths[2] = ft_strdup(&map->map[i][3]);
		else if (map->map[i][0] == 'E')
			map->img_paths[3] = ft_strdup(&map->map[i][3]);
		fd = open(&map->map[i][3], O_RDONLY);
		if (fd == -1)
			parse_exit(map, "Cannot open image");
		else
			close(fd);
	}
}

void	get_img(t_map *map)
{
	int	i;

	i = -1;
	map->img_paths = calloc (sizeof (char *), 5);
	if (!map->img_paths)
		parse_exit(map, "failed to alloc image paths");
	map->img_paths[4] = NULL;
	while (map->map[++i] && i < 4)
	{
		if (check_path_letters(map->map[i]))
			parse_exit(map, "wrong identifier");
	}
	if (letters_check(&(map->data)))
		parse_exit(map, "Missing identifiers");
	get_files(map);
}

void	check_map(t_map *map)
{
	map->data.no = 0;
	map->data.so = 0;
	map->data.we = 0;
	map->data.ea = 0;
	map->data.f = 0;
	map->data.C = 0;
	get_img(map);
	get_colors(map);
	isolate_map(map);
	check_walls(map);
	get_player_vars(map->iso_map);
}
