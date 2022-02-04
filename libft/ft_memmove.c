#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src2;
	char	*dst2;
	size_t	i;

	i = -1;
	src2 = (char *)src;
	dst2 = (char *)dst;
	if (dst == src || len == 0)
		return (dst);
	if (dst > src)
	{
		while (len > 0)
		{
			dst2[len - 1] = src2[len - 1];
			len--;
		}
	}
	while (++i < len)
		dst2[i] = src2[i];
	return (dst);
}
