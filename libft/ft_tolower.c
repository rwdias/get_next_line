#include "libft.h"

int	ft_tolower(int arg)
{
	if ((arg >= 'A' && arg <= 'Z'))
		return (arg + 32);
	else
		return (arg);
}
