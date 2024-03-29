/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:01:23 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/08/17 19:47:57 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "macros.h"
# include "string.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include "mlx.h"

//SCREEN STUFF
# define SCREENW				1280
# define SCREENH				720
# define MM_W				240
# define MM_H				240
# define PI 3.14159
# define RGB_UNIT			65793
# define TRANSPARENT		3817537

//EVENTS
# define EXIT_KEY 17
# define MOUSE_MOVE 6
# define MOUSE_SENSITIVITY 0.05
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define MOVE_SPEED 0.03
# define JUMP_HEIGHT 3
# define GRAVITY_FORCE 0.7
# define MAX_GRAV 7

//MAC KEYCODES
# define ARROW_LEFT 	123
# define ARROW_RIGHT	124

typedef struct s_map	t_map;
typedef struct s_cub	t_cub;
typedef struct s_data	t_data;
typedef struct s_player	t_player;
typedef struct s_ray	t_ray;
typedef struct s_image	t_image;

struct s_image
{
	void	*ptr;
	char	*addr;
	int		bpp;	
	int		size_line;	
	int		endian;		
	int		width;
	int		height;
	int		ceilingpoint;
	int		floorpoint;
	int		text_end;
	int		text_start;
	double	wallh;
	double	wizh;
	int		x_axis;
	int		*data;
};

struct s_animation
{
	struct timeval	old_time;
	struct timeval	new_time;
	struct s_image	img;
	int				frame;
	int				max;
	int				size;

};

struct s_ray
{
	int		hit;
	double	raydirx;
	double	raydiry;
	double	deltadistx;
	double	deltadisty;
	double	sidedisty;
	double	sidedistx;
	double	wall_dist;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		side;
	double	wallx;
	int		wallside;
};

struct s_object
{
	int					hp;
	double				x;
	double				y;
	double				printx;
	double				printy;	
	t_ray				ray;
	struct s_animation	animation;
};

struct s_data
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
};

struct s_map
{
	t_data	data;
	int		fd;
	char	**map;
	char	**img_paths;
	char	**color_str;
	char	**iso_map;
	int		floor;
	int		ceiling;
	int		mapheight;
};

struct s_move
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			a_left;
	int			a_right;
	int			jump;
	double		gravity;
};

struct s_player
{
	double			posx;
	double			posy;
	double			diry;
	double			dirx;
	double			fovx;
	double			fovy;
	char			orientation;
	struct s_move	move;
};

struct s_cub
{
	int				rgb_flag;
	t_map			map;
	void			*mlx;
	int				horizon;
	void			*win;
	char			*fps_str;
	int				n_renders;
	struct timeval	old_time;
	struct timeval	new_time;
	double			*zbuffer;
	t_player		player;
	t_image			screen;
	t_image			wallno;
	t_image			wallso;
	t_image			wallwe;
	t_image			wallea;
	t_ray			ray;
	int				press_f;
	struct s_object	wizard;
	struct s_object	door;
	int				numb_players;
};

//MAIN.C
t_cub	*cub(void);
void	create_game(t_cub *cub);
void	init_screen(t_cub *cub);

/*+****************** PARSING *********************/

//PARSE_FILE.C
void	check_file(t_cub *cub, int ac, char **av);
void	check_scene(char *str);

//MAP.C
void	get_map(t_cub *cub, char *file);
int		count_map(char *file, t_cub *cub);

//MAP_CHECKER.C
void	check_map(t_map *map);
void	get_img(t_map *map);
int		check_path_letters(char *str);
int		letters_check(t_data *data);

//CHECK_WALLS.C
int		check_walls(t_map *map);

//COLOR_CHECKER.C
void	get_colors(t_map *map);
int		check_color_letters(char *str);
int		all_color(t_data *data);

//ISOLATE_MAP.C
void	isolate_map(t_map *map);
int		line_nbr(char **map);

//PLAYER.C
void	get_player_vars(char **map);
void	add_vars(int x, int y, char **map);
void	init_player_vars(t_cub *cub);

/********************* UTILS **********************/

//FT_ATOI.C
int		ft_atoi(const char *nptr);

//FT_CALLOC.C
void	*ft_calloc(size_t nelem, size_t elsize);

//STR_UTILS.C
int		ft_lenstr(char *str);
char	*ft_strrchr(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);

//FT_SPLIT.C
char	**ft_split(char *str, char c);

//FT_ITOA.C
char	*ft_itoa(int nbr);

//RBG_CONVERTER.C
int		convert_rbg(int r, int g, int b);

/********************** EXIT/FREES **********************/

//EXIT.C
void	ez_exit(char *str);
void	parse_exit(t_map *map, char *str);
void	free_exit(t_cub *cub, char *str);

//FREES.C
void	free_array(char *str);
void	free_matrix(char ***matrix);
void	free_stuff(t_cub *cub);
void	free_mlx(t_cub *cub);

//ENGINE.C
int		render(t_cub *cub);
int		game_loop(t_cub *cub);

//FPS_COUNTER.C
int		fps_counter(t_cub *cub);

//PLAYER.C
int		update_player(t_cub *cub);

//IMG_UTIL.C
int		get_color(int x, int y, int size);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
int		check_color(int x, int y, int size, t_image *img);

//SPRITES.C
int		init_sprites(t_cub *cub);

//RAYCASTER.C
void	copy_ray(t_ray *og, int *counter);
void	get_wall(t_cub *cub, t_ray *ray);
void	get_door(t_cub *cub, t_ray *ray);
void	put_screen(t_cub *cub);

//RAYCASTER_2.C
void	raycaster(t_cub *cub);
void	calc_step(t_cub *cub, t_ray *ray);
void	ray_hit(t_cub *cub, t_ray *ray);

//HOOKS.C
int		close_game(t_cub *cub);
int		move_mouse(int x, int y, t_cub *cub);
void	rotation(t_player *player, double move);
int		key_release(int key, t_cub *cub);
int		get_key(int key, t_cub *cub);

//ANIMATIONS.C
int		update_wizard_animation(t_cub *cub);
int		update_door_animation(t_cub *cub);

//OBJECT.C
int		init_object(t_cub *cub);
int		press_f(t_cub *cub);
int		print_phrase(t_cub *cub, char *str);

//PRINT_OBJECT.C
void	print_object(t_cub *cub);

//MOVES.C
void	move_w(t_cub *cub);
void	move_a(t_cub *cub);
void	move_s(t_cub *cub);
void	move_d(t_cub *cub);
void	jump(t_cub *cub);

//MINIMAP.C
void	minimap(t_cub *cub, char **map);
void	get_borders(t_cub *cub);
void	get_player(t_cub *cub);
void	get_map_around(t_cub *cub, char **map);
void	draw_square(int pX, int pY, int color);

//LOOKRL.C
void	look_left(t_cub *cub);
void	look_right(t_cub *cub);

#endif