NAME = libftprintf.a

SRCS = ft_putchar.c ft_printf.c 

CC = cc

CFLAGS = -Wall -Werror -Wextra

OBJECT_FILES = $(patsubst %.c,%.o,$(SRCS))

BONUS_OBJECT_FILES = $(patsubst %.c,%.o,$(BONUS))

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	ar -rcs $(NAME) $(OBJECT_FILES)

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: .bonus_f

.bonus_f: $(BONUS_OBJECT_FILES)
	ar -rcs $(NAME) $(BONUS_OBJECT_FILES)
	@touch .bonus_f

clean:
	rm -f $(OBJECT_FILES) $(BONUS_OBJECT_FILES) .bonus_f

fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: clean