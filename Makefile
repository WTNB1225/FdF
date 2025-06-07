# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 03:34:20 by wyuki             #+#    #+#              #
#    Updated: 2025/06/06 19:14:00 by wyuki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = fdf
CFLAGS = -Wall -Wextra -Werror -fsanitize=undefined

INCS = -I ./includes/

SRC_DIR = src/

SRC = main.c \
	  read_file.c \
	  read_color.c \
	  read_file_utils.c \
	  error.c \
	  draw.c \
	  isometric.c \
	  math_utils.c \
	  map_utils.c \

SRCS = $(addprefix $(SRC_DIR), $(SRC))

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft
	$(CC) $(CFLAGS) $(INCS) -o $@ $^ -L libft -lft -L mlx -lmlx -lXext -lX11 -lm

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
