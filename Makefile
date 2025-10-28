# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shitakah <shitakah@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/07 23:42:17 by shitakah          #+#    #+#              #
#    Updated: 2025/10/29 02:14:13 by shitakah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
CC		=	cc
AR		=	ar rcs
CFLAGS	=	-Wall -Wextra -Werror

SRC		=	ft_printf.c \
			putchar_len.c \
			puthex_len.c \
			putnbr_len.c \
			putptr_len.c \
			putstr_len.c \
			putunbr_len.c \

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(SOBJS)

fclean: clean
	rm -f $(NAME) libft.so

re: fclean all

.PHONY: all clean fclean re
