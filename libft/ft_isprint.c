#include "libft.h"

int	ft_isprint(int character)
{
	if (character >= 32 && character < 127)
	{
		return (character);
	}
	return (0);
}
