/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:53:18 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/19 18:08:37 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_back(t_data *data, int h1, int h2, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < W_WIDTH)
	{
		y = h1;
		while (y < h2)
		{
			ft_pix_put(&data->back, x, y, color);
			y++;
		}
		x++;
	}
}

int	draw(t_data *data)
{
	init_image_back(data);
	draw_back(data, 0, W_HEIGHT / 2, data->map.c_color);
	draw_back(data, W_HEIGHT / 2, W_HEIGHT, data->map.f_color);
	raycasting(data);
	mlx_put_image_to_window(data->win.mlx, data->win.win,
		data->back.back_ptr, 0, 0);
	mlx_destroy_image(data->win.mlx, data->back.back_ptr);
	return (0);
}

void	graphics(t_data *data)
{
	init_mlx(data);
	init_ray_struct(data);
	init_texture_struct(data);
	draw(data);
	move(data);
}
