/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:57:53 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 18:05:36 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

struct s_print_object
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		sprite_screen_x;
	int		sprite_height;
	int		draw_start_y;
	int		draw_end_y;
	int		sprite_width;
	int		draw_start_x;
	int		text_x_start;
	int		draw_end_x;
	int		text_x_end;
	int		stripe;
	int		y;
};

void	print_object_loop(t_cub *cub, struct s_print_object *data)
{
	while (++data->stripe < data->draw_end_x)
	{
		if (data->transform_y > 0 && data->transform_y < \
		cub->ZBuffer[data->stripe])
		{
			cub->wizard.printx = ((data->stripe - data->text_x_start) * \
			cub->wizard.animation.size) / (data->text_x_end - \
			data->text_x_start);
			data->y = data->draw_start_y - 1;
			while (++data->y < data->draw_end_y)
			{
				cub->wizard.printy = ((data->y - cub->screen.text_start) \
				* cub->wizard.animation.size) / (cub->screen.text_end - \
				cub->screen.text_start);
				my_mlx_pixel_put(&cub->screen, data->stripe, data->y, \
				get_color(data->stripe, data->y, cub->wizard.animation.size));
			}
		}
	}
}

void	print_object_2(t_cub *cub, struct s_print_object *data)
{
	cub->ray.wallside = -1;
	data->sprite_x = cub->wizard.x - cub->player.posX;
	data->sprite_y = cub->wizard.y - cub->player.posY;
	data->inv_det = 1.0 / (cub->player.fovX * cub->player.dirY - \
	cub->player.dirX * cub->player.fovY);
	data->transform_x = data->inv_det * (cub->player.dirY * \
	data->sprite_x - cub->player.dirX * data->sprite_y);
	data->transform_y = data->inv_det * (-cub->player.fovY * \
	data->sprite_x + cub->player.fovX * data->sprite_y);
	data->sprite_screen_x = (int)((SCREENW / 2) * \
	(1 + data->transform_x / data->transform_y));
	data->sprite_height = abs((int)(SCREENH / (data->transform_y)));
	data->draw_start_y = -data->sprite_height / 2 + SCREENH / 2;
	cub->screen.text_start = data->draw_start_y;
	if (data->draw_start_y < 0)
		data->draw_start_y = 0;
	data->draw_end_y = data->sprite_height / 2 + SCREENH / 2;
	cub->screen.text_end = data->draw_end_y;
	if (data->draw_end_y >= SCREENH)
		data->draw_end_y = SCREENH - 1;
	data->sprite_width = abs((int)(SCREENH / (data->transform_y)));
}

void	print_object(t_cub *cub)
{
	struct s_print_object	data;

	if (!cub->wizard.hp)
		return ;
	print_object_2(cub, &data);
	data.draw_start_x = -data.sprite_width / 2 + \
	data.sprite_screen_x;
	data.text_x_start = data.draw_start_x;
	if (data.draw_start_x < 0)
		data.draw_start_x = 0;
	data.draw_end_x = data.sprite_width / 2 + \
	data.sprite_screen_x;
	data.text_x_end = data.draw_end_x;
	if (data.draw_end_x > SCREENW)
		data.draw_end_x = SCREENW;
	data.stripe = data.draw_start_x - 1;
	print_object_loop(cub, &data);
}
