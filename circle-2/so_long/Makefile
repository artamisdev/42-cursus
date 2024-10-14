NAME = so_long

SRC = so_long.c

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

CC = cc -Wall -Werror -Wextra
RM = rm -rf

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

clean: 

fclean: rm -f $(NAME)

re: 

