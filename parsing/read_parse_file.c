/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_parse_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:38:23 by mshad             #+#    #+#             */
/*   Updated: 2022/03/21 19:38:24 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_file_format(const char *map_path, int fd)
{
	size_t	len;

	if (fd < 0)
		error_exit("Reading failed!\n");
	len = ft_strlen(map_path);
	if (len)
		len--;
	while (len && map_path[len] != '.')
		len--;
	if (!ft_strcmp(map_path + len + 1, "cub"))
		return ;
	else
		error_exit("File not .cub\n");
}

int	check_tex_and_color(t_data *data, char *line)
{
	if (parse_textures(data, line) || parse_colors(data, line))
		return (1);
	else if (!data->map.no_tex || ft_strlen(data->map.no_tex) == 0
		|| !data->map.so_tex || ft_strlen(data->map.so_tex) == 0
		|| !data->map.ea_tex || ft_strlen(data->map.ea_tex) == 0
		|| !data->map.we_tex || ft_strlen(data->map.we_tex) == 0
		|| data->map.f_color == -1 || data->map.c_color == -1)
		error_exit("Arguments error!\n");
	return (0);
}

void	parser_line(t_data *data, char *line)
{
	int	i;

	if (data->map.map_arr != NULL)
	{
		parse_map(data, line);
		return ;
	}
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else if (check_tex_and_color(data, line + i))
			break ;
		else if (line[i] == '1')
		{
			parse_map(data, line);
			return ;
		}
		else
			error_exit("Arguments error!\n");
	}
}

void	read_and_parse_file(t_data *data, const char *map_file)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(map_file, O_RDONLY);
	check_file_format(map_file, fd);
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			error_exit("Not reading file\n");
		if (line == NULL)
			error_exit("Arguments error!\n");
		parser_line(data, line);
		free(line);
		if (ret == 0)
			break ;
	}
	close(fd);
	if (data->map.map_arr == NULL)
		error_exit("No map!\n");
	check_map(data);
}
