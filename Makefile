NAME	=	so_long
CC		=	gcc -g
CFLAGS	=	-Wall -Werror -Wextra
LFLAGS	=	-Llibft -Lminilibx -lft -lmlx -framework OpenGL -framework AppKit
SOURCES 	= src/element_control.c \
			src/exit.c \
			src/ft_printf.c \
			src/get_next_line.c \
			src/hook.c \
			src/main.c \
			src/map_control.c \
			src/mlx_create.c \
			src/mlx_hook.c \
			src/placeholder.c \
			src/size_control.c

OBJ = $(SOURCES:.c=.o)

all		:	$(NAME)

$(NAME)	:	mdir $(OBJ)
		$(CC) $(CFLAGS) $(LFLAGS) $(SOURCES) -o $(NAME)

mdir	:
		@make -C libft
		@make -C minilibx

clean	:
		@make -C libft 		clean
		@make -C minilibx	clean
		@rm -f $(OBJ)

fclean :
		@make -C libft 		clean
		@make -C minilibx	clean
		@rm	-f $(NAME) $(OBJ)

re		:	fclean all

.PHONY	:	all $(NAME) mdir clean fclean re
