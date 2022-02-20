/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:54:06 by lfornio           #+#    #+#             */
/*   Updated: 2022/02/20 19:09:31 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void esc_exit(t_data *data)
{
	mlx_destroy_window(data->win_struct->mlx_ptr_window, data->win_struct->win_ptr_window);
	exit(0);
}
// void ft_destroy(char *str, t_data *data, int *x)
// {
// 	int i;
// 	i = 0;

// 	while (str[i])
// 	{
// 		mlx_destroy_image(data->win_struct->mlx_ptr_window, data->win_struct->win_ptr_window);
// 		*x += STEP;
// 		i++;
// 	}
// 	*x = 0;
// }

// void remove_image(t_data *data)
// {
// 	char **tab;
// 	tab = data->map_struct->map;
// 	int i;
// 	int x;
// 	int y;

// 	x = 0;
// 	y = 0;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		ft_destroy(tab[i], data, &x);
// 		y += STEP;
// 		i++;
// 	}
// }

int look(int key, t_data *data)
{
	if (key == 53)
		esc_exit(data);
	// if (key == 123)
	// {
	// 	data->player_struct->vector -= (PI / 3) / data->win_struct->width_window;
	// }
	// if (element_count(mlx, 'P') == 1)
	// {
	// 	mlx->p.x = pos_player_x(mlx->tab, 'P');
	// 	mlx->p.y = pos_player_y(mlx->tab, 'P');
	// 	if (key == 2)
	// 		step_count(mlx, mlx->p.y, mlx->p.x + 1);
	// 	else if (key == 0)
	// 		step_count(mlx, mlx->p.y, mlx->p.x - 1);
	// 	else if (key == 1)
	// 		step_count(mlx, mlx->p.y + 1, mlx->p.x);
	// 	else if (key == 13)
	// 		step_count(mlx, mlx->p.y - 1, mlx->p.x);
	// 	if (mlx->p.cake == mlx->cake && element_count(mlx, 'E') == 1)
	// 	{
	// 		mlx->p.x_ex = pos_player_x(mlx->tab, 'E');
	// 		mlx->p.y_ex = pos_player_y(mlx->tab, 'E');
	// 		mlx->tab[mlx->p.y_ex][mlx->p.x_ex] = 'F';
	// 	}
	// mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	// remove_image(data);
	// mlx_destroy_window(data->win_struct->mlx_ptr_window, data->win_struct->win_ptr_window);
	// graphics(data);
	// }

	return (0);
}

void move(t_data *data)
{
	mlx_hook(data->win_struct->win_ptr_window, 2, 1L << 0, look, data);
	// mlx_hook(mlx->win_ptr, 17, 1L << 0, step_exit, mlx);
	// mlx_loop(mlx->mlx_ptr);

	mlx_loop(data->win_struct->mlx_ptr_window); //ждем дейсвий
}
