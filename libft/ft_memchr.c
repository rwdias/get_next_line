#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t		count;
	const char	*ptr_str;

	count = 0;
	ptr_str = str;
	while (count < n)
	{
		if (ptr_str[count] == (const char) c)
			return ((void *)(ptr_str + count));
		count++;
	}
	return (NULL);
}
