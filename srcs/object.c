/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:20:07 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/16 18:12:25 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_phrase(t_cub *cub, char *str)
{
	if (str)
		mlx_string_put(cub->mlx, cub->win, (SCREENW / 2) - (ft_strlen(str) * 5), SCREENH / 2, \
	0xFFFFF, str);
	return (0);
}

int	press_f(t_cub *cub)
{
	if (cub->ray.hit)
	{
		if ((int)cub->player.posx == (int)(cub->door.x) && ((int)cub->player.posy == (int)cub->door.y + 1 || (int)cub->player.posy == (int)cub->door.y - 1))
		{
			cub->press_f = 1;
			return (1);
		}
		if ((int)cub->player.posy == (int)(cub->door.y) && ((int)cub->player.posx == (int)cub->door.x + 1 || (int)cub->player.posx == (int)cub->door.x - 1))
		{
			cub->press_f = 1;
			return (1);
		}
	}
	cub->press_f = 0;
	return (0);
}

int	init_door(t_cub *cub)
{
	int y;
	int	x;

	y = -1;
	cub->door.hp = 0;
	while (cub->map.iso_map[++y])
	{
		x = -1;
		while (cub->map.iso_map[y][++x])
		{
			if (cub->map.iso_map[y][x] == 'D')
			{
				cub->door.x = (double)(x);
				cub->door.y = (double)(y);
				cub->door.hp = 1;
				return (1);
			}
		}
	}
	cub->door.x = -1.0;
	return (0);
}

int	init_object(t_cub *cub)
{
	int y;
	int	x;

	y = -1;
	init_door(cub);
	cub->wizard.hp = 0;
	while (cub->map.iso_map[++y])
	{
		x = -1;
		while (cub->map.iso_map[y][++x])
		{
			if (cub->map.iso_map[y][x] == 'Z')
			{
				cub->wizard.x = (double)(x + 0.5);
				cub->wizard.y = (double)(y + 0.5);
				cub->wizard.hp = 1;
				return (1);
			}
		}
	}
	cub->wizard.x = -1.0;
	return (0);
}

void	print_object(t_cub *cub)
{
	if (!cub->wizard.hp)
		return ;

	cub->ray.wallside = -1;
	
	double spriteX = cub->wizard.x - cub->player.posx;
    double spriteY = cub->wizard.y - cub->player.posy;

	double invDet = 1.0 / (cub->player.fovx * cub->player.diry - cub->player.dirx * cub->player.fovy);

	double transformX = invDet * (cub->player.diry * spriteX - cub->player.dirx * spriteY);
    double transformY = invDet * (-cub->player.fovy * spriteX + cub->player.fovx * spriteY);

	int spriteScreenX = (int)((SCREENW / 2) * (1 + transformX / transformY));
	
	int spriteHeight = abs((int)(SCREENH / (transformY)));
	
	int drawStartY = -spriteHeight / 2 + SCREENH / 2;
	cub->screen.text_start = drawStartY;
    if(drawStartY < 0)
		drawStartY = 0;
    int drawEndY = spriteHeight / 2 + SCREENH / 2;
	cub->screen.text_end = drawEndY;
    if(drawEndY >= SCREENH)
		drawEndY = SCREENH - 1;
	
	int spriteWidth = abs((int)(SCREENH / (transformY))); // same as height of sprite, given that it's square
    int drawStartX = -spriteWidth / 2 + spriteScreenX;
	int text_x_start = drawStartX;
    if(drawStartX < 0)
		drawStartX = 0;
    int drawEndX = spriteWidth / 2 + spriteScreenX;
	int text_x_end = drawEndX;
    if(drawEndX > SCREENW)
		drawEndX = SCREENW;
	
	for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        if(transformY > 0 && transformY < cub->zbuffer[stripe])
        {
			cub->wizard.printx = ((stripe - text_x_start) * cub->wizard.animation.size) / (text_x_end - text_x_start);
        	for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
			{
				cub->wizard.printy = ((y - cub->screen.text_start) * cub->wizard.animation.size) / (cub->screen.text_end -cub->screen.text_start);
				// printf("{%d, %d}\n", y, stripe);
				my_mlx_pixel_put(&cub->screen, stripe, y, get_color(stripe, y, cub->wizard.animation.size));
			}
        }
      }
}