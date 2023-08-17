/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:36:30 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 15:47:13 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	do_door_thing(t_cub *cub, int *i)
{
	gettimeofday(&cub->door.animation.old_time, NULL);
	cub->door.animation.frame += *i;
	if (cub->door.animation.frame == cub->door.animation.max || 
		cub->door.animation.frame == 0)
		*i *= -1;
}

int	update_door_animation(t_cub *cub)
{
	static int		i;
	static double	fps;
	double			time;

	if (cub->door.x < 0 || 
		(!cub->door.hp && 
			cub->door.animation.frame == cub->door.animation.max) || 
		(cub->door.hp && cub->door.animation.frame == 0))
		return (0);
	if (!i)
		i = 1;
	if (!fps)
		gettimeofday(&cub->door.animation.old_time, NULL);
	fps = 1.0 / (cub->door.animation.max / 0.7);
	gettimeofday(&cub->door.animation.new_time, NULL);
	time = (cub->door.animation.new_time.tv_sec - 
			cub->door.animation.old_time.tv_sec);
	time += (double)(cub->door.animation.new_time.tv_usec - 
			cub->door.animation.old_time.tv_usec) / 1000000;
	if (time > fps)
		do_door_thing(cub, &i);
	return (0);
}

void	do_wizard_thing(t_cub *cub, int *i)
{
	gettimeofday(&cub->wizard.animation.old_time, NULL);
	cub->wizard.animation.frame += *i;
	if (cub->wizard.animation.frame > 9 || 
		cub->wizard.animation.frame < 0)
	{
		*i *= -1;
		cub->wizard.animation.frame += *i;
	}
}

int	update_wizard_animation(t_cub *cub)
{
	static int		i;
	static double	fps;
	double			time;

	if (!cub->wizard.hp || cub->wizard.x < 0)
		return (0);
	if (!i)
		i = 1;
	if (!fps)
		gettimeofday(&cub->wizard.animation.old_time, NULL);
	fps = 1.0 / (cub->wizard.animation.max / 1.7);
	gettimeofday(&cub->wizard.animation.new_time, NULL);
	time = (cub->wizard.animation.new_time.tv_sec - 
			cub->wizard.animation.old_time.tv_sec);
	time += (double)(cub->wizard.animation.new_time.tv_usec - 
			cub->wizard.animation.old_time.tv_usec) / 1000000;
	if (time > fps)
		do_wizard_thing(cub, &i);
	return (0);
}
