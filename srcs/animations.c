/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:36:30 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/16 18:10:39 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_door_animation(t_cub *cub)
{
	static int		i;
	static double	fps;
	double			time;

	if (cub->door.x < 0 || (!cub->door.hp && cub->door.animation.frame == cub->door.animation.max) || (cub->door.hp && cub->door.animation.frame == 0))
		return (0);
	if (!i)
		i = 1;
	if (!fps)
		gettimeofday(&cub->door.animation.old_time, NULL);
	fps = 1.0 / (cub->door.animation.max / 0.7);
	gettimeofday(&cub->door.animation.new_time, NULL);
	time = (cub->door.animation.new_time.tv_sec - cub->door.animation.old_time.tv_sec);
	time += (double)(cub->door.animation.new_time.tv_usec - cub->door.animation.old_time.tv_usec) / 1000000;
	//printf("%d - %d = %d / 1000000 = %f\n", cub->door.animation.new_time.tv_usec, cub->door.animation.old_time.tv_usec, cub->door.animation.new_time.tv_usec - cub->door.animation.old_time.tv_usec, (double)(cub->door.animation.new_time.tv_usec - cub->door.animation.old_time.tv_usec) / 1000000);
	// printf("{new} = %ld.%d\n", cub->door.animation.new_time.tv_sec, cub->door.animation.new_time.tv_usec);
	// printf("{old} = %ld.%d\n", cub->door.animation.old_time.tv_sec, cub->door.animation.old_time.tv_usec);
	//printf("%f < %f\n", time, fps);
	if (time > fps)
	{
		gettimeofday(&cub->door.animation.old_time, NULL);
		cub->door.animation.frame += i;
		if (cub->door.animation.frame == cub->door.animation.max || cub->door.animation.frame == 0)
			i *= -1;
	}
	return(0);
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
	time = (cub->wizard.animation.new_time.tv_sec - cub->wizard.animation.old_time.tv_sec);
	time += (double)(cub->wizard.animation.new_time.tv_usec - cub->wizard.animation.old_time.tv_usec) / 1000000;
	//printf("%d - %d = %d / 1000000 = %f\n", cub->wizard.animation.new_time.tv_usec, cub->wizard.animation.old_time.tv_usec, cub->wizard.animation.new_time.tv_usec - cub->wizard.animation.old_time.tv_usec, (double)(cub->wizard.animation.new_time.tv_usec - cub->wizard.animation.old_time.tv_usec) / 1000000);
	// printf("{new} = %ld.%d\n", cub->wizard.animation.new_time.tv_sec, cub->wizard.animation.new_time.tv_usec);
	// printf("{old} = %ld.%d\n", cub->wizard.animation.old_time.tv_sec, cub->wizard.animation.old_time.tv_usec);
	//printf("%f < %f\n", time, fps);
	if (time > fps)
	{
		gettimeofday(&cub->wizard.animation.old_time, NULL);
		cub->wizard.animation.frame += i;
		if (cub->wizard.animation.frame > 9 || cub->wizard.animation.frame < 0)
		{
			i *= -1;
			cub->wizard.animation.frame += i;
		}
		
	}
	return(0);
}

// int play_anim(t_animation data, int x, int y)
// {
// 	data.frame * data.size // saltar para frame certo ex frame 0 x 80 = 0 || 1 x80 = 80
	

// 	if (x >= data.size - 1) // mudar de frame, talvez seja melhor fazer isto no update game e controlar com tempo
// 	{
// 		data.frame++;
// 		if (data.frame >= data.max)
// 			data.frame = 0;
// 	}
// 	return (0);
// }