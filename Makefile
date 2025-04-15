NAME        = so_long
SRCS        = main.c parsing.c exit.c moves.c win.c render.c
OBJS        = $(SRCS:.c=.o)
MLX_DIR     = ./mlx
MLX_LIB     = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
CFLAGS      = -Wall -Werror -Wextra
CC          = cc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) -o $(NAME)
	clear

$(MLX);
	cd ./mlx && make

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $^

clean:
	rm -f $(OBJS)
	cd ./mlx && make clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
