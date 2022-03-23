/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:06:15 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/19 18:12:45 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_direction(t_data *data, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)W_WIDTH - 1;
	data->ray.ray_vec_x = data->ray.vec_x + data->ray.plane_x * camera_x;
	data->ray.ray_vec_y = data->ray.vec_y + data->ray.plane_y * camera_x;
	data->ray.map_x = (int)data->ray.pl_x;
	data->ray.map_y = (int)data->ray.pl_y;
}

void	distance_between_lines(t_data *data)
{
	if (data->ray.ray_vec_x)
		data->ray.delta_dist_x = fabs(1 / data->ray.ray_vec_x);
	if (data->ray.ray_vec_y)
		data->ray.delta_dist_y = fabs(1 / data->ray.ray_vec_y);
}

void	steps_and_start_distance(t_data *data)
{
	if (data->ray.ray_vec_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->ray.pl_x - data->ray.map_x)
			* data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->ray.map_x + 1.0 - data->ray.pl_x)
			* data->ray.delta_dist_x;
	}
	if (data->ray.ray_vec_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->ray.pl_y - data->ray.map_y)
			* data->ray.delta_dist_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->ray.map_y + 1.0 - data->ray.pl_y)
			* data->ray.delta_dist_y;
	}
}

void	flag_wall(t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.side = 1;
		}
		if (data->map.map_arr[data->ray.map_y][data->ray.map_x] == '1')
			hit = 1;
	}
}

void	raycasting(t_data *data)
{
	int	i;

	i = 0;
	while (i < W_WIDTH)
	{
		ray_direction(data, i);
		distance_between_lines(data);
		steps_and_start_distance(data);
		flag_wall(data);
		distance_to_the_wall(data);
		height_line(data);
		draw_walls(data, i);
		i++;
	}
}
