#include "libft.h"

int	ft_toupper(int arg)
{
	if ((arg >= 'a' && arg <= 'z'))
		return (arg - 32);
	else
		return (arg);
}
