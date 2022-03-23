/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:37:44 by mshad             #+#    #+#             */
/*   Updated: 2022/03/21 19:37:45 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_height_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	check_borders(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == '0')
			error_exit("The map is not valid!\n");
		j++;
	}
}

int	valid_symbol(char **arr, int i, int j, char s)
{
	if (arr[i + 1][j] == s || !arr[i + 1][j] || \
		arr[i - 1][j] == s || !arr[i - 1][j] || \
		arr[i][j + 1] == s || !arr[i][j + 1] || \
		arr[i][j - 1] == s || !arr[i][j - 1])
		return (1);
	return (0);
}

void	check_uncorrect_postion(t_data *data, char s)
{
	int	i;
	int	j;

	i = 1;
	while (data->map.map_arr[i + 1])
	{
		j = 1;
		if (data->map.map_arr[i][0] == s)
			error_exit("The map is not valid!\n");
		while (data->map.map_arr[i][j + 1])
		{
			if (data->map.map_arr[i][j] == s)
			{
				if (valid_symbol(data->map.map_arr, i, j, ' '))
					error_exit("The map is not valid!\n");
			}
			j++;
		}
		if (data->map.map_arr[i][j] == s)
			error_exit("The map is not valid!\n");
		i++;
	}
}
