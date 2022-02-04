#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	a;

	i = 0;
	while (s[i] != '\0')
		i++;
	a = i;
	while (a > 0)
	{
		if (s[a] != (char)c)
			a--;
		if (s[a] == (char)c)
			return ((char *)s + a);
	}
	if (s[0] == '\0' && s[0] == (char)c)
		return ((char *)s + a);
	return (NULL);
}
