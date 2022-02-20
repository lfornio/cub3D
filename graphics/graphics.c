/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:07:58 by lfornio           #+#    #+#             */
/*   Updated: 2022/02/20 18:52:58 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void print_one_box(t_data *data, int x, int y, int color)
{
	int i;
	int j;
	i = 0;
	j = 0;

	while (j < STEP)
	{
		i = 0;
		while (i < STEP)
		{
			mlx_pixel_put(data->win_struct->mlx_ptr_window, data->win_struct->win_ptr_window, x + i, y + j, color);
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
		*x += STEP;
		i++;
	}
	*x = 0;
}

void	ft_cast_ray(t_data *all)
{
	t_player ray = *all->player_struct; // задаем координаты луча равные координатам игрока
	printf("ray_pl_x = %f, ray_pl_y = %f\n", ray.pl_x, ray.pl_y);
	printf("ray_vector = %f\n", ray.vector);

while (all->map_struct->map[(int)(ray.pl_y / STEP)][(int)(ray.pl_x / STEP)] != '1')
	{
		ray.pl_x += cos(ray.vector);
		ray.pl_y += sin(ray.vector);
		mlx_pixel_put(all->win_struct->mlx_ptr_window, all->win_struct->win_ptr_window, ray.pl_x, ray.pl_y, 0xffff00);
	}
}

void ft_cast_rays(t_data *data)
{
	t_player ray = *data->player_struct; // задаем координаты и направление луча равные координатам игрока
	ray.start = ray.vector - PI / 6;			 // начало веера лучей
	ray.end = ray.vector + PI / 6;		 // край веера лучей
	// printf("start = %f\n", ray.start);
	// printf("end = %f\n", ray.end);

	while (ray.start <= ray.end)
	{
		ray.pl_x = data->player_struct->pos.x * STEP + STEP / 2; // каждый раз возвращаемся в точку начала
		ray.pl_y = data->player_struct->pos.y * STEP + STEP / 2;
		while (data->map_struct->map[(int)(ray.pl_y / STEP)][(int)(ray.pl_x / STEP)] != '1')
		{
			ray.pl_x += cos(ray.start);
			ray.pl_y += sin(ray.start);
			mlx_pixel_put(data->win_struct->mlx_ptr_window, data->win_struct->win_ptr_window, ray.pl_x, ray.pl_y, 0xffff00);
		}
		ray.start += (PI / 3) / data->win_struct->width_window;
	}
}

void graphics(t_data *data)
{
	char **tab;
	tab = data->map_struct->map;
	int i;
	int x;
	int y;

	x = 0;
	y = 0;

	i = 0;
	while (tab[i])
	{
		print_cub2d(tab[i], data, &x, y);
		y += STEP;
		i++;
	}
	ft_cast_rays(data);
}
