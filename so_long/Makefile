NAME = so_long

CC = cc

# LFLAG= -Iinclude -framework Cocoa -framework OpenGL -framework IOKit
# MLX=  -Iinclude/mlx42 MLX/build/libmlx42.a MLX/build/libglfw3.a
# mlx.c
# $(LFLAG) $(MLX)

SRC = main.c map_parsing.c extras.c  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	  srcs/ft_split.c

all: $(NAME)

$(NAME): header.h $(SRC)
	$(CC) -g $(SRC) -o $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all