/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:10:34 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/08 16:11:00 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_sprites(t_cub *cub)
{
	//printf("%s\n", cub->map.img_paths[1]);
	cub->wallNO.ptr = mlx_xpm_file_to_image(cub->mlx, cub->map.img_paths[0], &cub->wallNO.width, &cub->wallNO.height);
	cub->wallNO.addr = mlx_get_data_addr(cub->wallNO.ptr, &cub->wallNO.bpp, &cub->wallNO.size_line, &cub->wallNO.endian);
	cub->wallSO.ptr = mlx_xpm_file_to_image(cub->mlx, cub->map.img_paths[1], &cub->wallSO.width, &cub->wallSO.height);
	cub->wallSO.addr = mlx_get_data_addr(cub->wallSO.ptr, &cub->wallSO.bpp, &cub->wallSO.size_line, &cub->wallSO.endian);
	cub->wallWE.ptr = mlx_xpm_file_to_image(cub->mlx, cub->map.img_paths[2], &cub->wallWE.width, &cub->wallWE.height);
	cub->wallWE.addr = mlx_get_data_addr(cub->wallWE.ptr, &cub->wallWE.bpp, &cub->wallWE.size_line, &cub->wallWE.endian);
	cub->wallEA.ptr = mlx_xpm_file_to_image(cub->mlx, cub->map.img_paths[3], &cub->wallEA.width, &cub->wallEA.height);
	cub->wallEA.addr = mlx_get_data_addr(cub->wallEA.ptr, &cub->wallEA.bpp, &cub->wallEA.size_line, &cub->wallEA.endian);
	return (0);
}