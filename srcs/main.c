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
	//mlx_mouse_hide();
	//init_sprites(cub);
	init_player_vars(cub);
	mlx_hook(cub->win, MOUSE_MOVE, 1L << 6, move_mouse, cub); //SHITS NOT WORKING 1L << 6
	cub->fps_str = NULL;
	mlx_hook(cub->win, EXIT_KEY, 0, close_game, cub);
	mlx_hook(cub->win, KEY_PRESS, 1l << 0, get_key, cub);
	mlx_hook(cub->win, KEY_RELEASE, 1L << 1, key_release, cub);
	mlx_loop_hook(cub->mlx, &game_loop, cub);
	mlx_loop(cub->mlx);
}

int main(int ac, char **av)
{
	check_file(cub(), ac, av);
	create_game(cub());
	free_stuff(cub());
}