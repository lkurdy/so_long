NAME = so_long

SRC =  src/mymap.c src/utils.c src/main.c src/get_next_line.c src/get_next_line_utils.c src/ft_printf.c src/ft_hex.c src/ft_putbase.c src/ft_utils.c src/element.c

CC = gcc

FLAGS	= -Wall -Wextra -Werror -I/usr/include -Imlx_linux -c

MLX	=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o

OBJ = ${SRC:.c=.o}

all: ${NAME}

%.o: %.c
	$(CC) $(FLAGS) $< -o $@

${NAME}: ${OBJ}
	make -C mlx_linux
	${CC} $(OBJ) $(MLX) $(NAME)

clean: 
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
