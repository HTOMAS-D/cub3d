#include "cub3d.h"

t_cub *cub()
{
	static t_cub cub;
	return(&cub);
}

void create_game(t_cub *cub)
{
	cub->mlx = mlx_init();
	if(!cub->mlx)
		free_exit(cub, "mlx_init didnt work");
	cub->win = mlx_new_window(cub->mlx, SCREENW, SCREENH, "cub3d");
	if (!cub->win)
		free_exit(cub, "mlx_new_window failed");
	// mlx_mouse_hide(cub->mlx, cub->win);
	// get_player(cub);
	init_player_vars(cub);
	// raycaster(cub);
	mlx_loop(cub->mlx);
}

int main(int ac, char **av)
{
	check_file(cub(), ac, av);
	create_game(cub());
	free_stuff(cub());
}