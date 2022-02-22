/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:07:58 by lfornio           #+#    #+#             */
/*   Updated: 2022/02/22 10:02:20 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void print_one_box(t_data *data, int x, int y, int color)
{
	int i;
	int j;
	i = 0;
	j = 0;

	while (j < ZOOM2D)
	{
		i = 0;
		while (i < ZOOM2D)
		{
			// mlx_pixel_put(data->win_struct->mlx_ptr_window, data->win_struct->win_ptr_window, x + i, y + j, color);
			img_pix_put(&data->images->fon, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void print_cub2d(char *str, t_data *data, int *x, int y)
{
	int i;
	i = 0;

	while (str[i])
	{
		if (str[i] == '1')
			print_one_box(data, *x, y, 0xFFFFFF);
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			print_one_box(data, *x, y, 0xFF0096);
		*x += ZOOM2D;
		i++;
	}
	*x = 0;
}

void cast_ray(t_data *all)
{
	t_player ray = *all->plr; // задаем координаты луча равные координатам игрока
	printf("ray_pl_x = %f, ray_pl_y = %f\n", ray.pl_x, ray.pl_y);
	printf("ray_vector = %f\n", ray.vector);

	while (all->map->tab[(int)(ray.pl_y / ZOOM2D)][(int)(ray.pl_x / ZOOM2D)] != '1')
	{
		ray.pl_x += cos(ray.vector);
		ray.pl_y += sin(ray.vector);
		img_pix_put(&all->images->fon, ray.pl_x, ray.pl_y, 0xffff00);
	}
}

void cast_rays(t_data *data)
{
	t_player ray = *data->plr; // задаем координаты и направление луча равные координатам игрока
	ray.start = ray.vector - PI / 6;	 // начало веера лучей
	ray.end = ray.vector + PI / 6;		 // край веера лучей
	// printf("vector = %f\n", ray.vector);
	// printf("start = %f\n", ray.start);
	// printf("end = %f\n", ray.end);
	// printf("p_x = %f\n", (double)(data->plr->pos.x * STEP + STEP /2));
	// printf("p_y = %f\n", (double)(data->plr->pos.y * STEP + STEP / 2));
	int i = 0;
	while (ray.start <= ray.end)
	{
		ray.pl_x = data->plr->pos.x * ZOOM2D + ZOOM2D / 2; // каждый раз возвращаемся в точку начала
		ray.pl_y = data->plr->pos.y * ZOOM2D + ZOOM2D / 2;
		while (data->map->tab[(int)(ray.pl_y / ZOOM2D)][(int)(ray.pl_x / ZOOM2D)] != '1')
		{
			ray.pl_x += cos(ray.start);
			ray.pl_y += sin(ray.start);
			img_pix_put(&data->images->fon, ray.pl_x, ray.pl_y, 0xffff00);
		}
		data->arr_distances[i] = ((int)fabs(((data->plr->pos.x * ZOOM2D + ZOOM2D / 2) - ray.pl_x) / cos(ray.start))) *  cos(ray.start);
		ray.start += (PI / 3) / data->win->width2d_win;
		i++;
	}
	// for(int i = 0; i < data->win->width_win; i++)
	// 	printf("%d %d\n", data->arr_distances[i], i);
}

void img_pix_put(t_fon_img *fon, int x, int y, int color)
{
	char *pixel;

	pixel = fon->addr + (y * fon->size_line + x * (fon->bpp / 8));
	*(int *)pixel = color;
}


void graphics_2d(t_data *data)
{
	char **tab;
	tab = data->map->tab;
	int i;
	int x;
	int y;

	x = 0;
	y = 0;

	i = 0;
	init_fon2D(data);
	while (tab[i])
	{
		print_cub2d(tab[i], data, &x, y);
		y += ZOOM2D;
		i++;
	}
	cast_rays(data);
	mlx_put_image_to_window(data->win->mlx_ptr_win, data->win->win_ptr_win, data->images->fon.fon_img_ptr, 0, 0);
}
