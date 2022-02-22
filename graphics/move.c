/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:54:06 by lfornio           #+#    #+#             */
/*   Updated: 2022/02/22 10:01:56 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void esc_exit(t_data *data)
{
	mlx_destroy_window(data->win->mlx_ptr_win, data->win->win_ptr_win);
	exit(0);
}

int change_position(t_data *data, int j, int i, char ch)
{
	int x;
	int y;

	x = data->plr->pos.x;
	y = data->plr->pos.y;

	if (data->map->tab[j][i] == '1')
		return (-1);
	data->map->tab[y][x] = '0';
	data->map->tab[j][i] = ch;
	if (i - x)
	{
		data->plr->pos.x = x + (i - x);
		data->plr->pl_x = data->plr->pl_x + (i - x) * ZOOM2D;
	}
	if (j - y)
	{
		data->plr->pos.y = y + (j - y);
		data->plr->pl_y = data->plr->pl_y + (j - y) * ZOOM2D;
	}
	return (0);
}

int to_look_to_go(int key, t_data *data)
{
	int x;
	int y;

	x = data->plr->pos.x;
	y = data->plr->pos.y;
	if (key == 53)
		esc_exit(data);
	if (key == 123)
		data->plr->vector -= 5 * PI / 180;
	else if (key == 124)
		data->plr->vector += 5 * PI / 180;
	else if (key == 2)
		x++;
	else if (key == 0)
		x--;
	else if (key == 1)
		y++;
	else if (key == 13)
		y--;
	if (change_position(data, y, x, data->map->tab[data->plr->pos.y][data->plr->pos.x]) < 0)
		return (-1);
	mlx_destroy_image(data->win->mlx_ptr_win, data->images->fon.fon_img_ptr);
	graphics_2d(data);
	return (0);
}

void move(t_data *data)
{
	mlx_hook(data->win->win_ptr_win, 2, 1L << 0, to_look_to_go, data);
	// mlx_hook(mlx->win_ptr, 17, 1L << 0, step_exit, mlx);

	mlx_loop(data->win->mlx_ptr_win); //ждем дейсвий
	mlx_loop(data->win->mlx2_ptr_win); //ждем дейсвий
}
