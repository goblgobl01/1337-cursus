NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c ft_lstsize.c lstclear.c push.c rotate.c swap.c \
	  algorithms.c ft_lstadd_front_bonus.c ft_split.c lstaddback.c lstnew.c \
	  push_swap.c rrotate.c

all: $(NAME)

$(NAME): header.h $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)