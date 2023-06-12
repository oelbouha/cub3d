# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 20:14:07 by ysalmi            #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2023/06/11 20:01:24 by ysalmi           ###   ########.fr        #
=======
#    Updated: 2023/06/07 21:41:11 by oelbouha         ###   ########.fr        #
>>>>>>> 67e7479b9f8b2bd0282df78a17c0908217bb49f1
#                                                                              #
# **************************************************************************** #

NAME := cub3d
CC := cc
CFLAGS := -Wall -Werror -Wextra
MLX_DIR := /Users/oelbouha/Desktop/cub3d/minilibx
MLXFLAGS := -lmlx -L$(MLX_DIR) -framework OpenGL -framework AppKit
I := -I./inc -I./libft/inc -I$(MLX_DIR) -I./gnline
LIBFT := libft/libft.a
GNLINE := gnline/gnline.a


MAP_PARSER := map_parser/parser.c \
	map_parser/analyse_map.c

SRC := index.c \
	minimap.c \
	raycaster.c \
	$(MAP_PARSER) \
	canvas_utils.c \
	debug_utils.c
bb49f1

OBJ := $(addprefix obj/,$(SRC:.c=.o))

N :=\x1b[0m
G :=\x1b[32;01m
R :=\x1b[31;01m
B :=\x1b[43;01m
O :=\x1b[33;01m

all: libmlx libft $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $I -o $@ $^
	@echo "\n$O$(NAME)$N $Gcreated$N"

$(LIBFT): libft

libft:
	@$(MAKE) -s -C libft

libmlx:
	@$(MAKE) -s -C $(MLX_DIR)

obj/%.o: src/%.c
	@mkdir -p $(shell dirname $@)
	@echo "Compiling $B$<$N..."
	@$(CC) $(CFLAGS) $I -c $< -o $@

clean:
	@make -C libft clean
	@echo "$RDeleting $(NAME) object files...$N"
	@rm -rf obj
	@echo "$RDone.$N\n"

fclean:
	@make -C libft fclean
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

.PHONY: all clean fclean re clear libft

