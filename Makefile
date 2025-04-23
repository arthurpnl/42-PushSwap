NAME	= push_swap

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

RM		= rm -f

FILES	= $(wildcard src/*.c)

OBJS	= $(FILES:.c=.o)

.c.o:
	@$(CC) $(FLAGS) -c $< -o $@ -I ./include

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
all :		$(NAME)

clean :
			@$(RM) $(OBJS)

fclean :	clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re