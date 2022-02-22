/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:10:31 by lfornio           #+#    #+#             */
/*   Updated: 2022/02/22 10:08:43 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_mlx(t_data *data)
{
	t_win *p;
	p = (t_win *)malloc(sizeof(t_win));
	if (!p)
		return;
	data->win = p;
	p->width2d_win = ZOOM2D * data->map->width_map;											   //ширина окна
	p->height2d_win = ZOOM2D * data->map->height_map;											   //высота окна
	// p->mlx_ptr_win = mlx_init();																	   //инициируем подключение
	p->mlx2_ptr_win = mlx_init();																	   //инициируем подключение
	// p->win_ptr_win = mlx_new_window(p->mlx_ptr_win, p->width2d_win, p->height2d_win, "cub2D"); //создаем окно
	p->win2_ptr_win = mlx_new_window(p->mlx_ptr_win, WIDTH, HEIGHT, "cub3D"); //создаем окно
}
void init_fon2D(t_data *data) //структура для заполнения фона(картинки 2D)
{
	data->images->fon.fon_img_ptr = mlx_new_image(data->win->mlx_ptr_win, data->win->width2d_win, data->win->height2d_win);
	data->images->fon.addr = mlx_get_data_addr(data->images->fon.fon_img_ptr, &data->images->fon.bpp,&data->images->fon.size_line, &data->images->fon.endian);
}

void init_images(t_data *data) //заполняем структуру изображений
{
	t_image *img;
	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
		return;
	data->images = img;
	// init_fon2D(data);

}

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
	{
		error("Argument error");
		return (1);
	}
	parsing(&data, argv[1]);
	for (int i = 0; data.map->tab[i]; i++)
		printf("%s %d\n", data.map->tab[i], (int)ft_strlen(data.map->tab[i]));
	init_mlx(&data); //инициализируем окно
	init_arr_distances(&data);
	init_images(&data);  //инициализируем изображения
	graphics_2d(&data);  //2d карта
	printf("w = %d\n", data.win->width2d_win);
	printf("h = %d\n", data.win->height2d_win);
	move(&data);  // движения





	free_all(&data);
	return (0);
}
