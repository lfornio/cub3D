/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:07:58 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/13 16:51:34 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void init_ray_direction_start(t_ray *ray)
{
	char ch = 'N';

	if (ch == 'N')
	{
		ray->vec_x = 0;
		ray->vec_y = -1;
	}
	else if (ch == 'S')
	{
		ray->vec_x = 0;
		ray->vec_y = 1;
	}
	else if (ch == 'E')
	{
		ray->vec_x = 1;
		ray->vec_y = 0;
	}
	else if (ch == 'W')
	{
		ray->vec_x = -1;
		ray->vec_y = 0;
	}
}

void init_fov(t_ray *ray)
{
	char ch = 'N';

	if (ch == 'N')
	{
		ray->plane_x = 0.66;
		ray->plane_y = 0;
	}
	else if (ch == 'S')
	{
		ray->plane_x = -0.66;
		ray->plane_y = 0;
	}
	else if (ch == 'E')
	{
		ray->plane_x = 0;
		ray->plane_y = 0.66;
	}
	else if (ch == 'W')
	{
		ray->plane_x = 0;
		ray->plane_y = -0.66;
	}
}

void init_ray_struct(t_data *data)
{
	t_ray *tmp;
	tmp = (t_ray *)malloc(sizeof(t_ray));
	if (!tmp)
		return;
	data->ray = tmp;
	init_ray_direction_start(tmp);
	init_fov(tmp);
	tmp->ray_vec_x = 0;
	tmp->ray_vec_y = 0;
	tmp->side_dist_x = 0;
	tmp->side_dist_y = 0;
	tmp->delta_dist_x = 0;
	tmp->delta_dist_y = 0;
	tmp->map_x = 0;
	tmp->map_y = 0;
	tmp->step_x = 0;
	tmp->step_y = 0;
	tmp->side = 0;
	tmp->perp_wall_dist  = 0;
	tmp->line_height = 0;
}

void img_pix_put(t_fon_img *fon, int x, int y, int color)
{
	char *pixel;

	pixel = fon->addr + (y * fon->size_line + x * (fon->bpp / 8));
	*(int *)pixel = color;
}

void print_back(t_data *data, int h1, int h2, int color)
{
	int x;
	x = 0;
	int y;
	while (x < WIDTH)
	{
		y = h1;
		while (y < h2)
		{
			img_pix_put(&data->images->fon, x, y, color);
			y++;
		}
		x++;
	}
}

void graphics(t_data *data)
{
	init_fon(data);
	print_back(data, 0, HEIGHT / 2, 0x140096);
	print_back(data, HEIGHT / 2, HEIGHT, 0x002546);

	raycasting(data);
	// print2d(data);

	mlx_put_image_to_window(data->win->mlx_ptr_win, data->win->win_ptr_win, data->images->fon.fon_img_ptr, 0, 0);
}
