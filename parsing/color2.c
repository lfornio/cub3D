/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:57:40 by mshad             #+#    #+#             */
/*   Updated: 2022/03/21 21:58:13 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_colors(t_data *data, char *str)
{
	if (ft_strncmp(str, "F ", 2) == 0 || ft_strncmp(str, "C ", 2) == 0)
	{
		if (ft_strncmp(str, "F ", 2) == 0)
		{
			if (data->map.f_color != -1)
				error_exit("Arguments error!\n");
			data->map.f_color = color_converting(ft_strtrim(str + 2, " \t"));
		}
		else
		{
			if (data->map.c_color != -1)
				error_exit("Arguments error!\n");
			data->map.c_color = color_converting(ft_strtrim(str + 2, " \t"));
		}
		return (1);
	}
	return (0);
}
