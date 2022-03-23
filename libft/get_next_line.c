/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:46:30 by mshad             #+#    #+#             */
/*   Updated: 2022/03/21 19:46:31 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*m_str(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*m_remains(char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * ((ft_strlen(s) - i) + 1));
	if (str == NULL)
		return (NULL);
	i = i + 1;
	while (s[i])
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	free (s);
	return (str);
}

static int	m_return_error(int fd, char **line, char **buffer)
{
	if (!line || fd < 0 || fd > 1024 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (0);
	*buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*buffer == NULL)
		return (0);
	return (1);
}

static int	end_read(char **save, char **line)
{
	*line = ft_strdup(*save);
	free (*save);
	*save = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			res_read;
	char		*buffer;
	static char	*save;

	res_read = 1;
	if (m_return_error(fd, &(*line), &buffer) == 0)
		return (-1);
	if (!save)
		save = ft_strnew(1);
	while (new_str(save) == 0 && res_read > 0)
	{
		res_read = read(fd, buffer, BUFFER_SIZE);
		buffer[res_read] = '\0';
		save = ft_strjoin_free(save, buffer);
	}
	free (buffer);
	if (new_str(save))
	{
		*line = m_str(save);
		save = m_remains(save);
	}
	if (res_read == 0)
		return (end_read(&save, &(*line)));
	return (1);
}
