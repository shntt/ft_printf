# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shitakah <shitakah@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/07 23:42:17 by shitakah          #+#    #+#              #
#    Updated: 2025/11/13 22:28:05 by shitakah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC		=	cc
AR		=	ar rcs
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I./includes
SRC		=	srcs/ft_printf.c \
			srcs/putchar_len.c \
			srcs/puthex_len.c \
			srcs/putnbr_len.c \
			srcs/putptr_len.c \
			srcs/putstr_len.c \
			srcs/putunbr_len.c \

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ) $(SOBJS)

fclean: clean
	rm -f $(NAME) libft.so

re: fclean all

.PHONY: all clean fclean re
