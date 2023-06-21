#include "cub3d.h"

t_cub *cub()
{
	static t_cub cub;
	return(&cub);
}

void create_game(t_cub *cub)
{
	cub->mlx = mlx_init();
}

int main(int ac, char **av)
{
	check_file(cub(), ac, av);
	// free_stuff(cub());
	create_game(cub());
}