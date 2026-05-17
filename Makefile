CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
NAME		= minishell
HEADER		= header/builtin.h
LIBFT_PATH	= libft/
LIBFT		= libft/libft.a
SRCS		=				\
builtin/custom_libft.c		\
builtin/lst_tools.c			\
builtin/pwd_env.c			\
builtin/echo.c				\
builtin/main.c				\
builtin/exit.c				\
builtin/cd.c				\

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
