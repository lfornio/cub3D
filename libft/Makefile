NAME = libft.a
HEAD = libft.h
LIST = ft_isalnum.c ft_isalpha.c ft_isdigit.c \
		ft_isascii.c ft_isprint.c ft_tolower.c ft_toupper.c \
		ft_strlen.c ft_memset.c ft_strncmp.c ft_strnstr.c \
		ft_bzero.c ft_strrchr.c ft_strchr.c ft_strlcat.c \
		ft_memcpy.c ft_strlcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_putchar_fd.c ft_strmapi.c \
		ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_strtrim.c \
		ft_itoa.c ft_split.c ft_strcpy.c ft_strcmp.c \
		get_next_line.c get_next_line_utils.c

OBJ = $(patsubst %.c, %.o, $(LIST))

OPTFLAGS = -O2
FLAGS = -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -I.

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	@ar rcs $(NAME) $?

%.o: %.c $(HEAD)
	@cc $(CFLAGS) $(OPTFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
	