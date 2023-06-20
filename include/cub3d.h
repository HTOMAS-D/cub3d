#ifndef CUB3D_H
#define CUB3D_H

#include "macros.h"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct s_map t_map;
typedef struct s_cub t_cub;
typedef struct s_data t_data;

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
};
struct s_cub
{
	t_map map;
};


//MAIN.C
t_cub *cub(void);

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

//FREES.C
void free_array(char *str);
void free_matrix(char **matrix);
void free_stuff(t_cub *cub);

#endif