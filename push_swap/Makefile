# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smercado <smercado@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 16:23:55 by smercado          #+#    #+#              #
#    Updated: 2024/10/31 11:53:46 by smercado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEAD = push_swap.h
SRC = main.c errors.c calculs.c utils.c rotate.c swap.c reverse.c start_sortation.c\
	utils_sort.c push.c make_order.c choose_sort.c

LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

OBJS = ${SRC:.c=.o}

AR = ar rcs
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RANLIB = ranlib

all : subsystems $(NAME)

$(NAME): $(OBJS) $(HEAD) Makefile
		$(CC) $(CFLAGS) $(OBJS)	$(LIBFT_LIB) -o $(NAME)

%.o : %.c $(HEAD) Makefile
		$(CC) $(CFLAGS) -I. -c -o $@ $<

subsystems:
	@make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
