/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapareci <rwdias1991@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:36:28 by rafaeldias        #+#    #+#             */
/*   Updated: 2021/11/11 11:23:12 by rapareci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!s1 || !s2 || !ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		ptr[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		ptr[i++] = s2 [j++];
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	count;

	count = 0;
	if (!dst || !src)
		return (0);
	if (n == 0)
	{
		while (src[count])
			count++;
		return (count);
	}
	while (count < n - 1 && src[count] != '\0')
	{
		dst[count] = src[count];
		count++;
	}
	dst[n - 1] = '\0';
	if (count < n)
		dst[count] = '\0';
	while (src[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(const char *src)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(src);
	ptr = malloc(len + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, src, len + 1);
	ptr[len] = '\0';
	return (ptr);
}
