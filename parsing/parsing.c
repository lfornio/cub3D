/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:00:46 by lfornio           #+#    #+#             */
/*   Updated: 2022/02/04 13:01:57 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int size_tab_from_file(char *map) //считывание файла для подсчета размера
{
	int fd;
	int count;
	char *line;

	line = NULL;
	count = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(0);
	}
	while ((get_next_line(fd, &line)) > 0)
	{
		if (ft_strlen(line) == 0)
		{
			printf("Error: Map is error, empty lines\n");
			exit(0);
		}
		free(line);
		count++;
	}
	free(line);
	close(fd);
	return (count);
}

char **new_tab(char *map, int count) //считывание из файла карты
{
	char **tab;
	char *line;
	int fd;
	int i;

	i = 0;
	fd = open(map, O_RDONLY);
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	while ((get_next_line(fd, &line)) > 0)
	{
		tab[i] = ft_substr(line, 0, ft_strlen(line));
		free(line);
		i++;
	}
	free(line);
	tab[i] = NULL;
	close(fd);
	return (tab);
}

int max_lenght_str_in_map(char **tab) //max длина строки в массиве до заполнения пробелами
{
	int i;
	i = 0;
	int len_max;
	len_max = 0;
	int tmp;
	tmp = 0;

	while (tab[i])
	{
		tmp = (int)ft_strlen(tab[i]);
		if (tmp > len_max)
			len_max = tmp;
		i++;
	}
	return (len_max);
}

char *full_str(char *str, int max) //заполнили строку в массиве пробелами
{
	char *res;
	int i;
	int j;
	i = 0;
	j = 0;
	res = (char *)malloc(sizeof(char) * (max + 1));
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[j] = str[i];
		i++;
		j++;
	}
	while (j < max)
	{
		res[j] = ' ';
		j++;
	}
	res[j] = '\0';
	free(str);
	return (res);
}

void full_map(char **tab, int max) //массив заполнили пробелами
{
	int i;
	i = 0;
	while (tab[i])
	{
		if ((int)ft_strlen(tab[i]) < max)
			tab[i] = full_str(tab[i], max);
		i++;
	}
}

void create_tab(t_data *data, char *file_name) //создаем массив строк для карты
{
	t_map *the_map;

	the_map = (t_map *)malloc(sizeof(t_map)); //иниц структуру для карты
	if (!the_map)
		return;
	data->map_struct = the_map;
	the_map->height_map = size_tab_from_file(file_name);	  //высота карты = количество строк
	the_map->map = new_tab(file_name, the_map->height_map);	  // массив строк в структуре карта
	the_map->width_map = max_lenght_str_in_map(the_map->map); //ширина карты = количество столбцов
	full_map(the_map->map, the_map->width_map);				  //заполняем карту пробелами
}

void search_player(char *str, int y, t_data *data)
{
	int i;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'W' || str[i] == 'E' || str[i] == 'S')
		{
			data->player_struct->pos.x = i;
			data->player_struct->pos.y = y;
			break;
		}
		i++;
	}
}

void player_position_search(t_data *data)
{
	char **tab;
	tab = data->map_struct->map;
	int i;
	i = 0;
	while (tab[i])
	{
		search_player(tab[i], i, data);
		i++;
	}
}

void init_player(t_data *data) //заполняем структуру игрока
{
	t_player *plr;
	plr = (t_player *)malloc(sizeof(t_player));
	if (!plr)
		return;
	data->player_struct = plr;
	player_position_search(data);
	printf("x = %d y = %d\n", data->player_struct->pos.x, data->player_struct->pos.y);
}

void parsing(t_data *data, char *map)
{
	error_file(map);	   //проверка на .cub
	create_tab(data, map); //создаем структуру для карты
	init_player(data);	   //создаем структуру игрока
}
