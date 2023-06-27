#include "cub3d.h"

void check_scene(char *str)
{
	int i;

	i = ft_strlen(str);
	if (i < 4)
		ez_exit("Invalid file type: Needs to be *.cub"); //added because it might crash on linux without it
	if(str[i - 1] == 'b' && str[i - 2] == 'u'
		&& str[i - 3] == 'c' && str[i - 4] == '.'
		&& str[i - 5])
		return ;
	else
		ez_exit("Invalid file type: Needs to be *.cub");
	
}

void check_file(t_cub *cub, int ac, char **av)
{
	if (ac != 2)
		ez_exit("Wrong number of arguments\nTry ./cub3d *map*");
	check_scene(av[1]);
	get_map(cub, av[1]);
	check_map(&(cub->map));
}