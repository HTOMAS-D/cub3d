/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:53:10 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 16:14:05 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i + (str[i] == '\n'));
}

char	*ft_join(char *line, char *stash)
{
	char	*ret;
	size_t	i;

	ret = (char *)malloc((ft_strlen(line) + ft_strlen(stash)) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (line && line[++i])
		ret[i] = line[i];
	i += (!line);
	free(line);
	while (*stash)
	{
		ret[i++] = *stash;
		if (*stash++ == '\n')
			break ;
	}
	ret[i] = '\0';
	return (ret);
}

int	ft_nextclean(char *stash)
{
	int	nl_flag;
	int	i;
	int	j;

	i = 0;
	j = 0;
	nl_flag = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			nl_flag = 1;
			stash[i++] = 0;
			break ;
		}
		stash[i++] = 0;
	}
	while (nl_flag && stash[i])
	{
		stash[j++] = stash[i];
		stash[i++] = 0;
	}
	return (nl_flag);
}
