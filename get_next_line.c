/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-b <jpaulo-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:28:52 by jpaulo-b          #+#    #+#             */
/*   Updated: 2025/05/15 13:07:23 by jpaulo-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	line = ft_strjoin(line, buffer);
	while (!ft_strchr(buffer))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || buffer[0] == 0)
		{
			free(line);
			//shift(buffer);
			return (NULL);
		}
		if (!bytes_read)
			break ;
		if (bytes_read < BUFFER_SIZE)
			buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	shift(buffer);
	return (line);
}
/*#include <stdio.h>
int	main(void)
{
	char	*line;
	int		fd1;

	fd1 = open("text.txt", O_RDONLY);
	while((line = get_next_line(fd1)))
	{
		printf("%s", line);
		free(line);
	}
	line = get_next_line(fd1);
	printf("\n%s\n", line);
	free(line);
	close(fd1);
	return (0);
}*/