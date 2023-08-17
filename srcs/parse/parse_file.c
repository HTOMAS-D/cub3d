/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:39:28 by htomas-d          #+#    #+#             */
/*   Updated: 2023/08/17 09:39:29 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_scene(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 4)
		ez_exit("Invalid file type: Needs to be *.cub");
	if (str[i - 1] == 'b' && str[i - 2] == 'u'
		&& str[i - 3] == 'c' && str[i - 4] == '.'
		&& str[i - 5])
		return ;
	else
		ez_exit("Invalid file type: Needs to be *.cub");
}

void	check_file(t_cub *cub, int ac, char **av)
{
	cub->numb_players = 0;
	if (ac != 2)
		ez_exit("Wrong number of arguments\nTry ./cub3d *map*");
	check_scene(av[1]);
	get_map(cub, av[1]);
	check_map(&(cub->map));
}
