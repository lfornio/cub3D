/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:37:54 by mshad             #+#    #+#             */
/*   Updated: 2022/03/21 21:58:01 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	rgb_to_hex(int red, int green, int blue)
{
	return ((((red * 256) + green) * 256) + blue);
}

static int	check_split(char **arr)
{
	int		x;
	int		y;

	x = -1;
	while (++x != 3)
	{
		y = -1;
		while (arr[x][++y])
		{
			if (ft_isalpha(arr[x][y]) == 1)
				return (1);
		}
	}
	return (0);
}

static int	check_split2(char **arr)
{
	int		x;
	char	**rgb1;
	int		result;

	x = -1;
	while (++x != 3)
	{
		result = 0;
		rgb1 = ft_split(arr[x], ' ');
		while (rgb1[result])
			result++;
		if (result != 1)
		{
			free_str_arr(rgb1);
			return (1);
		}
		free_str_arr(rgb1);
	}
	return (0);
}

static void	ft_free_and_exit(char **arr)
{
	free_str_arr(arr);
	error_exit("Invalid color!\n");
}

int	color_converting(char *str)
{
	int		result;
	char	**rgb;

	rgb = ft_split(str, ',');
	result = 0;
	while (rgb[result])
		result++;
	if (result != 3)
		ft_free_and_exit(rgb);
	if (check_split(rgb) == 1)
		ft_free_and_exit(rgb);
	if (check_split2(rgb) == 1)
		ft_free_and_exit(rgb);
	if (ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255
		|| ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255
		|| ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255)
		ft_free_and_exit(rgb);
	result = rgb_to_hex(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_str_arr(rgb);
	free(str);
	return (result);
}
