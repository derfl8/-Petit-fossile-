NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCE =	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itohex.c \
			ft_lltoa.c \
			ft_ulltohex.c

OBJECTS = $(SOURCE:.c=.o)

SOURCE_BONUS =	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \

OBJECTS_BONUS = $(SOURCE_BONUS:.c=.o)



all : $(NAME)

$(NAME) : $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)	#'c' creates archive if needed, 'r' replace old member if updated

%.o : %.c
	$(CC) $(CFLAGS) $^ -o $@ -c	#'$^' outputs all prerequisites

clean :
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

bonus : all $(OBJECTS_BONUS)
	ar -rc $(NAME) $(OBJECTS_BONUS)

.PHONY : clean fclean re all bonus
