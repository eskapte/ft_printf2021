NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I. -g

SRC = ft_printf.c parser/ft_parser.c parser/ft_parser.c handlers/char_handler.c handlers/ft_handler.c \
	  handlers/int_handler.c handlers/pointer_handler.c handlers/str_handler.c handlers/unsigned_handler.c \
	  handlers/percent_handler.c handlers/hex_handler.c

HEADERS = ft_printf.h parser/ft_parser.h handlers/ft_handler.h

OBJ = $(SRC:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	make -C libft/
	ar rcs $(NAME) $(OBJ) libft/*.o

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

norm:
	norminette $(SRC) $(HEADER) libft/

.PHONY: all clean fclean re norm