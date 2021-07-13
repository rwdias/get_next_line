#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t		count;
	const char	*ptr_str1;
	const char	*ptr_str2;

	count = 0;
	ptr_str1 = str1;
	ptr_str2 = str2;
	while ((count < n) && ((unsigned char)ptr_str1[count]
			== (unsigned char)ptr_str2[count]))
	{
		count++;
	}
	if (count == n)
		return (0);
	else
		return ((unsigned char)ptr_str1[count]
			- (unsigned char)ptr_str2[count]);
}
