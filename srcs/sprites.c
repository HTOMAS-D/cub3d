/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:10:34 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/07/18 16:05:15 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_sprites(t_cub *cub)
{
	//printf("%s\n", cub->map.img_paths[1]);
	cub->wall.ptr = mlx_xpm_file_to_image(cub->mlx, "./pics/wood.xpm", &cub->wall.width, &cub->wall.height);
	cub->wall.addr = mlx_get_data_addr(cub->wall.ptr, &cub->wall.bpp, &cub->wall.size_line, &cub->wall.endian);
	return (0);
}