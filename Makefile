NAME	= so_long
CC		= cc
SRC		= main.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		move_player.c \
		events.c \
		map_gen.c\
		setup.c \
		map.c \
		map_check.c
OBJS	= $(SRC:.c=.o)
CFLAGS	= -L./minilibx-linux -Wall -Werror -Wextra -O0 -g -lmlx -lXext -lX11 -lm -lbsd
RM 		= rm -f

all:
	$(CC) $(SRC) $(CFLAGS) -o so_long

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

show:
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "FLAGS		: $(FLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "OBJS		: $(OBJS)\n"

PHONY: show fclean clean all
