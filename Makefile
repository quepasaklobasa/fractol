NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_REPO = https://github.com/42Paris/minilibx-linux.git
SRCS = main.c ft_color.c ft_error.c ft_events.c ft_map_help.c ft_init.c ft_math.c ft_render.c ft_string_utils.c
OBJS = $(SRCS:.c=.o)
LIBS = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm

all: $(NAME)

$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "MinilibX not found. Cloning..."; \
		git clone $(MLX_REPO) $(MLX_DIR); \
		rm -rf $(MLX_DIR)/.git; \
	fi
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all