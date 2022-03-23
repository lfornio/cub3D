/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:43:26 by mshad             #+#    #+#             */
/*   Updated: 2022/03/21 19:43:27 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cpy;

	len = ft_strlen(s1) + 1;
	cpy = malloc(sizeof(char) * len);
	if (!cpy)
		return (0);
	cpy = ft_memcpy(cpy, s1, len);
	return (cpy);
}
