#include "cub3d.h"

int render(t_cub* cub) // gaming loop 1-UPDATE GAME (RAYCASTING AND MOVING) 2- RENDER
{
	unsigned long	time;

	if (!cub->n_renders)
		gettimeofday(&cub->old_time, NULL);
	cub->n_renders++;
	gettimeofday(&cub->new_time, NULL);
	time = (cub->new_time.tv_sec - cub->old_time.tv_sec);
	raycaster(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->screen.ptr, 0, 0);
	if (cub->fps_str)
		mlx_string_put(cub->mlx, cub->win, 32, 36, \
	0xFFFFF, cub->fps_str);
	if (time)
	{
		free(cub->fps_str);
		cub->fps_str = ft_itoa(cub->n_renders);
		cub->n_renders = 0;
	}
	return (0);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = (image->addr + (y * image->size_line + x * (image->bpp / 8)));
	*(unsigned int *)dst = color;
	// int	x_i;
	// int	y_i;

	// x_i = x;
	// y_i = y;
	// if (x_i >= 0 && x_i < SCREENW && \
	// 	y_i >= 0 && y_i < SCREENW)
	// 	(*(unsigned int*)(image->addr + ((y_i * image > size_line) \
	// 	+ (x_i * (data->bpp / 8))))) = color;

}