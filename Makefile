NAME = pac_man

SRC =  test.c
#main.c get_next_line.c get_next_line_utils.c

CC = gcc

FLAGS	= -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c

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
