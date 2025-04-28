NAME = push_swap

CC = gcc
FLAGS = -g3 -Wall -Wextra -Werror
RM = rm -f
INCLUDES = -I ./includes

FILES = argv_check_utils \
		init_utils \
		move_b \
		sort_utils \
		stack_operations \
		cost_utils \
		main \
		parse_argument \
		split \
		targeting \
		final_sort \
		move_ab \
		rotation \
		stack_moves_a \
		utils \
		free_utils \
		move_a \
		simple_sort \
		stack_moves_b

SRCS = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix src/, $(addsuffix .o, $(FILES)))

# === RULES ===
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

src/%.o: src/%.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

