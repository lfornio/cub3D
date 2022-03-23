/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:05:56 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/19 18:13:44 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	distance_to_the_wall(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.perp_wall_dist = (data->ray.side_dist_x
				- data->ray.delta_dist_x);
	else
		data->ray.perp_wall_dist = (data->ray.side_dist_y
				- data->ray.delta_dist_y);
}

void	height_line(t_data *data)
{
	data->ray.line_height = (int)(W_HEIGHT / data->ray.perp_wall_dist);
	data->ray.draw_start = -data->ray.line_height / 2 + W_HEIGHT / 2;
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + W_HEIGHT / 2;
	if (data->ray.draw_end >= W_HEIGHT)
		data->ray.draw_end = W_HEIGHT - 1;
}
