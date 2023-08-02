/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:53:52 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/07/31 15:59:58 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fps_counter(t_cub *cub)
{
	unsigned long	time;

	if (!cub->n_renders)
		gettimeofday(&cub->old_time, NULL);
	gettimeofday(&cub->new_time, NULL);
	time = (cub->new_time.tv_sec - cub->old_time.tv_sec);
	if (cub->fps_str)
		mlx_string_put(cub->mlx, cub->win, 32, 36, \
	0xFFFFF, cub->fps_str);
	if (time)
	{
		free(cub->fps_str);
		cub->fps_str = ft_itoa(cub->n_renders);
		gettimeofday(&cub->old_time, NULL);
		cub->n_renders = 0;
	}
	return (0);
}
