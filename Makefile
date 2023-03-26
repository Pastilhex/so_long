NAME	= so_long

NAME_BONUS	= so_long_bonus

CC		= cc

SRC		= main.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		move_player.c \
		events.c \
		map_gen.c\
		setup.c \
		map_check.c \
		map_utils.c \
		destroy.c

SRC_BONUS	= enemy.c

OBJS	= $(SRC:.c=.o)

CFLAGS	= -L./minilibx-linux -Wall -Werror -Wextra -g -lmlx -lXext -lX11 -lm -lbsd
#-03
RM 		= rm -f

all:
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)

bonus:
	$(CC) $(SRC) $(SRCB) $(CFLAGS) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

show:
	@printf "NAME  		: $(NAME)\n"
	@printf "NAME BONUS	: $(NAME_BONUS)\n"
	@printf "CC		: $(CC)\n"
	@printf "FLAGS		: $(CFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "SRC BONUS	: $(SRC_BONUS)\n"
	@printf "OBJS		: $(OBJS)\n"

PHONY: show fclean clean bonus all
