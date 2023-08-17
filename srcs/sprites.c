/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:10:34 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 18:22:56 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	load_image(char *path)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(cub()->mlx, path, &img.width, &img.height);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, \
	&img.endian);
	return (img);
}

int	init_sprites(t_cub *cub)
{
	cub->wallno = load_image(cub->map.img_paths[0]);
	cub->wallso = load_image(cub->map.img_paths[1]);
	cub->wallwe = load_image(cub->map.img_paths[2]);
	cub->wallea = load_image(cub->map.img_paths[3]);
	return (0);
}
