#ifndef CUB3D_H
#define CUB3D_H

#include "macros.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include "../mlx/mlx.h"

//SCREEN STUFF
# define SCREENW				1280
# define SCREENH				720
# define MM_W				250
# define MM_H				250

//MAC KEYCODES
#  define KEY_ESC	53
#  define KEY_W		13
#  define KEY_A		0
#  define KEY_S		1
#  define KEY_D		2
#  define ARROW_LEFT 	123
#  define ARROW_RIGHT	124

typedef struct s_map t_map;
typedef struct s_cub t_cub;
typedef struct s_data t_data;
typedef struct s_player t_player;
typedef struct s_ray t_ray;
typedef struct s_image t_image;


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
	int		floorPoint;
	double	wallH;
	int		x_axis;
};
struct s_ray
{
	double rayDirX;
	double rayDirY;
	double deltaDistX;
	double deltaDistY;
	double sidedistY;
	double sidedistX;
	double wall_dist;
	int mapX;
	int mapY;
	int stepX;
	int stepY;
	int side;
};

struct s_data
{
	int NO;
	int SO;
	int	WE;
	int EA;
	int F;
	int C;
};

struct s_map
{
	t_data data;
	int fd;
	char **map;
	char **img_paths;
	char **color_str;
	char **iso_map;
};

struct s_player
{
	double posX;
	double posY;
	double	dirY;
	double	dirX;
	double	fovX;
	double	fovY;
	char	orientation;
};

struct s_cub
{
	t_map map;
	void *mlx;
	void *win;
	t_player player;
	t_image screen;
	t_ray ray;
	int numb_players;
};


//MAIN.C
t_cub *cub(void);
void create_game(t_cub *cub);
void init_screen(t_cub *cub);

/*+****************** PARSING *********************/

//PARSE_FILE.C
void check_file(t_cub *cub, int ac, char **av);
void check_scene(char *str);


//MAP.C
void get_map(t_cub *cub, char *file);
int count_map(int fd);

//MAP_CHECKER.C
void check_map(t_map *map);
void get_img(t_map *map);
int check_path_letters(char *str);
int letters_check(t_data *data);

//COLOR_CHECKER.C
void get_colors(t_map *map);
int check_color_letters(char *str);
int all_color(t_data *data);

//ISOLATE_MAP.C
void isolate_map (t_map *map);
int line_nbr(char **map);

//PLAYER.C
void	get_player_vars(char **map);
void add_vars(int x, int y, char **map);
void init_player_vars(t_cub *cub);




/********************* UTILS **********************/

//STR_UTILS.C
int ft_lenstr(char *str);
char *ft_strrchr(char *str, char c);
char *ft_strjoin(char *s1, char *s2);
char *ft_strdup(char *str);

//FT_SPLIT.C
char **ft_split(char *str, char c);


/********************** EXIT/FREES **********************/

//EXIT.C
void ez_exit(char *str);
void parse_exit(t_map *map, char *str);
void	free_exit(t_cub *cub, char *str);

//FREES.C
void free_array(char *str);
void free_matrix(char ***matrix);
void free_stuff(t_cub *cub);
void free_mlx(t_cub *cub);




//IMG_UTIL.C
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
void	render(t_cub *cub);



//RAYCASTER.C
void raycaster(t_cub *cub);
void calc_step(t_cub *cub, t_ray *ray);
void ray_hit(t_cub *cub, t_ray *ray);

#endif