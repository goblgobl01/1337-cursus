# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaarafi <mmaarafi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 18:34:59 by yazan             #+#    #+#              #
#    Updated: 2025/03/20 20:32:57 by mmaarafi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME_CLIENT = client
NAME_SERVER = server

SRC_CLIENT = client.c ft_atoi.c
SRC_SERVER = server.c ft_itoa.c ft_strlen.c

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): header.h $(SRC_CLIENT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER): header.h $(SRC_SERVER)
	$(CC) $(CFLAGS) $(SRC_SERVER) -o $(NAME_SERVER)

clean:

fclean: clean
	rm -rf $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: clean fclean all