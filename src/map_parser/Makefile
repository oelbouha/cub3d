# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 21:41:54 by oelbouha          #+#    #+#              #
#    Updated: 2023/06/09 11:55:41 by oelbouha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := parser

CC := cc
CFLAGS := -Wall -Werror -Wextra
MLX_DIR := /Users/oelbouha/Desktop/cub3d/minilibx
MLXFLAGS := -lmlx -L$(MLX_DIR) -framework OpenGL -framework AppKit

I := -I../../inc \
	-I ../../libft/inc \
	-I$(MLX_DIR) \
	-I../../gnline

LIBFT := ../../libft/libft.a
LIBFT_DIR := ../../libft
GNLINE_DIR := ../../gnline
GNLINE := ../../gnline/gnline.a

SRC :=	main.c \
		parser.c \
		print.error.msg.c \
		destroy.textures.c \
		utils.c \
		create.rgb.c \
		create.colors.c \
		open.textures.c \
		get.rectangle.map.c 

OBJ := $(addprefix obj/,$(SRC:.c=.o))

N :=\x1b[0m
G :=\x1b[32;01m
R :=\x1b[31;01m
B :=\x1b[43;01m
O :=\x1b[33;01m

all: libmlx libft $(NAME) run

$(NAME): $(OBJ) $(LIBFT) $(GNLINE)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $I -o $@ $^
	@echo "\n$O$(NAME)$N $Gcreated$N"
	
run: 
	./parser ../../maps/map.cub

$(LIBFT): libft

libft:
	@$(MAKE) -C $(LIBFT_DIR)

libmlx:
	@$(MAKE) -C $(MLX_DIR)

obj/%.o: %.c
	@mkdir -p $(shell dirname $@)
	@echo "Compiling $B$<$N..."
	@$(CC) $(CFLAGS) $I -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf obj

fclean:
	@make -C $(LIBFT_DIR) fclean
	@rm -rf obj/
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re clear libft