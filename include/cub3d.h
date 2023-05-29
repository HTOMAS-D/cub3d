#ifndef CUB3D_H
#define CUB3D_H

#include "macros.h"
#include "get_next_line.h"
#include <stdio.h>

typedef struct s_cub t_cub;

struct s_cub
{
	char *str;
};

//MAIN.C
t_cub *cub(void);
void ez_exit(char *str);

#endif