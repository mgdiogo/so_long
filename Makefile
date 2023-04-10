NAME	=	so_long

LIB		=	-L ./mlx -lmlx -lXext -lX11

CC		=	cc

SRC		=	so_long.c ./aux/create_win.c ./aux/create_map.c ./aux/keyhooks.c \
			./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
			./aux/map_parsing.c ./aux/flood_map.c

all:	$(NAME)

$(NAME):
		make -C ./mlx
		$(CC) -o $(NAME) $(SRC) $(LIB) $(FLAGS) -fsanitize=address

clean:
		make clean -C ./mlx

fclean:
		make clean -C ./mlx
		rm -f $(NAME)

re:		fclean
		make