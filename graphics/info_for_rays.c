/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_for_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:52:03 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/19 18:08:59 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_direction_start(t_data *data)
{
	if (data->player.dir == 'N')
	{
		data->ray.vec_x = 0;
		data->ray.vec_y = -1;
	}
	else if (data->player.dir == 'S')
	{
		data->ray.vec_x = 0;
		data->ray.vec_y = 1;
	}
	else if (data->player.dir == 'E')
	{
		data->ray.vec_x = 1;
		data->ray.vec_y = 0;
	}
	else if (data->player.dir == 'W')
	{
		data->ray.vec_x = -1;
		data->ray.vec_y = 0;
	}
}

void	init_fov(t_data *data)
{
	if (data->player.dir == 'N')
	{
		data->ray.plane_x = 0.66;
		data->ray.plane_y = 0;
	}
	else if (data->player.dir == 'S')
	{
		data->ray.plane_x = -0.66;
		data->ray.plane_y = 0;
	}
	else if (data->player.dir == 'E')
	{
		data->ray.plane_x = 0;
		data->ray.plane_y = 0.66;
	}
	else if (data->player.dir == 'W')
	{
		data->ray.plane_x = 0;
		data->ray.plane_y = -0.66;
	}
}

void	init_ray_struct(t_data *data)
{
	data->ray.pl_x = (double)data->player.x + 0.5;
	data->ray.pl_y = (double)data->player.y + 0.5;
	init_ray_direction_start(data);
	init_fov(data);
	data->ray.ray_vec_x = 0;
	data->ray.ray_vec_y = 0;
	data->ray.side_dist_x = 0;
	data->ray.side_dist_y = 0;
	data->ray.delta_dist_x = 0;
	data->ray.delta_dist_y = 0;
	data->ray.perp_wall_dist = 0;
	data->ray.map_x = 0;
	data->ray.map_y = 0;
	data->ray.step_x = 0;
	data->ray.step_y = 0;
	data->ray.side = 0;
	data->ray.line_height = 0;
	data->ray.draw_start = 0;
	data->ray.draw_end = 0;
}
