#include "cub3d.h"

int	update_player(t_cub *cub)
{
	if (cub->player.move.w)
		move_w(cub);
	if (cub->player.move.s)
		move_s(cub);
	if (cub->player.move.a)
		move_a(cub);
	if (cub->player.move.d)
		move_d(cub);
	if ((cub->player.move.jump && cub->horizon == SCREENH / 2) || (cub->player.move.jump && cub->player.move.jump != JUMP_HEIGHT))
		jump(cub);
	if (cub->horizon != SCREENH / 2 && !cub->player.move.jump)
	{
		cub->horizon -= (int)cub->player.move.gravity;
		cub->player.move.gravity += GRAVITY_FORCE;
		if (cub->player.move.gravity >= MAX_GRAV)
			cub->player.move.gravity = MAX_GRAV;
		if (cub->horizon < SCREENH / 2)
			cub->horizon = SCREENH / 2;
	}
	if (cub->horizon == SCREENH / 2)
		cub->player.move.gravity = 0;
	return (0);
}

int	render(t_cub *cub)
{
	unsigned long	time;

	if (!cub->n_renders)
		gettimeofday(&cub->old_time, NULL);
	cub->n_renders++;
	gettimeofday(&cub->new_time, NULL);
	time = (cub->new_time.tv_sec - cub->old_time.tv_sec);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->screen.ptr, 0, 0);
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

int	update_game(t_cub *cub)
{
	update_player(cub);
	raycaster(cub);
	return (0);
}

int game_loop(t_cub* cub) // gaming loop 1-UPDATE GAME (RAYCASTING AND MOVING) 2- RENDER
{
	update_game(cub);
	render(cub);
	return (0);
}

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
	return (*(unsigned int *) dst);
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