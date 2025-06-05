# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzarza-g <jzarza-g@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 13:03:01 by jzarza-g          #+#    #+#              #
#    Updated: 2025/06/05 14:40:52 by jzarza-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/fractol.c src/utils.c src/init.c src/events.c \
	  src/algorithms.c src/render.c src/draw_fractals.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBS = -Llibft -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(LIBFT):
	make -C libft

$(MLX_LIB): $(MLX_DIR)
	make -C $(MLX_DIR)

$(MLX_DIR):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Iheaders -Ilibft -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean
	if [ -d $(MLX_DIR) ]; then make -C $(MLX_DIR) clean; fi

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
