NAME    = so_long
UNAME   := $(shell uname)
LFLAGS  =  -L$(LIBMLX)
OBJ     = $(SRC:%.c=%.o)
KEYCODES =  -D $(ESC) -D $(Q) -D $(R) -D $(W) -D $(A) -D $(S) -D $(D) -D $(ESP)
RATES	= -D $(GRATE)
SRC     =	srcs/animation.c \
			srcs/canva.c \
			srcs/check_path.c \
			srcs/checks_game.c \
			srcs/checks.c \
			srcs/collect.c \
			srcs/enemies.c \
			srcs/enemy_patrol.c \
			srcs/error.c \
			srcs/ft_split.c \
			$(GAME_C) \
			srcs/gravity.c \
			srcs/handle_keys.c \
			srcs/lst_functions.c \
			srcs/main.c \
			srcs/map.c \
			srcs/object.c \
			srcs/player.c \
			srcs/put_player.c \
			srcs/sprites.c \
			srcs/utils.c \
			srcs/get_next_line_bonus.c \
			srcs/get_next_line_utils_bonus.c

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
	R = KEY_R=15
	Q = KEY_Q=12
	ESP = KEY_ESPACE=49
	GRATE = GAME_RATE=17
	GAME_C = srcs/game_mac.c
else
	INC	= /usr/include
	CFLAGS  = -Wall -Werror -Wextra -g -I$(INC) -Iinclude -O3 $(KEYCODES) $(RATES) -Imlx_linux
	CC = @cc
	LIBMLX  = mlx_linux
	LFLAGS += -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz #-fsanitize=address -g
	ESC = KEY_ESC=65307
	W = KEY_W=119
	A = KEY_A=97
	S = KEY_S=115
	D = KEY_D=100
	R = KEY_R=114
	Q = KEY_Q=113
	ESP = KEY_ESPACE=65
	GRATE = GAME_RATE=2100
	GAME_C = srcs/game_linux.c
endif

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(OBJ) $(LFLAGS) -o $(NAME)
	@echo "$(GREEN)Toma la pah --> $(YELLOW)$(NAME)$(DEFAULT)"

clean:
	@rm -f $(OBJ)
	@echo "$(RED)Housekeeping...$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Byeee, files removed!$(DEFAULT)"

re: fclean all

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "OBJ		: $(OBJ)\n"

#COLORS
GREEN = \033[1;32m
RED = \033[1;31m
DEFAULT = \033[0m
YELLOW = \033[1;33m