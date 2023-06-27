NAME		= cub3d

SRCS		= srcs/main.c srcs/exit/exit.c srcs/gnl/get_next_line.c 	\
				srcs/gnl/get_next_line_utils.c srcs/parse/parse_file.c srcs/parse/map.c \
				srcs/utils/str_utils.c srcs/utils/ft_split.c srcs/exit/frees.c	\
				srcs/parse/map_checker.c

OBJS		= $(SRCS:%.c=%.o)

MLX		= ./mlx/libmlx.a

MLX_FLAGS	= -framework OpenGL -framework AppKit

LINKS		= -L mlx -lmlx -L

INCLUDES	= -I mlx -I .

CC		= gcc -Wall -Wextra -Werror -g -fsanitize=address

RM		= rm -f

.c.o:
			$(CC) -c $< -o $@

all:		$(NAME)

$(NAME): 	 $(MLX) $(OBJS)
			$(CC) $(MLX) $(MLX_FLAGS) $(OBJS) -o $(NAME)
			@echo "$(GREEN)Successfully built --> $(YELLOW)$(NAME)$(DEFAULT)"

$(MLX):
			make -C mlx

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			make -C mlx clean
			@echo "$(RED)Files Removed!$(DEFAULT)"

re:			fclean all

.PHONY:		all clean re fclean

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