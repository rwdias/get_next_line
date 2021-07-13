#include "libft.h"

int	search(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr_s1;
	size_t	len_s1;
	size_t	beg;
	size_t	count;

	if (!s1 || !set)
		return (NULL);
	len_s1 = ft_strlen(s1);
	beg = 0;
	count = 0;
	while (s1[beg] && search(s1[beg], set))
		beg++;
	while (len_s1 > beg && search(s1[len_s1 - 1], set))
		len_s1--;
	ptr_s1 = (char *)malloc(sizeof(*s1) * (len_s1 - beg + 1));
	if (!ptr_s1)
		return (NULL);
	while (beg < len_s1)
		ptr_s1[count++] = s1[beg++];
	ptr_s1[count] = '\0';
	return (ptr_s1);
}
