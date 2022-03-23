NAME	= cub3D
HEADER	= cub3d.h

CC		= cc
FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -I. -Imlx -Ilibft
OPTFLAGS = -O2

SRC		= main.c \
			parsing/init_data.c \
			parsing/read_parse_file.c \
			parsing/parser_map.c \
			parsing/color.c \
			parsing/color2.c \
			parsing/texture.c \
			parsing/errors_parsing.c \
			parsing/check_map.c \
			graphics/graphics.c \
			graphics/raycasting_1.c \
			graphics/raycasting_2.c \
			graphics/info_for_rays.c \
			graphics/info_for_texture.c \
			graphics/init_mlx.c \
			graphics/move.c \
			graphics/draw.c \
			graphics/steps.c \
			graphics/rotation.c \
			graphics/texture.c \

SRC_BONUS	= main.c \
			parsing/init_data.c \
			parsing/read_parse_file.c \
			parsing/parser_map.c \
			parsing/color.c \
			parsing/color2.c \
			parsing/texture.c \
			parsing/errors_parsing.c \
			parsing/check_map.c \
			graphics_bonus/graphics.c \
			graphics_bonus/raycasting_1.c \
			graphics_bonus/raycasting_2.c \
			graphics_bonus/info_for_rays.c \
			graphics_bonus/info_for_texture.c \
			graphics_bonus/init_mlx.c \
			graphics_bonus/move.c \
			graphics_bonus/draw.c \
			graphics_bonus/steps.c \
			graphics_bonus/rotation.c \
			graphics_bonus/texture.c \
			graphics_bonus/mini_map.c \

ifeq ($(MAKECMDGOALS),bonus)
	OBJ = $(patsubst %.c, %.o, $(SRC_BONUS))
else
	OBJ = $(patsubst %.c, %.o, $(SRC))
endif

.PHONY:	all clean fclean re libft mlx

.o: .c $(HEADER)
	@ $(CC) $(CFLAGS) $(OPTFLAGS) -c $< -o $@

LIBFT_A		=   libft/libft.a

all:	mlx libft ${NAME}

$(NAME): $(OBJ) $(HEADER)
		@$(CC) $(OBJ) $(LIBFT_A) -Llibft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

bonus:	mlx libft $(NAME)


mlx:
		@make -C mlx/

libft:
		@make -C libft/

clean:
		@rm -f $(OBJ)
		@rm -f graphics_bonus/*.o
		@make -C libft clean
		@make -C mlx clean

fclean:	clean
		@rm -f ${NAME}
		@rm -f libft/libft.a
		@rm -f mlx/libmlx.a
		@rm -rf a.out*
		@rm -rf */a.out*
		@rm -rf *.gch
		@rm -rf */*.gch

re:		fclean all
