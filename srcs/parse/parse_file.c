#include "cub3d.h"

void check_scene(char *str)
{
	int i;

	i = ft_strlen(str);
	if(str[i] == 'b' && str[i - 1] == 'u'
		&& str[i - 2] == 'c' && str[i - 3] == '.'
		&& str[i - 4])
		return ;
	else
		ez_exit("Invalid file type: Needs to be *.cub");
	
}

void check_file(t_cub *cub, int ac, char **av)
{
	if (ac != 2)
		ez_exit("Wrong number of arguments\nTry ./cub3d *map*");
	check_scene(av[1]);
}