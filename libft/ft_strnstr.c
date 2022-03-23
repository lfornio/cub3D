/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:45:38 by mshad             #+#    #+#             */
/*   Updated: 2022/03/21 19:45:39 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		n;
	size_t	m;
	size_t	l;
	char	*hay;
	char	*need;

	hay = (char *)haystack;
	need = (char *)needle;
	l = ft_strlen(needle);
	if (l == 0)
		return (&hay[0]);
	if (len == 0)
		return (NULL);
	n = -1;
	while (hay[++n] != '\0')
	{
		m = 0;
		if (hay[n] == need[m])
			while ((hay[n + m] == need[m]) && (m <= l))
				if ((++m == l) && (((size_t)n + m <= len)))
					return (&hay[n]);
	}
	return (NULL);
}
