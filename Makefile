SRCS_B = checker_bonus.c swap_op.c rotate_n_rev.c push_pop.c utils.c get_next_line_bonus.c \
	 get_next_line_utils_bonus.c parse_args.c check_args.c ft_split.c utils.c \
	ft_lstclear.c utils.c utils_bonus.c
OBJS_B = $(SRCS_B:.c=.o)

SRCS = main.c utils.c sorting.c utils.c push_pop.c \
		 parse_args.c max_min.c swap_op.c \
		 rotate_n_rev.c is_cheaper.c perform_op.c \
		 sort_rest_3.c find_cheaper.c check_args.c \
		 utils_bonus.c ft_split.c utils2.c ft_lstclear.c
OBJS := $(SRCS:.c=.o)
NAME := push_swap
FLAGS := -Wall -Wextra -Werror
NAME_B = checker

all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $^ -o $@

$(NAME_B) : $(OBJS_B)
	cc $(FLAGS) $^ -o $@

%.o: %.c pushswap.h
	cc $(FLAGS) -c $< -o $@

bonus : $(NAME_B)

clean:
	rm -f $(OBJS) $(OBJS_B)
fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all
