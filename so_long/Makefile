NAME = so_long

CC = cc

CFLAGS = -g

SRC = main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	  srcs/ft_split.c

all: $(NAME)

$(NAME): header.h $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all