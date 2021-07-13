#include "libft.h"

size_t	ft_rows(char const *s, char c)
{
	size_t	count;
	size_t	n_rows;

	if (!s[0])
		return (0);
	count = 0;
	n_rows = 0;
	while (s[count] != '\0' && s[count] == c)
		count++;
	while (s[count] != '\0' )
	{
		if (s[count] == c)
		{
			n_rows++;
			while (s[count] != '\0' && s[count] == c)
				count++;
			continue ;
		}
		count++;
	}
	if (s[count - 1] != c)
		n_rows++;
	return (n_rows);
}

void	ft_procstr(char **string_n, size_t *len_str, char c)
{
	size_t	count;

	*string_n += *len_str;
	*len_str = 0;
	count = 0;
	while (**string_n && **string_n == c)
		(*string_n)++;
	while ((*string_n)[count])
	{
		if ((*string_n)[count] == c)
			return ;
		(*len_str)++;
		count++;
	}
}

char	**ft_null(char **board)
{
	size_t	count;

	count = 0;
	while (board[count])
		free(board[count++]);
	free(board);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**board;
	char	*string_n;
	size_t	len_str;
	size_t	n_rows;
	size_t	count;

	if (!s)
		return (NULL);
	n_rows = ft_rows(s, c);
	board = (char **)malloc(sizeof(char *) * (n_rows + 1));
	if (!board)
		return (NULL);
	count = 0;
	string_n = (char *)s;
	len_str = 0;
	while (count < n_rows)
	{
		ft_procstr(&string_n, &len_str, c);
		board[count] = (char *)malloc(sizeof(char) * (len_str + 1));
		if (!board)
			return (ft_null(board));
		ft_strlcpy(board[count++], string_n, len_str + 1);
	}
	board[count] = NULL;
	return (board);
}
