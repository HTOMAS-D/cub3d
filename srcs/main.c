#include "cub3d.h"

t_cub *cub()
{
	static t_cub cub;
	return(&cub);
}

void init_screen (t_cub *cub)
{
	cub->screen.ptr = mlx_new_image(cub->mlx, SCREENW, SCREENH);
	cub->screen.addr = mlx_get_data_addr(cub->screen.ptr, &cub->screen.bpp, &cub->screen.size_line, &cub->screen.endian);
}

void create_game(t_cub *cub)
{
	cub->mlx = mlx_init();
	if(!cub->mlx)
		free_exit(cub, "mlx_init didnt work");
	init_screen(cub);
	cub->win = mlx_new_window(cub->mlx, SCREENW, SCREENH, "cub3d");
	if (!cub->win)
		free_exit(cub, "mlx_new_window failed");
	
	// mlx_mouse_hide(cub->mlx, cub->win);
	init_player_vars(cub);
	raycaster(cub);
	mlx_hook(cub->win, 17, 0, close_game, cub);
	mlx_loop(cub->mlx);
}

int main(int ac, char **av)
{
	check_file(cub(), ac, av);
	create_game(cub());
	free_stuff(cub());
}