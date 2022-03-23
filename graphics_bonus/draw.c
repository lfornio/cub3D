/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:22:17 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/19 18:03:51 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_pix_put(t_back *back, int x, int y, int color)
{
	char	*pixel;

	pixel = back->addr + (y * back->size_line + x * (back->bpp / 8));
	*(int *)pixel = color;
}

void	draw_walls(t_data *data, int x)
{
	int	color;

	get_flag_wall(data);
	get_x_from_texture(data);
	while (data->ray.draw_start <= data->ray.draw_end)
	{
		data->tex.tex_y = (int)data->tex.tex_pos & (TEX - 1);
		data->tex.tex_pos += data->tex.step;
		color = get_color(data);
		ft_pix_put(&data->back, x, data->ray.draw_start, color);
		data->ray.draw_start++;
	}
}
