#include "cub3d.h"

void check_file(t_cub *cub, int ac, char **av)
{
	if (ac != 2)
		ez_exit("Wrong number of arguments\nTry ./cub3d *map*");
}