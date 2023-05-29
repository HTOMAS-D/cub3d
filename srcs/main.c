#include "cub3d.h"

t_cub *cub()
{
	static t_cub cub;
	return(&cub);

}

int main(int ac, char **av)
{
	(void) av;
	check_file(cub(), ac, av);
}