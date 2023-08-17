/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:04:21 by htomas-d          #+#    #+#             */
/*   Updated: 2023/08/17 16:12:46 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ez_exit(char *str)
{
	printf("%s%s\n", RED, str);
	exit(1);
}

void	parse_exit(t_map *map, char *str)
{
	if (map)
	{
		if (map->map)
			free_matrix(&(map->map));
		map->map = NULL;
	}
	free_exit(cub(), str);
}

void	free_exit(t_cub *cub, char *str)
{
	if (cub->map.map)
		free_matrix(&(cub->map.map));
	if (cub->map.img_paths)
		free_matrix(&(cub->map.img_paths));
	if (cub->map.iso_map)
		free_matrix(&(cub->map.iso_map));
	if (cub->zbuffer)
		free(cub->zbuffer);
	free_mlx(cub);
	ez_exit(str);
}
