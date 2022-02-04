/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:07:58 by lfornio           #+#    #+#             */
/*   Updated: 2022/02/04 12:47:17 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void print_one_box(t_data *data, int x, int y, int color)
{
	int i;
	int j;
	i = 0;
	j = 0;

	while(j < STEP)
	{
		i = 0;
		while(i < STEP)
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

	while(str[i])
	{
		if(str[i] == '1')
			print_one_box(data, *x, y, 0xFFFFFF);
		if(str[i] == 'N')
			print_one_box(data, *x, y, 0xFF0096);
		*x += STEP;
		i++;
	}
	*x = 0;

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

	i=0;
	while(tab[i])
	{
		print_cub2d(tab[i], data, &x, y);
		y += STEP;
		i++;
	}


}
