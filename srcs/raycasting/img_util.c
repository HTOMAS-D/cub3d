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

int check_color(int x, int y, int size, t_image *img)
{
	char *dst;

	x = (int)(cub()->door.ray.wallx * size);
	y = treat_var_get_color(y, cub()->screen.text_start, size);
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	if (*(unsigned int *) dst == TRANSPARENT)
		return (0);
	return (1);
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
	else if (cub()->ray.wallside == -1) //wizard
		img = &cub()->wizard.animation.img;
	else // door
		img = &cub()->door.animation.img;
	if (cub()->ray.wallside == -1)
	{
		x = (int)(cub()->wizard.printx) + (size * cub()->wizard.animation.frame);
		y = (int)(cub()->wizard.printy);
	}
	else if (cub()->ray.wallside == - 2)
	{
		x = (int)((cub()->door.ray.wallx * size) + (size * cub()->door.animation.frame));
		y = treat_var_get_color(y, cub()->screen.text_start, size);
	}
	else
	{
		y = treat_var_get_color(y, cub()->screen.text_start, size);
		x = (int)(cub()->ray.wallx * size);
	}
	if (y >= size)
		y = size - 1;
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