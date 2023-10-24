NAME = libft.a
FLAG = -Wall -Wextra -Werror
SRC = $(shell find . -name "ft_*.c")

CC	= gcc

all: $(NAME)

$(NAME):
	@$(CC) $(FLAG) -c $(SRC)
	@echo "✅"
	@ar rc $(NAME) *.o

clean:
	@/bin/rm -f *.o *.out

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "🗑️"

re: fclean all

.PHONY: all clean fclean re