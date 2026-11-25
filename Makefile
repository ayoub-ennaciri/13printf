
NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

SRC = src/calculations.c     src/handle_x.c  src/handle_p.c         src/printing0.c src/printing1.c        src/ft_printf.c        src/libft_functions.c  src/switcher.c        src/handle_c.c         src/parser0.c                            src/handle_d.c         src/parser1.c    

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

bonus: all	

.PHONY: all clean fclean re
