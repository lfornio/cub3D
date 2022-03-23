/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:40:35 by mshad             #+#    #+#             */
/*   Updated: 2022/03/21 20:39:27 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_atoi(const char *str)
// {
// 	long	i;
// 	long	nbr;
// 	int		isneg;

// 	i = 0;
// 	nbr = 0;
// 	isneg = 0;
// 	while ((str[i] != '\0') && ((str[i] == 32)
// 			|| (str[i] >= 9 && str[i] <= 13)))
// 		i++;
// 	if (str[i] != '\0' && str[i] == '-')
// 	{
// 		isneg = 1;
// 		i++;
// 	}
// 	else if (str[i] == '+')
// 		i++;
// 	while (str[i] != '\0' && ft_isdigit(str[i]))
// 		nbr = (nbr * 10) + (str[i++] - '0');
// 	if (isneg == 1)
// 		return (-nbr);
// 	return (nbr);
// }

int	ft_atoi(const char *str)
{
	long	i;
	long	n;
	int		b;

	i = 0;
	n = 0;
	b = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			b = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	n = n * b;
	return (n);
}
