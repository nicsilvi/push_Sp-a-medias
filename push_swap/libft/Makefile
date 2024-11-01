# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smercado <smercado@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 16:23:55 by smercado          #+#    #+#              #
#    Updated: 2024/10/26 12:32:47 by smercado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEAD = libft.h
BONUS = .bonus
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c\
			ft_isascii.c ft_isprint.c ft_strlen.c\
			ft_memset.c ft_bzero.c ft_memcpy.c\
			ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c\
			ft_memcmp.c ft_strnstr.c ft_atoi.c\
			ft_substr.c ft_strjoin.c ft_strtrim.c\
			ft_split.c ft_itoa.c ft_strmapi.c\
			ft_striteri.c ft_putstr_fd.c ft_strdup.c\
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
			ft_calloc.c get_next_line.c ft_printf.c hexa.c\
			numbers.c pointers.c unsigned.c ft_free.c ft_isdigit_str.c

OBJS = ${SRC:.c=.o}

SRCBONUS = ft_lstsize_bonus.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c

BONUSOBJS = ft_lstsize_bonus.o ft_lstnew_bonus.o ft_lstadd_front_bonus.o

TOUCH = touch
AR = ar rcs
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RANLIB = ranlib

all : $(NAME)

bonus: $(BONUS)

$(BONUS): $(HEAD) $(BONUSOBJS) $(OBJS)
	$(AR) $(NAME) $(BONUSOBJS)
	$(RANLIB) $(NAME)
	@$(TOUCH) $(BONUS)

$(NAME):	$(OBJS) $(HEAD) Makefile
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

%.o : %.c $(HEAD) Makefile
	$(CC) -I. $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
