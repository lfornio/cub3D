/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:10:58 by lfornio           #+#    #+#             */
/*   Updated: 2022/02/04 12:53:34 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

#define STEP 64
#define PI 3.14159265359

typedef struct s_window   //структура для окна
{
	int		width_window;
	int		height_window;
	void	*mlx_ptr_window;
	void	*win_ptr_window;

}	t_window;

typedef struct s_map   //структура для карты
{
	int		width_map;
	int		height_map;
	char	**map;

}	t_map;

typedef struct s_pos   //структура исходной позиции
{
	int		x;
	int		y;

}	t_pos;

typedef struct s_player   //структура игрока
{
	t_pos		pos;
	float		pl_x;
	float		pl_y;
	float		vector;

}	t_player;






typedef struct s_data
{
	t_window *win_struct; //структура для окна
	t_map *map_struct; //структура для карты
	t_player *player_struct;


}	t_data;



void	error(const char *s);
void	error_file(const char *name_file);
void parsing(t_data *data, char *map);
void free_all(t_data *data);
void graphics(t_data *data);



#endif
