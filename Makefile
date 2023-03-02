SRCS_MAIN = main.c 
SRCS = $(addprefix srcs/, $(SRCS_MAIN)) 
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g3
# CFLAGS += -fsanitize=address
INCLUDE = -Lmlx -lmlx -Lincludes -Imlx -lXext -lX11 -lm -lz

LIBFT = libft/libft.a
MLX = mlx/libmlx.a
NAME = cub3d 

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -Imlx -O3 -c $< -o $@

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

norm:
	norminette srcs/ includes/

leak:
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=rl_leaks.txt ./$(NAME)

.PHONY: all clean fclean ffclean re rere bonus norm leak
