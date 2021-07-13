#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	count;
	char	*ptr;

	count = 0;
	ptr = str;
	while (count < n)
	{
		ptr[count] = c;
		count++;
	}
	return (str);
}
