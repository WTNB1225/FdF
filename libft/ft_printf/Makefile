NAME =  libftprintf.a
LIBFT = libft
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	ft_printf_utils.c \
	get_hex.c \
	hex_utils.c \
	print_int_utils.c \
	print_char.c \
	print_str.c \
	print_p.c \
	print_int.c \
	print_u.c \
	print_x.c \
	print_utils.c \
	print_upper_x.c \
	spec_handler.c \
	spec_parser.c \
	spec_printer.c \
	print_fd.c \

OBJ = $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all bonus clean fclean re

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a

re: fclean all

bonus: $(NAME)
