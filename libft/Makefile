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

NAME := libft.a
INC := -Iinc/

SRCDIR := src
SRC := ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_templatecmp.c \
		ft_issubset.c \
		ft_strnstr.c \
		ft_stristr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstdel_first.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_lstremove_if.c \
		ft_lst_to_arr.c \
		ft_printf.c \
		ft_print_str.c \
		ft_print_const_str.c \
		ft_print_variable.c \
		ft_pad.c \
		print_char.c \
		print_str.c \
		print_pointer.c \
		print_number.c \
		print_hex.c \
		ft_replace.c \
		utils.c

OBJF := $(SRC:%.c=%.o)
OBJ  := $(addprefix obj/,$(OBJF))

# Colors

N :=\x1b[0m
G :=\x1b[32;01m
R :=\x1b[31;01m
B :=\x1b[43;01m
O :=\x1b[33;01m

$(NAME): $(OBJ)
	@ar -rcs $@ $^
	@echo "\n$B$@$N $Gcreated$N"

all: $(NAME)

obj/%.o:src/%.c
	@mkdir -p $(shell dirname $@)
	@echo "compiling" "$B$<$N..."
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo "$Rremoving libft object files...$N"
	@rm -rf obj
	@echo "$RDone$N\n"

fclean: clean
	@echo "$Rremoving $Olibft.a$R...$N"
	@rm -f $(NAME)
	@echo "$RDone$N\n"

re: fclean all

.PHONY: all bonus clean fclean re test
