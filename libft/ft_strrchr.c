/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:45:45 by mshad             #+#    #+#             */
/*   Updated: 2022/03/21 19:45:46 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		n;
	char	*fin;

	fin = (char *)s;
	n = ft_strlen(fin);
	if ((unsigned char)c == '\0')
		return (&fin[n]);
	while (n >= 0)
	{
		if (fin[n] == (unsigned char)c)
		{
			return (&fin[n]);
		}
		n--;
	}
	return (NULL);
}
