/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:09:49 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/19 18:12:12 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_image_back(t_data *data)
{
	data->back.back_ptr = mlx_new_image(data->win.mlx, W_WIDTH, W_HEIGHT);
	data->back.addr = mlx_get_data_addr(data->back.back_ptr, &data->back.bpp,
			&data->back.size_line, &data->back.endian);
}

void	init_mlx(t_data *data)
{
	data->win.mlx = mlx_init();
	data->win.win = mlx_new_window(data->win.mlx, W_WIDTH, W_HEIGHT, "cub3d");
}
