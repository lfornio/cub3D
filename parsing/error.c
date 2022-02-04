/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfornio <lfornio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:24:50 by lfornio           #+#    #+#             */
/*   Updated: 2022/02/03 16:31:44 by lfornio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	error(const char *s)
{
	write(2, "Error\n", 6);
	printf("%s\n", s);
}

void	error_file(const char *name_file)
{
	int		i;
	int		a;
	char	*str;

	i = 0;
	a = ft_strlen(name_file) - 4;
	str = (char *)malloc(sizeof(char *) * 5);
	if (!str)
		return ;
	while (name_file[a])
	{
		str[i] = name_file[a];
		a++;
		i++;
	}
	str[i] = '\0';
	if (ft_strncmp(str, ".cub", 4) != 0)
	{
		write(2, "Error\n", 6);
		printf("The map is not .cub\n");
		free(str);
		exit(0);
	}
	free(str);
}
