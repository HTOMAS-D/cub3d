/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_linux_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:04:00 by htomas-d          #+#    #+#             */
/*   Updated: 2023/08/17 21:47:58 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub	*cub(void)
{
	static t_cub	cub;

	return (&cub);
}

void	init_screen(t_cub *cub)
{
	cub->screen.ptr = mlx_new_image(cub->mlx, SCREENW, SCREENH);
	cub->screen.addr = mlx_get_data_addr(cub->screen.ptr, &cub->screen.bpp, 
			&cub->screen.size_line, &cub->screen.endian);
}

//mlx_mouse_hide(cub->mlx, cub->win);
void	create_game(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		free_exit(cub, "mlx_init didnt work");
	init_screen(cub);
	cub->win = mlx_new_window(cub->mlx, SCREENW, SCREENH, "cub3d");
	if (!cub->win)
		free_exit(cub, "mlx_new_window failed");
	init_sprites(cub);
	init_object(cub);
	cub->zbuffer = ft_calloc(SCREENW, sizeof(double));
	init_player_vars(cub);
	mlx_hook(cub->win, MOUSE_MOVE, 1L << 6, move_mouse, cub);
	cub->fps_str = NULL;
	cub->horizon = SCREENH / 2;
	mlx_hook(cub->win, EXIT_KEY, 0, close_game, cub);
	mlx_hook(cub->win, KEY_PRESS, 1l << 0, get_key, cub);
	mlx_hook(cub->win, KEY_RELEASE, 1L << 1, key_release, cub);
	mlx_loop_hook(cub->mlx, &game_loop, cub);
	mlx_loop(cub->mlx);
}

int	main(int ac, char **av)
{
	check_file(cub(), ac, av);
	create_game(cub());
	free_stuff(cub());
}
