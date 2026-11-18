
NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

SRC =	src/calc_num_base.c src/ft_calloc.c	    src/ft_printf.c	src/ft_putnbr_base.c	src/ft_strlen.c	src/handle_d.c	src/handle_x.c	src/parser1.c	src/calculat_lenght_width.c	src/ft_isdigit.c	src/ft_putchar.c	src/ft_putstr.c	src/handle_c.c	src/handle_space.c	src/handle_zero.c	src/parser0.c	src/switcher.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
