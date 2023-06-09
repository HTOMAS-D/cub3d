#include "cub3d.h"

int count_map(int fd)
{
	char *line;
	int count;

	count = 0;
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		count++;
		free_array(line);
	}
	return (count);
}

void get_map(t_cub *cub, char *file)
{
	char *line = NULL;
	int size;

	cub->map.fd = open(file, O_RDONLY);
	if (!cub->map.fd)
		ez_exit("Error opening the file");
	size = count_map(cub->map.fd);
	close(cub->map.fd);
	cub->map.map = malloc(sizeof(char *) * size + 1);
	cub->map.map[size] = NULL;
	cub->map.fd = open(file, O_RDONLY);
	size = 0;
	while(1)
	{
		line = get_next_line(cub->map.fd);
		if (!line)
			break;
		cub->map.map[size++] = ft_strdup(line);
		free_array(line);
	}
	close(cub->map.fd);
}
