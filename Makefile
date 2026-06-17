CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
NAME		= minishell
LIBFT_PATH	= libft/
LIBFT		= libft/libft.a
OBJPATH		= obj/
READLINE	= -l readline
SRCS		=				\
builtin/custom_libft.c		\
builtin/lst_tools.c			\
builtin/pwd.c				\
builtin/env.c				\
builtin/echo.c				\
builtin/exit.c				\
builtin/cd.c				\
builtin/cd_norm.c			\
builtin/unset.c				\
builtin/export.c			\
builtin/exp_no_arg.c		\
parser/parser_utils.c		\
parser/parser.c				\
parser/cmd_tree_utils.c		\
parser/lexer.c				\
parser/dynamic_arg_table.c	\
parser/quote_remover.c		\
parser/debug_parser.c		\
parser/free_cmd_tree.c		\
exec/exec_builtin.c			\
exec/path.c					\
exec/exec.c					\
signal/signal_handler.c		\
main.c

OBJS    = $(SRCS:%.c=$(OBJPATH)%.o)

all: $(NAME)

$(NAME): $(OBJPATH) $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIBFT) $(READLINE)

$(OBJPATH):
	mkdir -p $(OBJPATH) $(OBJPATH)/builtin $(OBJPATH)/parser $(OBJPATH)/exec $(OBJPATH)/signal

$(OBJPATH)%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C $(LIBFT_PATH)

clean:
	rm -rf $(OBJPATH)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
