/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:54:03 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/19 18:15:57 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_from_texture(t_img *img, int x, int y)
{
	int	color;

	color = img->addr[y * TEX + x];
	return (color);
}

int	get_color(t_data *data)
{
	int	color;

	color = color_from_texture(data->tex.tex_arr[data->tex.tex_flag].img_ptr,
			data->tex.tex_x, data->tex.tex_y);
	return (color);
}

void	get_x_from_texture(t_data *data)
{
	if (data->ray.side == 0)
		data->tex.wall_x = data->ray.pl_y + data->ray.perp_wall_dist
			* data->ray.ray_vec_y;
	else
		data->tex.wall_x = data->ray.pl_x + data->ray.perp_wall_dist
			* data->ray.ray_vec_x;
	data->tex.wall_x -= floor((data->tex.wall_x));
	data->tex.tex_x = (int)(data->tex.wall_x * (double)TEX);
	if (data->ray.side == 0 && data->ray.ray_vec_x > 0)
		data->tex.tex_x = TEX - data->tex.tex_x - 1;
	if (data->ray.side == 1 && data->ray.ray_vec_y < 0)
		data->tex.tex_x = TEX - data->tex.tex_x - 1;
	data->tex.step = (double)TEX / data->ray.line_height;
	data->tex.tex_pos = (data->ray.draw_start - W_HEIGHT / 2
			+ data->ray.line_height / 2) * data->tex.step;
}

void	get_flag_wall(t_data *data)
{
	if (data->ray.side == 1)
	{
		if (data->ray.ray_vec_y > 0)
			data->tex.tex_flag = 0;
		else if (data->ray.ray_vec_y < 0)
			data->tex.tex_flag = 1;
	}
	else if (data->ray.side == 0)
	{
		if (data->ray.ray_vec_x > 0)
			data->tex.tex_flag = 2;
		else if (data->ray.ray_vec_x < 0)
			data->tex.tex_flag = 3;
	}
}
