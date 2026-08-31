# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smasatak <smasatak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/25 20:57:08 by smasatak          #+#    #+#              #
#    Updated: 2026/08/26 18:05:04 by smasatak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = get_next_line
BUFFER_SIZE = 42
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=$(BUFFER_SIZE)

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean :clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
