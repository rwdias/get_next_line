#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t		count;

	count = 0;
	if (*str == '\0')
		return (0);
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}
