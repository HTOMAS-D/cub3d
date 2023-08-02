/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbg_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:27:20 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/07/31 19:12:22 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_rgb(int r, int g, int b)
{
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		parse_exit(&cub()->map, "RGB values go from 0 - 255.\n");
	return (0);
}

int	place_letters(char **str, int n, int index)
{
	char	*hex;
	double	temp;

	hex = "0123456789ABCDEF";
	temp = (double)n / 16;
	str[0][index] = hex[(int)temp];
	temp = (temp - floor(temp)) * 16;
	str[0][index + 1] = hex[(int)temp];
	return (0);
}

int	hex_index(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	else if (c >= 'A' && c <= 'F')
		return (c - 55);
	else if (c >= 'a' && c <= 'f')
		return (c - 87);
	return (-1);
}

int	convert_hex_to_dec(char *str)
{
	int size;
	int	i;
	int res;

	str += 2;
	size = ft_strlen(str) - 1;
	i = 0;
	res = 0;
	while (size - i >= 0 && str[size - i])
	{
		res += pow(16, i) * hex_index(str[size - i]);
		i++;
	}
	return (res);
}

int	convert_rbg(int r, int g, int b)
{
	char	*str;
	int		res;
	
	check_rgb(r, g, b);
	str = calloc(9, sizeof(char));
	str[0] = '0';
	str[1] = 'x';
	place_letters(&str, r, 2);
	place_letters(&str, g, 4);
	place_letters(&str, b, 6);
	res = convert_hex_to_dec(str);
	free(str);
	return (res);
}
