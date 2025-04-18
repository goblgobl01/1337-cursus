NAME = mini_shell

CC = cc

CFLAGS = -Wall -Werror -Wextra -lreadline -g

SRC = main.c ast_function.c ft_substr.c custom_split.c ft_strdup.c ft_strlen.c

all: $(NAME)

$(NAME): header.h $(SRC)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)

clean:

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all