# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucda-si <lucda-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 13:38:51 by lucda-si          #+#    #+#              #
#    Updated: 2024/11/20 12:46:42 by lucda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDES_DIR = .

SRCS = ft_printf.c ft_strchr.c ft_putchar.c ft_putstr.c \
ft_putadress.c ft_uitoa.c ft_putnbrhex.c ft_putpercent.c 

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean
	make

.PHONY: all clean fclean re