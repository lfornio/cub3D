#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
		int c, size_t n)
{
	const unsigned char	*src2;
	unsigned char		*dst2;
	unsigned char		a;
	size_t				i;

	src2 = (const unsigned char *)src;
	dst2 = (unsigned char *)dst;
	a = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (src2[i] == a)
		{
			return (dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
