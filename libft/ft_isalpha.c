#include "libft.h"

int	ft_isalpha(int arg)
{
	if (arg >= 'A' && arg <= 'Z')
		return (1);
	else if (arg >= 'a' && arg <= 'z')
		return (2);
	else
		return (0);
}
