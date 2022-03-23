/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:52:47 by mshad             #+#    #+#             */
/*   Updated: 2022/03/21 20:05:46 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_tex(char *str)
{
	int		fd;
	char	*format;
	int		i;

	format = malloc(sizeof(char) * 5);
	if (!format)
		error_exit("Malloc failed!\n");
	i = 0;
	while (i < 4)
	{
		format[i] = str[ft_strlen(str) - 4 + i];
		i++;
	}
	format[i] = '\0';
	fd = open(str, O_RDONLY);
	if (fd == -1 || ft_strncmp(format, ".xpm", 4) != 0)
	{
		free(format);
		error_exit("Link for a texture is incorrect\n");
	}
	free(format);
	close(fd);
}

int	parse_textures(t_data *data, char *str)
{
	if (ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "SO ", 3) == 0
		|| ft_strncmp(str, "WE ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0)
	{
		parsing_tex(data, str);
		if (data->map.no_tex)
			check_tex(data->map.no_tex);
		if (data->map.so_tex)
			check_tex(data->map.so_tex);
		if (data->map.ea_tex)
			check_tex(data->map.ea_tex);
		if (data->map.we_tex)
			check_tex(data->map.we_tex);
		return (1);
	}
	return (0);
}

void	parsing_tex(t_data *data, char *str)
{
	if (ft_strncmp(str, "NO ", 3) == 0)
	{
		if (data->map.no_tex != NULL)
			error_exit("Arguments error!\n");
		data->map.no_tex = ft_strtrim(str + 3, " \t");
	}
	else if (ft_strncmp(str, "SO ", 3) == 0)
	{
		if (data->map.so_tex != NULL)
			error_exit("Arguments error!\n");
		data->map.so_tex = ft_strtrim(str + 3, " \t");
	}
	else if (ft_strncmp(str, "WE ", 3) == 0)
	{
		if (data->map.we_tex != NULL)
			error_exit("Arguments error!\n");
		data->map.we_tex = ft_strtrim(str + 3, " \t");
	}
	else if (ft_strncmp(str, "EA ", 3) == 0)
	{
		if (data->map.ea_tex != NULL)
			error_exit("Arguments error!\n");
		data->map.ea_tex = ft_strtrim(str + 3, " \t");
	}
}
