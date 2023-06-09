#include "cub3d.h"

t_cub *cub()
{
	static t_cub cub;
	return(&cub);

}

int main(int ac, char **av)
{
	// (void) av;
	check_file(cub(), ac, av);
	printf("%s\n", cub()->map.map[0]);
	printf("%s\n", cub()->map.map[1]);
	printf("%s\n", cub()->map.map[2]);
	printf("%s\n", cub()->map.map[3]);
	printf("%s\n", cub()->map.map[4]);
	printf("%s\n", cub()->map.map[5]);
	printf("%s\n", cub()->map.map[6]);
	printf("%s\n", cub()->map.map[7]);
	printf("%s\n", cub()->map.map[8]);
	free_stuff(cub());
}