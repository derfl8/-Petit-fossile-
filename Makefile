CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
NAME		= minishell
HEADER		= header/parser.h
LIBFT_PATH	= libft/
LIBFT		= libft/libft.a
SRCS		=				\
parser/parser_utils.c		\
parser/parser.c				\
parser/cmd_tree_utils.c		\
parser/lexer.c				\
header/parser.h				\

OBJS    = $(SRCS:.c=.o)

all: $(NAME) $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -o $(NAME) $(LIBFT)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
