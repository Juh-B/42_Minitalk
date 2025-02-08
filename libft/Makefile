# Project name
NAME = libft.a

SRC = \
	ft_atoi.c ft_isdigit.c ft_strlen.c ft_strdup.c\
	ft_strjoin.c ft_printf.c\
	printf_putchar.c printf_putstr.c\
	printf_putnbr.c printf_putnbr_unsig.c\
	printf_puthex.c printf_putptr.c

DESP = libft.h
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Compilation
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(DESP)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
