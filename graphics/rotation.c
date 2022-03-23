/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:46:54 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/19 18:14:22 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotation(t_data *data, double angle)
{
	double	old_vec_x;
	double	old_plane_x;

	old_vec_x = data->ray.vec_x;
	data->ray.vec_x = data->ray.vec_x * cos(angle)
		- data->ray.vec_y * sin(angle);
	data->ray.vec_y = old_vec_x * sin(angle)
		+ data->ray.vec_y * cos(angle);
	old_plane_x = data->ray.plane_x;
	data->ray.plane_x = data->ray.plane_x * cos(angle)
		- data->ray.plane_y * sin(angle);
	data->ray.plane_y = old_plane_x * sin(angle)
		+ data->ray.plane_y * cos(angle);
}

void	rotations(int key, t_data *data)
{
	if (key == LEFT)
		rotation(data, -ROT);
	else if (key == RIGHT)
		rotation(data, ROT);
}
