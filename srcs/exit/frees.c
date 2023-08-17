/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:04:32 by htomas-d          #+#    #+#             */
/*   Updated: 2023/08/17 10:04:34 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char *str)
{
	if (!str)
		return ;
	free(str);
	str = NULL;
}

void	free_matrix(char ***matrix)
{
	char	**ptr;
	int		i;

	if (!*matrix)
		return ;
	ptr = *matrix;
	i = 0;
	while (ptr && ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	*matrix = NULL;
}

void	free_mlx(t_cub *cub)
{
	if (cub->mlx != NULL)
	{
		mlx_destroy_window(cub->mlx, cub->win);
		free(cub->mlx);
		cub->mlx = NULL;
		cub->win = NULL;
	}
}

void	free_stuff(t_cub *cub)
{
	if (cub->map.map)
	{
		free_matrix(&(cub->map.map));
		cub->map.map = NULL;
	}
	if (cub->map.img_paths)
	{
		free_matrix(&(cub->map.img_paths));
		cub->map.img_paths = NULL;
	}
	if (cub->map.iso_map)
	{
		free_matrix(&(cub->map.iso_map));
		cub->map.iso_map = NULL;
	}
	if (cub->fps_str)
		free(cub->fps_str);
}
