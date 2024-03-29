/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:15:27 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 18:33:39 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	treat_var_get_color(int var, int start, int max)
{
	double	size;

	size = cub()->screen.text_end - cub()->screen.text_start;
	size /= max;
	var -= start;
	var /= size;
	return (var);
}

void	get_color_choose_img(t_image **img)
{
	if (cub()->ray.wallside == 1)
		*img = &cub()->wallea;
	else if (cub()->ray.wallside == 2)
		*img = &cub()->wallso;
	else if (cub()->ray.wallside == 3)
		*img = &cub()->wallwe;
	else if (cub()->ray.wallside == 0)
		*img = &cub()->wallno;
}

int	get_color(int x, int y, int size)
{
	char	*dst;
	t_image	*img;

	get_color_choose_img(&img);
	y = treat_var_get_color(y, cub()->screen.text_start, size);
	x = (int)(cub()->ray.wallx * size);
	if (y >= size)
		y = size - 1;
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	return (*(unsigned int *) dst);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = (image->addr + (y * image->size_line + x * (image->bpp / 8)));
	*(unsigned int *)dst = color;
}
