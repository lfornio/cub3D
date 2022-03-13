/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:31:34 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/13 17:37:52 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


void many_rays_direction(t_data *data, int x)
{
	double cameraX;

	cameraX = 2 * x / (double)WIDTH - 1;
	data->ray->ray_vec_x = data->ray->vec_x + data->ray->plane_x * cameraX;
	data->ray->ray_vec_y = data->ray->vec_y + data->ray->plane_y * cameraX;
}

void found_now_position_of_the_ray_on_the_map(t_data *data)
{
	data->ray->map_x = (int)data->plr->pl_x;
	data->ray->map_y = (int)data->plr->pl_y;
}

void distance_between_lines(t_data *data)
{
	if (data->ray->ray_vec_x)
		data->ray->delta_dist_x = fabs(1 / data->ray->ray_vec_x);
	else
		data->ray->delta_dist_x = 1e30;

	if (data->ray->ray_vec_y)
		data->ray->delta_dist_y = fabs(1 / data->ray->ray_vec_y);
	else
		data->ray->delta_dist_y = 1e30;
}

void steps_and_start_distance(t_data *data)
{
	if (data->ray->ray_vec_x < 0)
	{
		data->ray->step_x = -1;
		data->ray->side_dist_x = (data->plr->pl_x - data->ray->map_x) * data->ray->delta_dist_x;
	}
	else
	{
		data->ray->step_x = 1;
		data->ray->side_dist_x = (data->ray->map_x + 1.0 - data->plr->pl_x) * data->ray->delta_dist_x;
	}
	if (data->ray->ray_vec_y < 0)
	{
		data->ray->step_y = -1;
		data->ray->side_dist_y = (data->plr->pl_y - data->ray->map_y) * data->ray->delta_dist_y;
	}
	else
	{
		data->ray->step_y = 1;
		data->ray->side_dist_y = (data->ray->map_y + 1.0 - data->plr->pl_y) * data->ray->delta_dist_y;
	}
}
void flag_to_the_wall(t_data *data)
{
	int hit;
	hit = 0;
	while (hit == 0)
	{
		if (data->ray->side_dist_x < data->ray->side_dist_y)
		{
			data->ray->side_dist_x += data->ray->delta_dist_x;
			data->ray->map_x += data->ray->step_x;
			data->ray->side = 0;
		}
		else
		{
			data->ray->side_dist_y += data->ray->delta_dist_y;
			data->ray->map_y += data->ray->step_y;
			data->ray->side  = 1;
		}
		if (data->map->tab[data->ray->map_y][data->ray->map_x] == '1')
			hit = 1;
	}
}
void distance_to_the_wall(t_data *data)
{
	if (data->ray->side == 0)
		data->ray->perp_wall_dist = (data->ray->side_dist_x - data->ray->delta_dist_x);
	else
		data->ray->perp_wall_dist = (data->ray->side_dist_y - data->ray->delta_dist_y);
}

void print_line(t_data *data, int x)
{
	int drawStart;
	int drawEnd;
	drawStart = -data->ray->line_height / 2 + HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = data->ray->line_height / 2 + HEIGHT / 2;
	if (drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;
	while(drawStart <= drawEnd)
	{
		img_pix_put(&data->images->fon, x, drawStart, 0xFF0096);
		drawStart++;
	}
}

void raycasting(t_data *data)
{

	int i;
	i = 0;
	while (i < WIDTH)
	{
		many_rays_direction(data, i);
		found_now_position_of_the_ray_on_the_map(data);
		distance_between_lines(data);
		steps_and_start_distance(data);
		flag_to_the_wall(data);
		distance_to_the_wall(data);
		data->ray->line_height = (int)(HEIGHT / data->ray->perp_wall_dist);
		// print_line(data, i);
		print_texture(data, i);
		i++;
	}
}
