/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 18:19:09 by evoronin      #+#    #+#                 */
/*   Updated: 2023/02/01 12:38:13 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line_bonus.h"
#include <limits.h>

char	*get_newline(char *temp)
{
	int		i;
	char	*newline;

	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\n')
		newline = (char *)malloc(sizeof(char) * (i + 2));
	else
		newline = (char *)malloc(sizeof(char) * (i + 1));
	if (!newline)
		return (NULL);
	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
	{
		newline[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		newline[i] = '\n';
		i++;
	}
	newline[i] = '\0';
	return (newline);
}

char	*read_buf(int fd, char *temp)
{
	int			bytes;
	char		buf[BUFFER_SIZE + 1];

	bytes = 1;
	buf[0] = '\0';
	while (!ft_strchr(temp, '\n') && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (ft_free(&temp, NULL), NULL);
		buf[bytes] = '\0';
		temp = ft_strjoin(temp, buf);
		if (!temp)
		{
			buf[0] = '\0';
			return (ft_free(&temp, NULL), NULL);
		}
	}
	if (!temp)
		return (ft_free(&temp, NULL), NULL);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char		*temp[OPEN_MAX];
	char			*line;

	if (!temp[fd])
	{
		temp[fd] = (char *)malloc(sizeof(char) * 1);
		if (!temp[fd])
			return (NULL);
		temp[0] = '\0';
	}
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	temp[fd] = read_buf(fd, temp[fd]);
	if (!temp[fd])
		return (ft_free(&temp[fd], NULL), NULL);
	line = get_newline(temp[fd]);
	if (!line)
		return (ft_free(&temp[fd], NULL), NULL);
	if (ft_strlen(newline) == 0)
		return (free(newline), NULL);
	temp[fd] = ft_temptrim(temp[fd], line);
	if (!temp[fd])
		return (ft_free(&temp[fd], line), NULL);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		fd;
// 	int		i;
// 	int		fd1;
// 	int		fd2;

// 	i = 1;
// 	fd = open("testbonus1.txt", O_RDONLY);
// 	fd1 = open("testbonus2.txt", O_RDONLY);
// 	fd2 = open("testbonus3.txt", O_RDONLY);
// 	while (i < 3)
// 	{
// 		line = get_next_line(fd);
// 		printf("[%d] %s\n", i, line);
// 		free(line);
// 		line = get_next_line(fd1);
// 		printf("[%d] %s\n", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("[%d] %s\n", i, line);
// 		free(line);
// 		i++;
// 	}
// 	// system("leaks a.out");
// 	close(fd);
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
