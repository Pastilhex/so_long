NAME = so_long

NAME_BONUS = so_long_bonus

CC = cc

GNL = ./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c

SRC	= $(wildcard *.c)

SRC_BONUS = $(wildcard fbonus/*.c)

CFLAGS = -L ./minilibx-linux -Wall -Werror -Wextra -g -lmlx -lXext -lX11 -lm -lbsd

RM = rm -f

all:
	$(MAKE) -C ./minilibx-linux
	$(CC) $(SRC) $(GNL) $(CFLAGS) -o $(NAME)

bonus:
	$(CC) $(SRC_BONUS) $(GNL) $(CFLAGS) -o $(NAME_BONUS)

clean:
	$(MAKE) clean -C ./minilibx-linux 
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME_BONUS)

re: fclean all

show:
	@printf "CC		: $(CC)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "NAME BONUS	: $(NAME_BONUS)\n"
	@printf "CLEAN		: $(RM)\n"
	@printf "FLAGS		: $(CFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "SRC BONUS	: $(SRC_BONUS)\n"

PHONY: show fclean bonus clean all
