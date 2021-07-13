#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	count;

	count = 0;
	if (!dst || !src)
		return (0);
	if (n == 0)
	{
		while (src[count])
			count++;
		return (count);
	}
	while (count < n - 1 && src[count] != '\0')
	{
		dst[count] = src[count];
		count++;
	}
	dst[n - 1] = '\0';
	if (count < n)
		dst[count] = '\0';
	while (src[count] != '\0')
		count++;
	return (count);
}
