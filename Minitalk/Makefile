# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 18:34:59 by yazan             #+#    #+#              #
#    Updated: 2025/03/23 23:13:21 by mmaarafi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME_1 = client
NAME_2 = server

SRC_CLIENT = client.c ft_atoi.c
SRC_SERVER = server.c ft_itoa.c ft_strlen.c

all: $(NAME_1) $(NAME_2)

$(NAME_1): header.h $(SRC_CLIENT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(NAME_1)

$(NAME_2): header.h $(SRC_SERVER)
	$(CC) $(CFLAGS) $(SRC_SERVER) -o $(NAME_2)

clean:

fclean: clean
	rm -rf $(NAME_1) $(NAME_2)

re: fclean all

.PHONY: clean fclean all