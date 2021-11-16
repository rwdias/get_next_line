/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapareci <rwdias1991@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:38:23 by rapareci          #+#    #+#             */
/*   Updated: 2021/11/16 17:57:28 by rapareci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*create_bkp(int fd, char *bkp, char	*buffer);
static char	*create_line(char *bkp);
static char	*keep_bkp(char *bkp);

static char	*keep_bkp(char *bkp)
{
	int			i;
	char		*newbkp;

	i = 0;
	while (bkp[i] && bkp[i] != '\n')
		i++;
	if (bkp[i] == '\0')
	{
		free(bkp);
		return (NULL);
	}
	newbkp = (char *)malloc(sizeof(char) * (ft_strlen(bkp) - i + 1));
	if (!newbkp)
		return (NULL);
	ft_strlcpy(newbkp, bkp + i + 1, ft_strlen(bkp) - i + 1);
	free(bkp);
	return (newbkp);
}

static char	*create_line(char *bkp)
{
	int			i;
	char		*line;

	i = 0;
	while (bkp[i] && bkp[i] != '\n')
		i++;
	line = (char *) malloc (sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, bkp, i + 2);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*create_bkp(int fd, char *bkp, char	*buffer)
{
	int		read_result;
	int		i;
	char	*temp;

	read_result = 1;
	i = 0;
	while (i == 0 && read_result != 0)
	{
		read_result = read(fd, buffer, BUFFER_SIZE);
		if (read_result == -1 )
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_result] = '\0';
		if (!bkp)
			bkp = ft_strdup("");
		temp = bkp;
		bkp = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(bkp, '\n'))
			i = 1;
	}
	free(buffer);
	return (bkp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*bkp;
	char		*buffer;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	bkp = create_bkp(fd, bkp, buffer);
	if (!bkp)
		return (NULL);
	line = create_line(bkp);
	bkp = keep_bkp(bkp);
	return (line);
}

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	fd1 = open("test", O_RDONLY);
	i = 1;
	while (i < 5)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}