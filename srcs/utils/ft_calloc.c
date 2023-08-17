/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:34:28 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/07/31 18:23:20 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*arr;
	size_t	i;

	i = -1;
	arr = malloc(elsize * nelem);
	if (!arr)
		return (NULL);
	if (nelem != 0)
	{
		while (++i < (elsize * nelem))
			arr[i] = 0;
		return ((void *)arr);
	}
	return ((void *)arr);
}
