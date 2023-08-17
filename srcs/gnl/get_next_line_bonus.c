/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:55:55 by htomas-d          #+#    #+#             */
/*   Updated: 2023/08/17 09:55:56 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	stash[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
	{
		if (fd > 0 && fd < FOPEN_MAX)
		{	
			while (stash[fd][i])
				stash[fd][i++] = 0;
		}
		return (NULL);
	}
	line = NULL;
	while (*(stash[fd]) || read(fd, stash[fd], BUFFER_SIZE) > 0)
	{
		line = ft_join(line, stash[fd]);
		if (ft_nextclean(stash[fd]))
			break ;
	}
	return (line);
}
