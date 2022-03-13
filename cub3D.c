/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:10:31 by lfornio           #+#    #+#             */
/*   Updated: 2022/03/13 17:34:42 by lfornio          ###   ########.fr       */
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
	// p->width2d_win = ZOOM2D * data->map->width_map;											   //ширина окна
	// p->height2d_win = ZOOM2D * data->map->height_map;											   //высота окна
	// p->mlx_ptr_win = mlx_init();																	   //инициируем подключение
	p->mlx_ptr_win = mlx_init();																	   //инициируем подключение
	// p->win_ptr_win = mlx_new_window(p->mlx_ptr_win, p->width2d_win, p->height2d_win, "cub2D"); //создаем окно
	p->win_ptr_win = mlx_new_window(p->mlx_ptr_win, WIDTH, HEIGHT, "cub3D");
}
void init_fon(t_data *data) //структура для заполнения фона(картинки 2D)
{
	data->images->fon.fon_img_ptr = mlx_new_image(data->win->mlx_ptr_win, WIDTH, HEIGHT);
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

void init_tex_for_draw(t_data *data)
{
	int	width;
	int	height;
	t_tex *tmp;
	tmp = (t_tex *)malloc(sizeof(t_tex));
	if (!tmp)
		return;
	data->tex = tmp;
	/*-----------------------------*/
	tmp->str_n = "images/wall1.xpm";
	tmp->str_s = "images/wall2.xpm";
	tmp->str_w = "images/wall3.xpm";
	tmp->str_e = "images/wall4.xpm";
	/*-----------------------------*/
	tmp->ptr_n= mlx_xpm_file_to_image(data->win->mlx_ptr_win, tmp->str_n, &width, &height);
	tmp->ptr_s= mlx_xpm_file_to_image(data->win->mlx_ptr_win, tmp->str_s, &width, &height);
	tmp->ptr_w= mlx_xpm_file_to_image(data->win->mlx_ptr_win, tmp->str_w, &width, &height);
	tmp->ptr_e= mlx_xpm_file_to_image(data->win->mlx_ptr_win, tmp->str_e, &width, &height);
	tmp->img_n = (int **)mlx_get_data_addr(tmp->ptr_n, &data->images->fon.bpp,&data->images->fon.size_line, &data->images->fon.endian);
	tmp->img_s = (int **)mlx_get_data_addr(tmp->ptr_s,&data->images->fon.bpp,&data->images->fon.size_line, &data->images->fon.endian);
	tmp->img_w = (int **)mlx_get_data_addr(tmp->ptr_w,&data->images->fon.bpp,&data->images->fon.size_line, &data->images->fon.endian);
	tmp->img_e = (int **)mlx_get_data_addr(tmp->ptr_e, &data->images->fon.bpp,&data->images->fon.size_line, &data->images->fon.endian);
	tmp->tex_num = 0;
	tmp->wall_x = 0;
	tmp->tex_x = 0;
	tmp->step = 0;
	tmp->tex_pos = 0;

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
	init_mlx(&data); //инициализируем окно
	init_arr_distances(&data);
	init_images(&data);  //инициализируем изображения
	init_ray_struct(&data);
	init_tex_for_draw(&data);
	graphics(&data);
	move(&data);  // движения






	// free_all(&data);
	return (0);
}
