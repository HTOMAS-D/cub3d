#include "cub3d.h"

void free_array(char *str)
{
	if(!str)
		return ;
	free(str);
	str = NULL;
}

void free_matrix(char **matrix)
{
	int i;
	
	i = -1;
	if (!matrix)
		return ;
	while(matrix[++i])
		free(matrix[i]);
	free(matrix);
	matrix = NULL;
}

void free_stuff(t_cub *cub)
{
	if(cub->map.map)
		free_matrix(cub->map.map);
}