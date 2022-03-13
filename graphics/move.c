/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:54:06 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/13 14:30:33 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void esc_exit(t_data *data)
{
	mlx_destroy_window(data->win->mlx_ptr_win, data->win->win_ptr_win);
	exit(0);
}

void rotation(t_data *data, double angle)
{
	double old_vec_x;
	double old_plane_x;

	old_vec_x = data->ray->vec_x;
	data->ray->vec_x = data->ray->vec_x * cos(angle) - data->ray->vec_y * sin(angle);
	data->ray->vec_y = old_vec_x * sin(angle) + data->ray->vec_y * cos(angle);
	old_plane_x = data->ray->plane_x;
	data->ray->plane_x = data->ray->plane_x * cos(angle) - data->ray->plane_y * sin(angle);
	data->ray->plane_y = old_plane_x * sin(angle) + data->ray->plane_y * cos(angle);
}

void change_fov(int key, t_data *data)
{
	if (key == 123)
		rotation(data, -ROTATION);
	else if (key == 124)
		rotation(data, ROTATION);
	mlx_destroy_image(data->win->mlx_ptr_win, data->images->fon.fon_img_ptr);
	graphics(data);
}

void make_step(t_data *data, double v_x, double v_y)
{
	if (data->map->tab[(int)data->plr->pl_y][(int)(data->plr->pl_x + v_x * STEP)] != '1')
		data->plr->pl_x += v_x * STEP;
	if (data->map->tab[(int)(data->plr->pl_y + v_y * STEP)][(int)data->plr->pl_x] != '1')
		data->plr->pl_y += v_y * STEP;
}

void change_position(int key, t_data *data)
{
	if (key == 2) //D
		make_step(data, data->ray->plane_x, data->ray->plane_y);
	else if (key == 0) //A
		make_step(data, -data->ray->plane_x, -data->ray->plane_y);
	else if (key == 1) //S
		make_step(data, -data->ray->vec_x, -data->ray->vec_y);
	else if (key == 13) //W
		make_step(data, data->ray->vec_x, data->ray->vec_y);
	mlx_destroy_image(data->win->mlx_ptr_win, data->images->fon.fon_img_ptr);
	graphics(data);
}
int	step_exit(int key, t_data *data)
{
	(void)key;
	(void)data;
	exit(0);
}

int to_look_to_go(int key, t_data *data)
{
	if (key == 53)
		esc_exit(data);
	else if (key == 123 || key == 124)
		change_fov(key, data);
	else if (key == 2 || key == 0 || key == 1 || key == 13)
		change_position(key, data);
	return (0);
}

void move(t_data *data)
{
	mlx_hook(data->win->win_ptr_win, 2, 1L << 0, to_look_to_go, data);
	mlx_hook(data->win->win_ptr_win, 17, 1L << 0, step_exit, data);
	mlx_loop(data->win->mlx_ptr_win); //ждем дейсвий
}
