#ifndef CUB3D_H
#define CUB3D_H

#include "macros.h"
#include "string.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <sys/time.h>
#include "mlx.h"

//SCREEN STUFF
# define SCREENW				1280
# define SCREENH				720
# define MM_W				220
# define MM_H				220
# define PI 3.14159
# define RGB_UNIT			65793

//EVENTS
# define EXIT_KEY 17
# define MOUSE_MOVE 6
# define MOUSE_SENSITIVITY 0.05
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define MOVE_SPEED 0.03
# define JUMP_HEIGHT 30
# define GRAVITY_FORCE 0.7
# define MAX_GRAV 7

//MAC KEYCODES
// #  define KEY_ESC	53
// #  define KEY_W		13
// #  define KEY_A		0
// #  define KEY_S		1
// #  define KEY_D		2
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
	int		text_end;
	int		text_start;
	double	wallH;
	int		x_axis;
	int *data;
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
	double wallx;
	int	wallside;
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
	int	floor;
	int	ceiling;
};

struct s_move
{
	int	w;
	int	a;
	int	s;
	int	d;
	int jump;
	double gravity;
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
	struct s_move	move;
};

struct s_cub
{
	t_map map;
	void *mlx;
	int		horizon;
	void *win;
	char	*fps_str;
	int		n_renders;
	struct timeval old_time;
	struct timeval new_time;
	t_player player;
	t_image screen;
	t_image	wallNO;
	t_image	wallSO;
	t_image	wallWE;
	t_image	wallEA;
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

//CHECK_WALLS.C
int	check_walls(t_map *map);

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

//FT_ATOI.C
int	ft_atoi(const char *nptr);

//FT_CALLOC.C
void	*ft_calloc(size_t nelem, size_t elsize);

//STR_UTILS.C
int ft_lenstr(char *str);
char *ft_strrchr(char *str, char c);
char *ft_strjoin(char *s1, char *s2);
char *ft_strdup(char *str);

//FT_SPLIT.C
char **ft_split(char *str, char c);

//FT_ITOA.C
char *ft_itoa(int nbr);

//RBG_CONVERTER.C
int	convert_rbg(int r, int g, int b);

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

//ENGINE.C
int		render(t_cub *cub);
int game_loop(t_cub* cub);

//FPS_COUNTER.C
int	fps_counter(t_cub *cub);

//PLAYER.C
int	update_player(t_cub *cub);

//IMG_UTIL.C
int		get_color(int x, int y);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);

//SPRITES.C
int	init_sprites(t_cub *cub);

//RAYCASTER.C
void raycaster(t_cub *cub);
void calc_step(t_cub *cub, t_ray *ray);
void ray_hit(t_cub *cub, t_ray *ray);


//HOOKS.C
int close_game(t_cub *cub);
int move_mouse(int x, int y, t_cub *cub);
void rotation(t_player *player, double move);
int	key_release(int key, t_cub *cub);
int get_key(int key, t_cub *cub);


//MOVES.C
void move_w(t_cub *cub);
void move_a(t_cub *cub);
void move_s(t_cub *cub);
void move_d(t_cub *cub);
void	jump(t_cub *cub);


//MINIMAP.C
void minimap(t_cub *cub, char **map);
void get_borders(t_cub *cub);
void get_player(t_cub *cub);
void get_map_around(t_cub *cub, char **map);
void draw_square(int pX, int pY, int color);

#endif