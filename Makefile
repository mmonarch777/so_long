NAME = so_long

HEADER = so_long.h

SRC = so_long.c		error.c		ft_handling_map.c		ft_add_image.c		ft_moove.c		ft_close.c

OBJ = $(patsubst %.c,%.o,$(SRC))

FLAGS = -Wall -Werror -Wextra

all: libft mlx $(NAME)

$(NAME): $(OBJ) $(HEADER)
		gcc -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
		gcc $(FLAGS) -Imlx -c $< -o $@

libft:
		make -C ./libft

mlx:
		make -C ./mlx
clean:
		rm -f $(OBJ)
		make clean -C ./libft

fclean: clean
		rm -f $(NAME)
		make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re libft mlx