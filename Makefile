CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
NAME		= minishell
HEADER		= header/builtin.h
LIBFT_PATH	= libft/
LIBFT		= libft/libft.a
READLINE	= -l readline
SRCS		=				\
builtin/custom_libft.c		\
builtin/lst_tools.c			\
builtin/pwd.c				\
builtin/env.c				\
builtin/echo.c				\
builtin/main.c				\
builtin/exit.c				\
builtin/cd.c				\
builtin/unset.c				\
builtin/export.c			\
builtin/exp_no_arg.c		\
parser/parser_utils.c		\
parser/parser.c				\
parser/cmd_tree_utils.c		\
parser/lexer.c				\
header/parser.h				\
parser/dynamic_arg_table.c	\

OBJS    = $(SRCS:.c=.o)

all: $(NAME) $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -o $(NAME) $(LIBFT) $(READLINE)

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
