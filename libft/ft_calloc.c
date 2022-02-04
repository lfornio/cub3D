#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	dest = malloc(size * count);
	if (dest == NULL)
		return (NULL);
	ft_memset(dest, 0, size * count);
	return (dest);
}
