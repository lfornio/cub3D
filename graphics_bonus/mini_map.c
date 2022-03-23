/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:07:35 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/21 20:20:15 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_one_box(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < MINI)
	{
		i = 0;
		while (i < MINI)
		{
			ft_pix_put(&data->back, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	print_cub2d(char *str, t_data *data, int *x, int y)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			print_one_box(data, *x, y, 0xFFFFFF);
		*x += MINI;
		i++;
	}
	*x = 0;
}

void	draw_player(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = (int)(data->ray.pl_x * MINI - PLAYER % 2);
	y = (int)(data->ray.pl_y * MINI - PLAYER % 2);
	while (j < PLAYER)
	{
		i = 0;
		while (i < PLAYER)
		{
			ft_pix_put(&data->back, x + i, y + j, 0xFF0000);
			i++;
		}
		j++;
	}
}

int	error_mini_map(t_data *data)
{
	int	a;
	int	b;
	int	i;

	i = 0;
	while (data->map.map_arr[i])
		i++;
	b = i;
	a = (int)ft_strlen(data->map.map_arr[0]);
	if (a * MINI > W_WIDTH || b * MINI > W_HEIGHT)
	{
		printf(RED"Error\n");
		ft_putstr_fd("Mini_map is very big\n", 2);
		printf(RESET"");
		return (1);
	}
	return (0);
}

void	draw_mini_map(t_data *data)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (data->map.map_arr[i])
	{
		print_cub2d(data->map.map_arr[i], data, &x, y);
		y += MINI;
		i++;
	}
	draw_player(data);
}
