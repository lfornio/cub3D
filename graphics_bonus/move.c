/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:16:02 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/19 16:51:09 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	step_exit(int key, t_data *data)
{
	(void)key;
	(void)data;
	exit(0);
}

void	esc_exit(t_data *data)
{
	mlx_destroy_window(data->win.mlx, data->win.win);
	exit(0);
}

int	press_key(int key, t_data *data)
{
	if (key == ESC)
		esc_exit(data);
	else if (key == 2 || key == 0 || key == 1 || key == 13)
		steps(key, data);
	else if (key == LEFT || key == RIGHT)
		rotations(key, data);
	return (0);
}

void	move(t_data *data)
{
	mlx_hook(data->win.win, 2, 1L << 0, press_key, data);
	mlx_hook(data->win.win, 17, 1L << 0, step_exit, data);
	mlx_loop_hook(data->win.mlx, draw, data);
	mlx_loop(data->win.mlx);
}
