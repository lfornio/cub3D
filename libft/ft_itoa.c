/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:41:29 by mshad             #+#    #+#             */
/*   Updated: 2022/03/21 19:41:30 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_nbr(int c)
{
	int	i;

	if (c < 0)
	{
		i = 1;
		c = -c;
	}
	else
		i = 0;
	while (c)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_size_nbr(n);
	str = malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		n = n * (-1);
		str[0] = '-';
	}
	str[size] = '\0';
	while (n > 0)
	{
		size--;
		str[size] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
