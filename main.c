/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:50:38 by mshad             #+#    #+#             */
/*   Updated: 2022/03/21 19:50:39 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		printf(YELLOW "Error\nPlease, usage: ./cub3D [path to map]\n");
		return (0);
	}
	data = init_data();
	read_and_parse_file(data, argv[1]);
	graphics(data);
	free_data(data);
	return (0);
}
