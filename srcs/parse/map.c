#include "cub3d.h"

void get_map(t_cub *cub, char *file)
{
	int fd;
	char *line = NULL;
	(void) cub;

	fd = open(file, O_RDONLY);
	if (!fd)
		ez_exit("Error opening the file");
	while(line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
}