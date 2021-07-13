#include "libft.h"

static int	ft_size(int n)
{
	int		count;
	long	nb;

	nb = n;
	count = 1;
	if (nb < 0)
	{
		count++;
		nb *= (-1);
	}
	while (nb >= 10)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ptr_n;
	long	nb;
	int		i;

	i = 0;
	ptr_n = (char *)malloc(sizeof(char) * ft_size(n) + 1);
	if (!ptr_n)
		return (NULL);
	if (n < 0)
		ptr_n[0] = '-';
	nb = n;
	if (nb < 0)
		nb *= (-1);
	ptr_n[ft_size(n) - i++] = '\0';
	while (nb >= 10)
	{
		ptr_n[ft_size(n) - i++] = (nb % 10) + '0';
		nb /= 10;
	}
	ptr_n[ft_size(n) - i++] = (nb % 10) + '0';
	return (ptr_n);
}
