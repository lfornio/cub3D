NAME		= 	cub3D
SRCS		= 	cub3D.c \
				parsing/parsing.c \
				parsing/error.c \
				parsing/free_all.c \
				graphics/graphics.c \
				graphics/move.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c
CC 			= 	gcc
FLAGS		=	-g -Wall -Wextra -Werror
INCLUDES	=	cub3D.h
OBJS		=	$(SRCS:.c=.o)
LIBFT_A		=   libft/libft.a

.c.o: $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@

${NAME}: $(OBJS) $(INCLUDE)
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) $(OBJS) $(LIBFT_A) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all : libft $(NAME)

clean :
	make -C libft clean
	rm -f $(OBJS)


fclean : clean
	rm -f libft/libft.a
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
