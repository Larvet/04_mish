/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:02:03 by bchene            #+#    #+#             */
/*   Updated: 2023/12/06 16:48:56 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*gnl_callocbuffer(void)
{
	char	*buffer;
	int		i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	i = -1;
	while (++i < (BUFFER_SIZE + 1))
		buffer[i] = '\0';
	return (buffer);
}

static void	*gnl_free(t_gnlist **line, char *buffer)
{
	if (buffer)
		free(buffer);
	if (line)
		gnl_lstclear(line);
	return (NULL);
}

static char	*gnl_returnline(t_gnlist **line, int readsize, char *buffer)
{
	char		*str;
	int			i;
	t_gnlist	*last;

	if (readsize == -1 || (*line == NULL && buffer[0] == '\0'))
		return (gnl_free(line, buffer));
	str = gnl_getlstline(*line);
	last = *line;
	while (last->next)
		last = last->next;
	i = 0;
	while (last->nl + i < BUFFER_SIZE && i < last->len)
	{
		buffer[i] = last->buffer[last->nl + i];
		i++;
	}
	buffer[i] = '\0';
	i = last->nl;
	gnl_lstclear(line);
	if (i && buffer[0] != '\0')
		gnl_lstadd_back(line, gnl_lstnew(buffer));
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static t_gnlist	*line;
	char			*buf;
	int				readsize;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buf = gnl_callocbuffer();
	if (buf == NULL)
		return (gnl_free(&line, buf));
	if (line && line->nl)
		return (gnl_returnline(&line, line->len - line->nl, buf));
	readsize = BUFFER_SIZE;
	while (readsize == BUFFER_SIZE)
	{
		readsize = (int)read(fd, buf, BUFFER_SIZE);
		if (readsize == -1 || (readsize == 0 && line == NULL))
			return (gnl_free(&line, buf));
		if (readsize)
		{
			buf[readsize] = '\0';
			readsize = gnl_lstadd_back(&line, gnl_lstnew(buf));
		}
	}
	return (gnl_returnline(&line, readsize, buf));
}
