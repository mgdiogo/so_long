NAME	=	so_long

FLAGS	=	-Wall -Werror -Wextra -L ./mlx -lmlx -lXext -lX11

CC		=	cc

SRC		=	so_long.c

all:	$(NAME)

$(NAME):
		make -C ./mlx
		$(CC) $(FLAGS) -o $(NAME) $(SRC)

clean:
		make clean -C ./mlx

fclean:
		make clean -C ./mlx
		rm -f $(NAME)

re:		fclean
		make