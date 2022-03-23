/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_for_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:21:14 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/19 18:11:35 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_images(t_data *data)
{
	int	width;
	int	height;
	int	i;

	i = 0;
	data->tex.tex_arr[0].img_ptr = mlx_xpm_file_to_image(data->win.mlx,
			data->map.no_tex, &width, &height);
	data->tex.tex_arr[1].img_ptr = mlx_xpm_file_to_image(data->win.mlx,
			data->map.so_tex, &width, &height);
	data->tex.tex_arr[2].img_ptr = mlx_xpm_file_to_image(data->win.mlx,
			data->map.we_tex, &width, &height);
	data->tex.tex_arr[3].img_ptr = mlx_xpm_file_to_image(data->win.mlx,
			data->map.ea_tex, &width, &height);
	while (i < 4)
	{
		data->tex.tex_arr[i].addr = (int *)mlx_get_data_addr
			(data->tex.tex_arr[i].img_ptr,
				&data->tex.tex_arr[i].bpp, &data->tex.tex_arr[i].size_line,
				&data->tex.tex_arr[i].endian);
		i++;
	}
}

void	init_texture_struct(t_data *data)
{
	init_images(data);
	data->tex.tex_num = 0;
	data->tex.tex_flag = 0;
	data->tex.tex_x = 0;
	data->tex.tex_y = 1;
	data->tex.wall_x = 0;
	data->tex.step = 0;
	data->tex.tex_pos = 0;
}
