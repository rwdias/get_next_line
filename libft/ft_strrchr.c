#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr_str;
	int		count;
	char	f;

	count = ft_strlen(str);
	ptr_str = (char *)str + (count - 1);
	f = (unsigned char) c;
	if (f == 0)
	{
		ptr_str++;
		return (ptr_str);
	}
	while (count != 0)
	{
		if (*ptr_str == f)
			return (ptr_str);
		ptr_str--;
		count--;
	}
	return (NULL);
}
