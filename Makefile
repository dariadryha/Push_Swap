#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddryha <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/02 14:20:41 by ddryha            #+#    #+#              #
#    Updated: 2018/03/02 14:20:42 by ddryha           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME1 = checker
NAME2 = push_swap
CC = gcc -Wall -Werror -Wextra
RM = rm -rf
HEADER = push_swap.h
LIBDIR = ./libft
SRC = ft_apply_sorting.c ft_check_arg.c ft_exec_flags.c ft_manage_stack.c \
		ft_mid_stack.c ft_push_rotate.c ft_sort_stack.c \
		ft_support_func_checker.c ft_swap_reverse.c ft_valid_sort.c \
		ft_sort_together.c ft_support_func_push.c ft_check_reverse_stack.c\

SRC1 = checker.c
SRC2 = ft_push_swap.c 
OBJ1 = $(SRC1:.c=.o) $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o) $(SRC:.c=.o)

all: $(NAME1) $(NAME2)

OBJ1: $(SRC1) $(SRC) push_swap.h
	$(CC) $(SRC1) $(SRC) $(HEADER) -c

OBJ2: $(SRC2) $(SRC) push_swap.h
	$(CC) $(SRC2) $(SRC) $(HEADER) -c

$(NAME2): $(OBJ2) $(HEADER)
	@make -C $(LIBDIR)
	$(CC) -o $(NAME2) $(OBJ2) -I.$(HEADER) $(LIBDIR)/libftprintf.a

$(NAME1):  $(OBJ1) $(HEADER)
	@make -C $(LIBDIR)
	$(CC) -o $(NAME1) $(OBJ1) -I.$(HEADER) $(LIBDIR)/libftprintf.a

clean:
	@make clean -C $(LIBDIR)
	$(RM) $(OBJ1) $(OBJ2)

fclean: clean
	@make fclean -C $(LIBDIR)
	$(RM) $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
