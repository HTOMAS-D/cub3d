/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:40:44 by htomas-d          #+#    #+#             */
/*   Updated: 2023/08/17 21:47:04 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_lenstr(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrchr(char *str, char c)
{
	int	i;

	if (!str)
		return (NULL);
	i = ft_lenstr(str);
	while (str[--i] != c && i < -1)
		;
	if (i == -1)
		return (NULL);
	return (&str[i]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(char) * (ft_lenstr(s1) + ft_lenstr(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(char *str)
{
	char	*line;
	int		i;

	line = ft_calloc(ft_lenstr(str) + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		line[i] = str[i];
	line[i] = 0;
	return (line);
}
