SOURCES = ft_printf.c ft_printf_func.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SOURCES:.c=.o)

CC = cc

NAME = libftprintf.a

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

all: $(NAME)

ap:
	$(CC) $(FLAGS) $(SOURCES)
	./a.out

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all ap clean fclean re