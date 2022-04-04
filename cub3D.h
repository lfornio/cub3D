/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:57:01 by mshad             #+#    #+#             */
/*   Updated: 2022/04/04 16:30:16 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define W_WIDTH 	1920
# define W_HEIGHT	1080
# define TEX		512
# define MINI		9
# define PLAYER		3

// colors
# define RED		"\033[31;1m"
# define YELLOW		"\033[33;1m"
# define RESET		"\033[0m"
# define GREEN		"\033[32;1m"

// keys
# define W			13
# define A			0
# define S			1
# define D			2
# define LEFT		123
# define RIGHT		124
# define ESC		53

//move
# define STEP		0.1
# define ROT		0.05

typedef struct s_win
{
	void	*mlx;
	void	*win;
}	t_win;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
}	t_player;

typedef struct s_map
{
	char	**map_arr;
	int		f_color;
	int		c_color;
	char	*no_tex;
	char	*so_tex;
	char	*ea_tex;
	char	*we_tex ;
}	t_map;

typedef struct s_ray
{
	double	pl_x;
	double	pl_y;
	double	vec_x;
	double	vec_y;
	double	plane_x;
	double	plane_y;
	double	ray_vec_x;
	double	ray_vec_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_back
{
	void	*back_ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_back;

typedef struct s_img
{
	void	*img_ptr;
	int		*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_tex
{
	t_img	tex_arr[4];
	int		tex_num;
	int		tex_flag;
	int		tex_x;
	int		tex_y;
	double	wall_x;
	double	step;
	double	tex_pos;
}	t_tex;

typedef struct s_data
{
	t_win		win;
	t_player	player;
	t_map		map;
	t_ray		ray;
	t_back		back;
	t_tex		tex;

}	t_data;

/*--------------------parsing-----------------------*/

int		main(int argc, char **argv);
t_data	*init_data(void);
void	free_data(t_data *data);
void	read_and_parse_file(t_data *data, const char *map_file);
void	error_exit(char *str);
void	parser_line(t_data *data, char *line);
void	parse_map(t_data *data, char *line);
void	check_file_format(const char *map_path, int fd);
int		check_tex_and_color(t_data *data, char *line);
int		parse_textures(t_data *data, char *str);
void	parsing_tex(t_data *data, char *str);
void	check_tex(char *str);
int		parse_colors(t_data *data, char *str);
int		ft_natoi(const char *str, int len);
int		color_converting(char *str);
void	free_str_arr(char **str_arr);
void	check_map(t_data *data);
void	check_sympols(char **map);
void	check_player(t_data *data);
void	check_borders(char **map, int i);
int		get_height_arr(char **arr);
int		valid_symbol(char **arr, int i, int j, char s);
void	check_uncorrect_postion(t_data *data, char s);

/*--------------------graphics-----------------------*/

void	graphics(t_data *data);
void	init_ray_struct(t_data *data);
void	init_texture_struct(t_data *data);
void	init_mlx(t_data *data);
void	move(t_data *data);
void	ft_pix_put(t_back *back, int x, int y, int color);
void	raycasting(t_data *data);
void	print_line(t_data *data, int x);
void	steps(int key, t_data *data);
int		draw(t_data *data);
void	rotations(int key, t_data *data);
void	draw_walls(t_data *data, int x);
void	init_image_back(t_data *data);
void	height_line(t_data *data);
void	get_flag_wall(t_data *data);
void	get_x_from_texture(t_data *data);
int		get_color(t_data *data);
void	distance_to_the_wall(t_data *data);

/*-------------------bonus------------------------*/

void	draw_mini_map(t_data *data);
void	draw_player(t_data *data);
int		error_mini_map(t_data *data);

#endif
