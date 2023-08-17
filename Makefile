NAME    = cub3d
UNAME   := $(shell uname)
LFLAGS  =  -L$(LIBMLX)
OBJ     = $(SRC:%.c=%.o)
KEYCODES =  -D $(ESC) -D $(Q) -D $(R) -D $(W) -D $(A) -D $(S) -D $(D) -D $(ESP) -D $(F) -D $(A1) -D $(A2)
RATES	= -D $(GRATE)
SRC     =	$(MAIN_C) srcs/exit/exit.c srcs/gnl/get_next_line.c 	\
				srcs/gnl/get_next_line_utils.c srcs/parse/parse_file.c srcs/parse/map.c \
				srcs/utils/str_utils.c srcs/utils/ft_split.c srcs/exit/frees.c	\
				srcs/parse/map_checker.c srcs/raycasting/raycaster.c \
				srcs/parse/color_checker.c srcs/parse/isolate_map.c \
				srcs/parse/player.c srcs/raycasting/img_util.c \
				$(HOOKS_C) srcs/raycasting/moves.c srcs/utils/ft_itoa.c \
				srcs/sprites.c srcs/engine.c srcs/fps_counter.c \
				srcs/utils/rbg_converter.c srcs/utils/ft_calloc.c \
				srcs/raycasting/minimap.c srcs/utils/ft_atoi.c srcs/parse/check_walls.c \
				srcs/animations.c srcs/object.c srcs/raycasting/draw_square.c \
				srcs/raycasting/raycaster_2.c srcs/print_object.c srcs/lookRL.c

ifeq ($(UNAME), Darwin)
	INC	= /usr/local/include
	CFLAGS  = -Wall -Werror -Wextra -g -I$(INC) -Iinclude -O3 $(KEYCODES) $(RATES) -Imlx
	CC = @gcc
	LIBMLX  = mlx
	LFLAGS += -framework OpenGL -framework AppKit -lmlx -Imlx -fsanitize=address -g
	ESC = KEY_ESC=53
	W = KEY_W=13
	A = KEY_A=0
	S = KEY_S=1
	D = KEY_D=2
	F = KEY_F=3
	R = KEY_R=15
	Q = KEY_Q=12
	ESP = KEY_ESPACE=49
	GRATE = GAME_RATE=17
	HOOKS_C = srcs/raycasting/hooks_mac.c
	MAIN_C = srcs/main_mac.c
else
	INC	= /usr/include
	CFLAGS  = -Wall -Werror -Wextra -g $(KEYCODES) -I$(INC) -Iinclude -O3 $(RATES) -Imlx_linux
	CC = @cc
	LIBMLX  = mlx_linux
	LFLAGS += -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -fsanitize=address -g
	ESC = KEY_ESC=65307
	W = KEY_W=119
	A = KEY_A=97
	S = KEY_S=115
	D = KEY_D=100
	R = KEY_R=114
	F = KEY_F=102
	Q = KEY_Q=113
	A1 = KEY_A_RIGHT=65363
	A2 = KEY_A_LEFT=65361
	ESP = KEY_ESPACE=32
	GRATE = GAME_RATE=100
	HOOKS_C = srcs/raycasting/hooks_linux.c
	MAIN_C = srcs/main_linux.c
endif

all: $(NAME)

$(NAME): $(OBJ) lib
	$(CC) $(OBJ) $(LFLAGS) -o $(NAME)
	@echo "$(GREEN)Toma la pah --> $(YELLOW)$(NAME)$(DEFAULT)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED)Housekeeping...$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBMLX) clean
	@echo "$(RED)Byeee, files removed!$(DEFAULT)"

lib:
	@make -C $(LIBMLX)

re: fclean all

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC			: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "OBJ		: $(OBJ)\n"

god:
	git status
	git add .
	git status
	git commit -m "🔥Random Makefile Commit🔥"
	git status


#COLORS
GREEN = \033[1;32m
RED = \033[1;31m
DEFAULT = \033[0m
YELLOW = \033[1;33m