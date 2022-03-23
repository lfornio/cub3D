/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:32:35 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/21 14:52:50 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_step(t_data *data, double v_x, double v_y)
{
	if (data->map.map_arr[(int)data->ray.pl_y]
		[(int)(data->ray.pl_x + v_x * (STEP + 0.25))] != '1')
		data->ray.pl_x += v_x * STEP;
	if (data->map.map_arr[(int)(data->ray.pl_y + v_y * (STEP + 0.25))]
		[(int)data->ray.pl_x] != '1')
		data->ray.pl_y += v_y * STEP;
}

void	steps(int key, t_data *data)
{
	if (key == D)
		make_step(data, data->ray.plane_x, data->ray.plane_y);
	else if (key == A)
		make_step(data, -data->ray.plane_x, -data->ray.plane_y);
	else if (key == S)
		make_step(data, -data->ray.vec_x, -data->ray.vec_y);
	else if (key == W)
		make_step(data, data->ray.vec_x, data->ray.vec_y);
}
