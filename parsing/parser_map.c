/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:54:39 by mshad             #+#    #+#             */
/*   Updated: 2022/03/17 09:55:04 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(t_data *data, char *line)
{
	int		i;
	char	**tmp;

	i = 0;
	if (data->map.map_arr != NULL)
	{
		while (data->map.map_arr[i])
			i++;
		tmp = (char **)malloc(sizeof(char *) * (i + 2));
		if (!tmp)
			error_exit("Malloc failed!\n");
		tmp[i + 1] = NULL;
		tmp[i] = ft_strdup(line);
		if (!tmp[i])
			error_exit("Malloc failed!\n");
		while (i-- > 0)
			tmp[i] = data->map.map_arr[i];
		free(data->map.map_arr);
		data->map.map_arr = tmp;
		return ;
	}
	data->map.map_arr = (char **)malloc(sizeof(char *) * 2);
	data->map.map_arr[0] = ft_strdup(line);
	data->map.map_arr[1] = NULL;
}

void	check_sympols(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != 'N' && map[i][j] != 'E' && \
				map[i][j] != 'S' && map[i][j] != 'W' && \
				map[i][j] != ' ' && map[i][j] != '0' && \
				map[i][j] != '1')
				error_exit("The map contains forbidden symbols!\n");
		}
	}
}

void	check_player(t_data *data)
{
	int	i;
	int	j;
	int	player;
	int	x;

	player = 0;
	i = -1;
	while (data->map.map_arr[++i])
	{
		j = -1;
		while (data->map.map_arr[i][++j])
		{
			x = data->map.map_arr[i][j];
			if (x == 'N' || x == 'E' || x == 'S' || x == 'W')
			{
				data->player.dir = data->map.map_arr[i][j];
				player++;
				data->player.x = j;
				data->player.y = i;
				data->map.map_arr[i][j] = '0';
			}
		}
	}
	if (player != 1)
		error_exit("It must be just one player!\n");
}

void	check_map(t_data *data)
{
	check_sympols(data->map.map_arr);
	check_player(data);
	check_borders(data->map.map_arr, 0);
	check_borders(data->map.map_arr, get_height_arr(data->map.map_arr) - 1);
	check_uncorrect_postion(data, '0');
	check_uncorrect_postion(data, data->player.dir);
	if (valid_symbol(data->map.map_arr, data->player.y, data->player.x, ' '))
		error_exit("The map is not valid!\n");
}
