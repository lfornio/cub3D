/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:10:31 by lfornio           #+#    #+#             */
/*   Updated: 2022/02/04 12:47:17 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_mlx(t_data *data)
{
	t_window *p;
	p = (t_window *)malloc(sizeof(t_window));
	if(!p)
		return ;
	data->win_struct = p;
	p->width_window= STEP * data->map_struct->width_map;  //ширина окна
	p->height_window = STEP * data->map_struct->height_map;  //высота окна
	p->mlx_ptr_window = mlx_init();  //инициируем подключение
	p->win_ptr_window = mlx_new_window(p->mlx_ptr_window, p->width_window, p->height_window, "cub3D");  //создаем окно


}

int main(int argc, char **argv)
{
	t_data data;

	if (argc == 2)
	{
		parsing(&data, argv[1]);
		for (int i = 0; data.map_struct->map[i]; i++)
			printf("%s %d\n", data.map_struct->map[i], (int)ft_strlen(data.map_struct->map[i]));
		init_mlx(&data);  //инициализируем окно
		graphics(&data);
		mlx_loop(data.win_struct->mlx_ptr_window); //ждем дейсвий


	}
	else
		error("Argument error");
	free_all(&data);
	return (0);
}
