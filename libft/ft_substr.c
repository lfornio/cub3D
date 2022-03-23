/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:46:06 by mshad             #+#    #+#             */
/*   Updated: 2022/03/21 19:46:07 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;
	size_t	i;
	size_t	j;

	i = 0;
	j = (size_t) start;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (j > ft_strlen(s))
		return (ft_strdup(""));
	rtn = malloc(sizeof(char) * (len + 1));
	if (!rtn)
		return (0);
	while (i < len)
	{
		rtn[i] = *(s + j + i);
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
