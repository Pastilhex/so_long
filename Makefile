NAME = so_long

NAME_BONUS = so_long_bonus

CC = cc

GNL = ./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c

SRC	= ./*.c

SRC_BONUS = $(wildcard fbonus/*.c)

CFLAGS = -L ./minilibx-linux -Wall -Werror -Wextra -g -lmlx -lXext -lX11 -lm -lbsd

RM = rm -f

all:
	$(CC) $(SRC) $(GNL) $(CFLAGS) -o $(NAME)

bonus:
	$(CC) $(SRC_BONUS) $(GNL) $(CFLAGS) -o $(NAME_BONUS)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME_BONUS)

re: fclean all

show:
	@printf "NAME  		: $(NAME)\n"
	@printf "NAME BONUS	: $(NAME_BONUS)\n"
	@printf "CC		: $(CC)\n"
	@printf "FLAGS		: $(CFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "SRC BONUS	: $(SRC_BONUS)\n"

PHONY: show fclean bonus clean all
