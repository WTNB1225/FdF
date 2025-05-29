NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c\
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \

FT_PRINTF_DIR = ft_printf/

GNL_DIR = get_next_line/

FT_PRINTF_C = ft_printf.c \
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

GNL_C = get_next_line.c \
		get_next_line_utils.c \

FT_PRINTF_SRC = $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_C))

GNL_SRC = $(addprefix $(GNL_DIR), $(GNL_C))

BONUSSRCS = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

OBJS = $(SRCS:.c=.o)

BONUSOBJS = $(BONUSSRCS:.c=.o)

FT_PRINTF_OBJ = $(FT_PRINTF_SRC:.c=.o)

GNL_OBJ = $(GNL_SRC:.c=.o)
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all bonus clean fclean re

$(NAME): $(OBJS) $(BONUSOBJS) $(FT_PRINTF_OBJ) $(GNL_OBJ)
	ar rcs $(NAME) $(OBJS) $(BONUSOBJS) $(FT_PRINTF_OBJ) $(GNL_OBJ)

all: $(NAME)

clean:
	rm -f $(OBJS) $(BONUSOBJS) $(FT_PRINTF_OBJ) $(GNL_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)

