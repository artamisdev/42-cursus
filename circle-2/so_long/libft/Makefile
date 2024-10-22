NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
SRC_GNL_ = get_next_line.c get_next_line_utils.c 
SRC_GNL = $(addprefix get_next_line/, $(SRC_GNL_))
SRC_PRINTF_ = ft_printf.c ft_ptr_print.c ft_putnbr_base_fd.c ft_print_x.c
SRC_PRINTF = $(addprefix ft_printf/, $(SRC_PRINTF_))

OBJ = $(SRC_GNL:.c=.o) $(SRC_PRINTF:.c=.o) $(SRC:.c=.o)

CC = cc -Wall -Werror -Wextra
AR = ar -rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)

re: fclean all
