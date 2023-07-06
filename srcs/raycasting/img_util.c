#include "cub3d.h"

void render(t_cub* cub)
{
	mlx_do_sync(cub->mlx);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->screen.ptr, 0, 0);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = (image->addr + (y * image->size_line + x * (image->bpp / 8)));
	*(unsigned int *)dst = color;
}