/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-b <jpaulo-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:13:20 by jpaulo-b          #+#    #+#             */
/*   Updated: 2025/05/16 15:56:46 by jpaulo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	line = ft_strjoin(line, buffer[fd]);
	while (!ft_strchr(buffer[fd]))
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read == -1 || buffer[fd][0] == 0)
		{
			free(line);
			shift(buffer[fd]);
			return (NULL);
		}
		if (!bytes_read)
			break ;
		if (bytes_read < BUFFER_SIZE)
			buffer[fd][bytes_read] = '\0';
		line = ft_strjoin(line, buffer[fd]);
	}
	shift(buffer[fd]);
	return (line);
}
/*#include <stdio.h>
#include <fcntl.h>// open, O_RDONLY

int	main(void)
{
	char	*line1, *line2, *line3;
	int		fd3 = open("text3.txt", O_RDONLY);
	int		fd4 = open("text4.txt", O_RDONLY);
	int		fd5 = open("text5.txt", O_RDONLY);
	
	while((line1 = get_next_line(fd3)))
	{
		printf("%s", line1);
		free(line1);
	}
	while((line2 = get_next_line(fd4)))
	{
		printf("%s", line2);
		free(line2);
	}
	while((line3 = get_next_line(fd5)))
	{
		printf("%s", line3);
		free(line3);
	}
	close(fd3);
	close(fd4);
	close(fd5);
	return (0);
}*/