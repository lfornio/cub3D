/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:42:33 by mshad             #+#    #+#             */
/*   Updated: 2022/03/21 19:42:34 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < len)
	{
		if (src < dst)
			((char *)dst)[len - i - 1] = ((char *)src)[len - i - 1];
		else
			((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
