/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:53:13 by htomas-d          #+#    #+#             */
/*   Updated: 2023/08/17 21:44:48 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_rgb(char *str)
{
	char	*temp;
	int		*i;
	int		res;

	temp = ft_calloc(4, sizeof(char));
	i = ft_calloc(5, sizeof(int));
	if (!temp || !i)
		return (-1);
	while (str && *str && i[4] < 3)
	{
		i[0] = 0;
		while (*str && *str != ',')
			temp[i[0]++] = *str++;
		i[++i[4]] = ft_atoi(temp);
		i[0] = 0;
		while (temp[i[0]])
			temp[i[0]++] = 0;
		str++;
	}
	if (*(str - 1))
		cub()->rgb_flag = 7;
	res = convert_rbg(i[1], i[2], i[3]);
	free(i);
	free(temp);
	return (res);
}

int	all_color(t_data *data)
{
	if (data->f != 1 || data->c != 1)
		return (1);
	else
		return (0);
}

int	check_color_letters(char *str)
{
	if (str[0] == 'F' && str[1] == ' ')
	{
		cub()->map.data.f++;
		cub()->map.floor = get_rgb(str + 2);
		return (0);
	}
	else if (str[0] == 'C' && str[1] == ' ')
	{
		cub()->map.data.c++;
		cub()->map.ceiling = get_rgb(str + 2);
		return (0);
	}
	else
		return (1);
}

void	get_colors(t_map *map)
{
	int	i;
	int	j;

	i = 4;
	j = -1;
	map->color_str = calloc(sizeof(char *), 4);
	if (!map->color_str)
		parse_exit(map, "failed to alloc color strings");
	map->color_str[3] = NULL;
	while (map->map[++i] && i < 7)
	{
		if (check_color_letters(map->map[i]))
			parse_exit(map, "Wrong identifier");
	}
	if (cub()->rgb_flag != 6)
		parse_exit(map, "Need 3 numbers for rgb");
	if (all_color(&(map->data)))
		parse_exit(map, "Missing identifier");
	i = 4;
	while (map->map[++i] && i < 7)
		map->color_str[++j] = ft_strdup(&map->map[i][2]);
}
