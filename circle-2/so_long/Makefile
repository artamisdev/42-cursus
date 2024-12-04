NAME = so_long

SRC =	so_long.c\
		deploy_background.c\
		check_pack_1.c\
		check_pack_2.c

OBJ = $(SRC:.c=.o)

UNAME = $(shell uname)

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
ifeq ($(UNAME), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
	INCLUDES = -I/usr/include -Imlx
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
	INCLUDES = -I/opt/X11/include -Imlx
endif

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

CC = cc -Wall -Werror -Wextra -fsanitize=address -g3
RM = rm -rf

all: $(MLX_LIB) $(LIBFT_LIB) $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(MLX_FLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(INCLUDES) -c $< -o $@

clean:
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

