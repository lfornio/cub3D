/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniature.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:43:21 by lfornio           #+#    #+#             */
/*   Updated: 2022/02/22 12:45:01 by lfornio          ###   ########.fr       */
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

void print2d(t_data *data)
{
	char **tab;
	tab = data->map->tab;
	int i;
	int x;
	int y;

	x = 0;
	y = 0;

	i = 0;
	while (tab[i])
	{
		print_cub2d(tab[i], data, &x, y);
		y += ZOOM2D;
		i++;
	}
}

