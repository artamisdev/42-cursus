NAME = libftprintf.a

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)
LIBFT_OBJ = libft/*.o

CC = cc -Wall -Werror -Wextra
AR = ar -rcs
RM = rm -rf

all: libft $(NAME)

libft:
	make -C ./libft all

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ) $(LIBFT_OBJ)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	make -C ./libft clean
	$(RM) $(OBJ)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re