/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:43:08 by mshad             #+#    #+#             */
/*   Updated: 2022/03/21 19:43:09 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter_str(char const *s, char c)
{
	int			i;
	char const	*p;

	i = 0;
	p = s;
	while (*p)
	{
		while (*p == c)
			p++;
		if (*p)
		{
			i++;
			while (*p && *p != c)
				p++;
		}
	}
	return (i);
}

static void	ft_freemal(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*ft_mal(char const *s, char c, int i, char **arr)
{
	char	*p;
	int		len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
	{
		ft_freemal(arr);
		return (NULL);
	}
	p[len] = '\0';
	while (len-- && s[i - 1] != c)
	{
		p[len] = s[i - 1];
		i--;
	}
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn;
	int		k;
	int		i;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	rtn = malloc(sizeof(char *) * (ft_counter_str(s, c) + 1));
	if (!rtn)
		return (NULL);
	while (k < ft_counter_str(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		rtn[k] = ft_mal(s, c, i, rtn);
		while (s[i] && s[i] != c)
			i++;
		k++;
	}
	rtn[k] = NULL;
	return (rtn);
}
