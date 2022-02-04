#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != (char)c)
			i++;
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	if (s[0] == '\0' && s[0] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
