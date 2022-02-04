/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:12:57 by lfornio           #+#    #+#             */
/*   Updated: 2022/02/04 12:47:17 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void free_tab(char **tab)  //очищение массива строк - карты
{
	int i;
	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void free_map(t_map *p) //чистим структуру для карты
{
	free_tab(p->map);
	free(p);
}


void free_all(t_data *data) //чистим основную структуру
{
	free_map(data->map_struct);
	free(data->win_struct);
	free(data->player_struct);

}
