/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:48:17 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 21:35:10 by mtiago-s         ###   ########.fr       */
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

	i = 0;
	if (!*matrix)
		return ;
	ptr = *matrix;
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
		mlx_destroy_image(cub->mlx, cub->screen.ptr);
		mlx_destroy_image(cub->mlx, cub->wallwe.ptr);
		mlx_destroy_image(cub->mlx, cub->wallso.ptr);
		mlx_destroy_image(cub->mlx, cub->wallno.ptr);
		mlx_destroy_image(cub->mlx, cub->wallea.ptr);
		mlx_destroy_image(cub->mlx, cub->wizard.animation.img.ptr);
		mlx_destroy_image(cub->mlx, cub->door.animation.img.ptr);
		mlx_clear_window(cub->mlx, cub->win);
		mlx_destroy_window(cub->mlx, cub->win);
		mlx_destroy_display(cub->mlx);
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
	if (cub->map.color_str)
	{
		free_matrix(&(cub->map.color_str));
		cub->map.color_str = NULL;
	}
	if (cub->zbuffer)
		free(cub->zbuffer);
}
