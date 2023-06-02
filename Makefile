# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysalmi <ysalmi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 20:14:07 by ysalmi            #+#    #+#              #
#    Updated: 2023/06/02 10:50:25 by ysalmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3d
CC := cc
CFLAGS := -Wall -Werror -Wextra
MLX_DIR := /Users/ysalmi/code/in_progress/cub3d/minilibx
MLXFLAGS := -lmlx -L$(MLX_DIR) -framework OpenGL -framework AppKit
I := -I./inc -I./libft/inc -I$(MLX_DIR)
LIBFT := libft/libft.a

SRC := main.c \
	canvas_utils.c

OBJ := $(addprefix obj/,$(SRC:.c=.o))

N :=\x1b[0m
G :=\x1b[32;01m
R :=\x1b[31;01m
B :=\x1b[43;01m
O :=\x1b[33;01m

all: libmlx libft $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(MLXFLAGS) $I -o $@ $^
	@echo "\n$O$(NAME)$N $Gcreated$N"

$(LIBFT): libft

libft:
	@$(MAKE) -C libft

libmlx:
	@$(MAKE) -C $(MLX_DIR)

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

