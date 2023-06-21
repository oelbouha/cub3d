# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 20:14:07 by ysalmi            #+#    #+#              #
#    Updated: 2023/06/21 10:48:12 by ysalmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := cub3D
CC := cc
CFLAGS := -Wall -Werror -Wextra
MLX_DIR := $(shell pwd)/minilibx
MLXFLAGS := -lmlx -L$(MLX_DIR) -framework OpenGL -framework AppKit
I := -I./inc -I./libft/inc -I$(MLX_DIR) -I./gnline
LIBFT := libft/libft.a
GNLINE := gnline/gnline.a


MAP_PARSER := map_parser/parser.c \
	map_parser/analyse_map.c

SRC := index.c \
	init.c \
	minimap.c \
	scene.c \
	event_handler.c \
	raycaster.c \
	canvas_utils.c \
	draw_line.c \
	debug_utils.c \
	parser.c \
	print.error.msg.c \
	destroy.textures.c \
	utils.c \
	create.colors.c \
	open.textures.c \
	analyze.map.c \
	init.player.c \
	get.rectangle.map.c

OBJ := $(addprefix obj/,$(SRC:.c=.o))

N :=\x1b[0m
G :=\x1b[32;01m
R :=\x1b[31;01m
B :=\x1b[43;01m
O :=\x1b[33;01m

all: libmlx libft gnline $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(GNLINE)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $I -o $@ $^
	@echo "\n$O$(NAME)$N $Gcreated$N"

$(LIBFT): libft

libft:
	@$(MAKE) -s -C libft

$(GNLINE): gnline

gnline:
	@$(MAKE) -C gnline

libmlx:
	@$(MAKE) -s -C $(MLX_DIR)

obj/%.o: src/%.c inc/cub3d.h
	@mkdir -p $(shell dirname $@)
	@echo "Compiling $B$<$N..."
	@$(CC) $(CFLAGS) $I -c $< -o $@

clean:
	@$(MAKE) -C gnline clean
	@$(MAKE) -C libft clean
	@echo "$RDeleting $(NAME) object files...$N"
	@rm -rf obj
	@echo "$RDone.$N\n"

fclean:
	@$(MAKE) -C gnline fclean
	@$(MAKE) -C libft fclean
	@echo "$RDeleting $(NAME) object files...$N"
	@rm -rf obj/
	@echo "$RDone.$N\n"
	@echo "$RDeleting $O$(NAME) and $(BONUS)$R..."
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@echo "$RDone.$N\n"


re: fclean all

clear:
	clear

.PHONY: all clean fclean re clear libft gnline

