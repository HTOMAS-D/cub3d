/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:41:09 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 16:41:39 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(int pX, int pY, int color)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < 20)
	{
		j = -1;
		while (++j < 20)
			my_mlx_pixel_put(&cub()->screen, pX + j, pY + i, color); 
	}
}
