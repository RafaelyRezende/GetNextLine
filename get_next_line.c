/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:22:08 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/06/13 18:31:37 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || !ft_init(&line, &bytes_read))
		return (NULL);
	line = ft_strjoin(line, buffer);
	if (!line)
		return (free(line), NULL);
	while (bytes_read && !ft_is_nl(&buffer[0]))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && !*line))
			return (free(line), NULL);
		if (bytes_read != 0)
		{
			ft_verify(bytes_read, buffer);
			line = ft_strjoin(line, buffer);
			if (!line)
				return (free(line),NULL);
		}
	}
	ft_offset(buffer);
	return (line);
}
