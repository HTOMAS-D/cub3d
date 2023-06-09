#include "cub3d.h"

void get_map(t_cub *cub, char *file)
{
	char *line = NULL;
	char *temp = NULL;
	char *temp_free = NULL;

	cub->map.fd = open(file, O_RDONLY);
	if (cub->map.fd)
		ez_exit("Error opening the file");
	while(1)
	{
		line = get_next_line(cub->map.fd);
		if (!line)
			break;
		temp_free = temp;
		temp = ft_strjoin(temp, line);
		free(temp_free);
		free(line);
	}
	cub->map.map = ft_split(temp, "\n");
	free(temp);
}