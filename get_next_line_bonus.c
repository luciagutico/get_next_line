/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/25 16:43:06 by anagutie      #+#    #+#                 */
/*   Updated: 2023/11/29 15:39:08 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **buffer)
{
	if (*buffer)
		free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*copying_line(char *static_buffer)
{
	char	*current_line;
	int		i;

	i = 0;
	if (!static_buffer[i])
		return (NULL);
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (static_buffer[i] == '\n')
		i++;
	current_line = ft_calloc(i + 1, sizeof(char));
	if (current_line == NULL)
		return (NULL);
	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
	{
		current_line[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] && static_buffer[i] == '\n')
	{
		current_line[i++] = '\n';
		current_line[i++] = '\0';
	}
	return (current_line);
}

char	*prepare_next_line(char *static_buffer)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (static_buffer[i] == '\0')
	{
		next_line = NULL;
		return (ft_free(&static_buffer));
	}
	next_line = ft_calloc((ft_strlen(static_buffer) - i + 1), sizeof(char));
	if (next_line == NULL)
		return (ft_free(&static_buffer));
	i++;
	j = 0;
	while (static_buffer[i])
		next_line[j++] = static_buffer[i++];
	ft_free(&static_buffer);
	return (next_line);
}

char	*read_and_append_file(int fd, char *static_buffer)
{
	char	*buffer;
	ssize_t	content_readed;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (ft_free(&static_buffer));
	content_readed = 1;
	while (content_readed > 0 && !ft_strchr(buffer, '\n'))
	{
		content_readed = read(fd, buffer, BUFFER_SIZE);
		if (content_readed < 0)
		{
			ft_free(&buffer);
			return (ft_free(&static_buffer));
		}
		buffer[content_readed] = 0;
		static_buffer = ft_strjoin(static_buffer, buffer);
		if (static_buffer == NULL)
			return (ft_free(&buffer));
	}
	free(buffer);
	return (static_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(1, 1);
	if (buffer[fd] == NULL)
		return (ft_free(&buffer[fd]));
	buffer[fd] = read_and_append_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = copying_line(buffer[fd]);
	if (!line)
		return (ft_free(&buffer[fd]));
	buffer[fd] = prepare_next_line(buffer[fd]);
	return (line);
}
