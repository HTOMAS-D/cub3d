/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:17:26 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 19:55:38 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

const char	*ft_white_spaces(const char *nptr)
{
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	return (nptr);
}

int	ft_atoi(const char *nptr)
{
	int	signal;
	int	nb;

	signal = 1;
	nb = 0;
	nptr = ft_white_spaces(nptr);
	if (*nptr == '-')
	{
		signal *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	cub()->rgb_flag++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + *nptr - '0';
		nptr++;
	}
	if (*nptr)
		cub()->rgb_flag = 7;
	return (nb * signal);
}
