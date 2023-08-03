#include "cub3d.h"

int treat_var_get_color(int var, int start)
{
	double size;

	size = cub()->screen.text_end - cub()->screen.text_start;
	size /= 64;
	var -= start;
	var /= size;
	return (var);
}

int	get_color(t_image *img, int x, int y)
{
	char	*dst;

	y = treat_var_get_color(y, cub()->screen.text_start);
	if (y >= 64)
		y = 63;
	x = (int)(cub()->ray.wallx * 64);
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	if (cub()->ray.side)
		return (*(unsigned int *) dst / 2);
	return (*(unsigned int *) dst);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = (image->addr + (y * image->size_line + x * (image->bpp / 8)));
	*(unsigned int *)dst = color;
}