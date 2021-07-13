#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{	
	size_t	count;

	count = 0;
	if (n == 0)
		return (0);
	while (str1[count] != '\0' && str1[count] == str2[count] && count < n - 1)
		count++;
	return ((unsigned char)str1[count] - (unsigned char)str2[count]);
}
