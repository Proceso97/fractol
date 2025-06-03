# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzarza-g <jzarza-g@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 13:03:01 by jzarza-g          #+#    #+#              #
#    Updated: 2025/06/02 19:30:54 by jzarza-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = fractol
CC         = cc
CFLAGS     = -Wall -Wextra -Werror
INCLUDES   = -I. -Ilibft -Iheaders -Imlx

SRC        = src/fractol.c src/render.c
OBJ        = $(SRC:.c=.o)

LIBFT_DIR  = libft
LIBFT      = $(LIBFT_DIR)/libft.a

# MLX configuration for Linux
MLX_DIR    = mlx
MLX_FLAGS  = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm

.PHONY: all libft clean fclean re

all: libft $(NAME)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@echo "==> Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
