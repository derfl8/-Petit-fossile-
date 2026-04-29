CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
NAME	= minishell
HEADER	= header/minishell.h
SRCS	=					\
builtin/custom_libft.c		\
builtin/lst_tools.c			\
builtin/libft.c				\
builtin/pwd_env.c			\
builtin/echo.c				\
builtin/main.c				\
builtin/exit.c				\

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
