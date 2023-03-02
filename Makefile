NAME		= main
CC 			= cc
FLAGS	 	= $(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
OBJS		= $(SRCS:.c=.o)

all:
BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS		= $(BONUS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
NAME			= libft.a
all:			$(NAME)
$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
clean:
				$(RM) $(OBJS) $(BONUS_OBJS)
fclean:			clean
				$(RM) $(NAME) a.out libft.so
re:				fclean $(NAME)
bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
so:		
				$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
				clang -nostartfiles -shared -o libft.so $(OBJS)
.PHONY:			all clean fclean re bonus