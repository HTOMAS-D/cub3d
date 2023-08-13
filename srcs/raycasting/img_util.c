#include "cub3d.h"

int treat_var_get_color(int var, int start, int max)
{
	double size;

	size = cub()->screen.text_end - cub()->screen.text_start;
	size /= max;
	var -= start;
	var /= size;
	return (var);
}

int	get_color(int x, int y, int size)
{
	char	*dst;
	t_image	*img;

	if (cub()->ray.wallside == 1) //EA
		img = &cub()->wallEA;
	else if (cub()->ray.wallside == 2) //SO
		img = &cub()->wallSO;
	else if (cub()->ray.wallside == 3) //WE
		img = &cub()->wallWE;
	else if (cub()->ray.wallside == 0)// NO
		img = &cub()->wallNO;
	else
		img = &cub()->wizard.animation.img;
	y = treat_var_get_color(y, cub()->screen.text_start, size);
	if (y >= size)
		y = size - 1;
	if (cub()->ray.wallside == -1)
		x = (int)(cub()->wizard.wizardx * size) + (size * cub()->wizard.animation.frame);
	else
		x = (int)(cub()->ray.wallx * size);
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	return (*(unsigned int *) dst);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (color == TRANSPARENT)
		return ;
	dst = (image->addr + (y * image->size_line + x * (image->bpp / 8)));
	*(unsigned int *)dst = color;
}