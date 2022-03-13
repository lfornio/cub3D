/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:10:58 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/13 17:34:00 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

#define ZOOM2D 6
#define TEXTURE 240
#define WIDTH 1920
#define HEIGHT 1080
#define STEP 0.2
#define ROTATION M_PI / 60

typedef struct s_win  //структура для окна
{
	void	*mlx_ptr_win;
	void	*win_ptr_win;

	int		width2d_win;
	int		height2d_win;
	void	*mlx2_ptr_win;
	void	*win2_ptr_win;
}	t_win;

typedef struct s_map   //структура для карты
{
	int		width_map;
	int		height_map;
	char	**tab;

}	t_map;

typedef struct s_pos   //структура исходной позиции
{
	int		x;
	int		y;

}	t_pos;

typedef struct s_plr   //структура игрока и луча
{
	t_pos		pos;
	double		pl_x;
	double		pl_y;
	// char		direction;
	double		vector;
	double		start;
	double		end;

}	t_player;

typedef struct s_fon_img
{
	void	*fon_img_ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_fon_img;

typedef struct s_image   //структура изображений
{
	t_fon_img fon;

}	t_image;

typedef struct s_ray
{
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
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int side;
	double perp_wall_dist ;
	int line_height ;


} t_ray;

typedef struct s_tex
{
	char *str_n;
	char *str_s;
	char *str_w;
	char *str_e;
	void *ptr_n;
	void *ptr_s;
	void *ptr_w;
	void *ptr_e;
	int **img_n;
	int **img_s;
	int **img_w;
	int **img_e;
	int tex_num;
	double wall_x;
	int tex_x;
	double step;
	double tex_pos;




} t_tex;






typedef struct s_data
{
	t_win *win; //структура для окна
	t_map *map; //структура для карты
	t_player *plr;  //структура для игрока и луча
	t_image *images;  //структура для изображений
	int *arr_distances;
	t_ray *ray;
	t_tex *tex;


}	t_data;



void	error(const char *s);
void	error_file(const char *name_file);
void	parsing(t_data *data, char *map);
void	free_all(t_data *data);
void	graphics(t_data *data);
void	print_player(t_data *data);
void	move(t_data *data);
void	img_pix_put(t_fon_img *fon, int x, int y, int color);
void	init_fon(t_data *data);
void	player_position_search(t_data *data);
void	init_arr_distances(t_data *data);
void	print2d(t_data *data);
void	raycasting(t_data *data);
void init_ray_struct(t_data *data);
void print_texture(t_data *data, int x);



#endif
