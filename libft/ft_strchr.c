#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr_str;
	char	f;

	ptr_str = (char *)s;
	f = (unsigned char) c;
	while (*ptr_str != '\0')
	{
		if (*ptr_str == f)
			return (ptr_str);
		ptr_str++;
	}
	if (*ptr_str == f)
		return (ptr_str);
	return (NULL);
}
