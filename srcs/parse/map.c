/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:50:11 by htomas-d          #+#    #+#             */
/*   Updated: 2023/08/17 09:50:12 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_map(char *file, t_cub *cub)
{
	char	*line;
	int		count;

	count = 0;
	cub->map.fd = open(file, O_RDONLY);
	if (cub->map.fd < 0)
		ez_exit("Error opening the file");
	while (1)
	{
		line = get_next_line(cub->map.fd);
		if (!line)
			break ;
		count++;
		free_array(line);
	}
	close(cub->map.fd);
	return (count);
}

void	get_map(t_cub *cub, char *file)
{
	char	*line;
	int		size;

	line = NULL;
	size = count_map(file, cub);
	cub->map.map = malloc(sizeof(char *) * (size + 1));
	if (!cub->map.map)
		ez_exit("Memory allocation failed");
	cub->map.fd = open(file, O_RDONLY);
	if (cub->map.fd < 0)
		ez_exit("Error opening the file");
	size = 0;
	while (1)
	{
		line = get_next_line(cub->map.fd);
		if (!line)
			break ;
		cub->map.map[size++] = ft_strdup(line);
		free_array(line);
	}
	cub->map.map[size] = NULL;
	close(cub->map.fd);
}
