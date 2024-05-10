# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rboulaga <rboulaga@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 21:06:50 by rboulaga          #+#    #+#              #
#    Updated: 2024/05/10 18:40:38 by rboulaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror # -fsanitize=address
SRC = instructions.c\
	instructions_2.c\
	instructions_utils.c\
	push_swap.c\
	utils_push_swap.c\
	utils_push_swap_2.c\
	parsing.c\
	build_stack.c\
	first_step.c\
	hard_sort.c\
	principal_operation.c\

SRCBONUS = checker.c\
	utils_checker.c\
	instructions.c\
	instructions_2.c\
	utils_push_swap.c\
	utils_push_swap_2.c\
	parsing.c\
	build_stack.c\
	instructions_utils.c\
	get_next_line.c\
	get_next_line_utils.c\

OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

all: $(NAME)

bonus : $(CHECKER)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o push_swap

$(CHECKER) : $(OBJBONUS)
	$(CC) $(CFLAGS) $(OBJBONUS) -o checker

%.o : %.c
	$(CC) ${CFLAGS} -c  $< -o $@

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY :
