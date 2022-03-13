/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:39:23 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/13 17:38:07 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void print_texture(t_data *data, int x)
{
	int drawStart;
	int drawEnd;
	drawStart = -data->ray->line_height / 2 + HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = data->ray->line_height / 2 + HEIGHT / 2;
	if (drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;
	// while(drawStart <= drawEnd)
	// {
	// 	img_pix_put(&data->images->fon, x, drawStart, 0xFF0096);
	// 	drawStart++;
	// }

	data->tex->tex_num = data->map->tab[data->ray->map_y][data->ray->map_x] - 1;
	if (data->ray->side == 0)
		data->tex->wall_x = data->plr->pl_y + data->ray->perp_wall_dist * data->ray->ray_vec_y;
	else
		data->tex->wall_x = data->plr->pl_x + data->ray->perp_wall_dist * data->ray->ray_vec_x;
	data->tex->wall_x -= floor((data->tex->wall_x));

	data->tex->tex_x = (int)(data->tex->wall_x * (double)TEXTURE);
	if (data->ray->side == 0 && data->ray->ray_vec_x > 0)
		data->tex->tex_x = TEXTURE - data->tex->tex_x - 1;
	if (data->ray->side == 1 && data->ray->ray_vec_y < 0)
		data->tex->tex_x = TEXTURE - data->tex->tex_x - 1;

	data->tex->step = 1.0 * TEXTURE / data->ray->line_height;
	data->tex->tex_pos = (drawStart - HEIGHT / 2 + data->ray->line_height / 2) * data->tex->step;

	int buf[HEIGHT][WIDTH];
	for (int y = drawStart; y < drawEnd; y++)
	{
		int texY = (int)data->tex->tex_pos & (TEXTURE - 1);
		data->tex->tex_pos += data->tex->step;
		int color = data->tex->img_n[data->tex->tex_num ][TEXTURE * texY + data->tex->tex_x];
		if (data->ray->side == 1)
			color = (color >> 1) & 8355711;
		buf[y][x] = color;
	}
	// while(drawStart <= drawEnd)
	// {
	// 	img_pix_put(&data->images->fon, x, drawStart, buf[1][1]);
	// 	drawStart++;
	// }

	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++)
			buf[y][x] = 0;
}
