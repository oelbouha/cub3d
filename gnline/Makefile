# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysalmi <ysalmi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 11:17:13 by ysalmi            #+#    #+#              #
#    Updated: 2023/05/13 18:24:21 by ysalmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc

CFLAGS := -Wall -Werror -Wextra

NAME := gnline.a

SRC :=	get_next_line_utils.c \
		get_next_line.c 

OBJ := $(SRC:%.c=%.o)
OBJ := $(addprefix obj/, $(OBJ))

$(NAME): $(OBJ)
	@ar -rcs $@ $^

all: $(NAME)

obj/%.o:%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re test
