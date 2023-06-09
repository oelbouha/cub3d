# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelbouha <oelbouha@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 15:38:31 by oelbouha          #+#    #+#              #
#    Updated: 2023/06/09 15:38:33 by oelbouha         ###   ########.fr        #
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
