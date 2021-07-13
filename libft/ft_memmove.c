#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char		*ptr_str1;
	const char	*ptr_str2;
	size_t		count;

	ptr_str1 = str1;
	ptr_str2 = str2;
	count = 0;
	if (!str1 && !str2)
		return (0);
	else if (str1 > str2)
		while (n-- > 0)
			ptr_str1[n] = ptr_str2[n];
	else
	{
		while (count < n)
		{
			ptr_str1[count] = ptr_str2[count];
			count++;
		}
	}
	return (ptr_str1);
}
