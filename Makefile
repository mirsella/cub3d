SRCS_MAIN = main.c 
SRCS_MAP = map.c
SRCS = $(addprefix srcs/, $(SRCS_MAIN)) \
		$(addprefix srcs/map/, $(SRCS_MAP))
OBJS = $(SRCS:.c=.o)

CC = /usr/bin/cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g3
# CFLAGS += -fsanitize=address
INCLUDE = -Lmlx -lmlx -Lincludes -Imlx -lXext -lX11 -lm

LIBFT = libft/libft.a
MLX = mlx/libmlx.a
NAME = cub3d 

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) 
	

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

ffclean: fclean
	make -C libft fclean
	make -C mlx clean

re: fclean all

rere: ffclean all

$(LIBFT):
	make -C libft

$(MLX):
	make -C mlx

bonus: all

test:
	./$(NAME) maps/map.cub

norm:
	norminette srcs/ includes/

leak:
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME)

.PHONY: all clean fclean ffclean re rere bonus norm leak
