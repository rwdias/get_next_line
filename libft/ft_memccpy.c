#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		*ptr_s1;
	const unsigned char	*ptr_s2;
	size_t				count;

	ptr_s1 = s1;
	ptr_s2 = s2;
	count = 0;
	if (!s1 && !s2)
		return (0);
	while (count < n)
	{
		ptr_s1[count] = ptr_s2[count];
		if (ptr_s2[count] == (unsigned char)c)
			return ((void *)(ptr_s1 + count + 1));
		count++;
	}
	return (0);
}
