/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:40:05 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/03/25 15:40:34 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_text(int fd, char *remainder);
static char	*read_file(int fd, char *total_buffer);
static char	*get_line(char *text);
static char	*get_remainder(char *text);

char	*get_next_line(int fd)
{
	char			*line;
	char			*text;
	static char		*remainder[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (ft_strchr(remainder[fd], '\n') != NULL)
		text = remainder[fd];
	else
		text = get_text(fd, remainder[fd]);
	if (text == NULL)
		return (NULL);
	remainder[fd] = get_remainder(text);
	line = get_line(text);
	free(text);
	if (line == NULL)
		line = reset_ptr(line);
	return (line);
}

/* Get text from remainder or from fd */
static char	*get_text(int fd, char *remainder)
{
	char	*text;

	if (remainder == NULL)
		text = ft_strdup("");
	else
		text = remainder;
	text = read_file(fd, text);
	if (*text == '\0')
		text = reset_ptr(text);
	return (text);
}

/* Get text from fd until the buffer contains \n or EOF */
static char	*read_file(int fd, char *total_buffer)
{
	char	*current_buffer;
	char	*previous_buffer;
	size_t	read_len;

	current_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!current_buffer)
		return (NULL);
	read_len = BUFFER_SIZE;
	while (read_len == BUFFER_SIZE)
	{
		read_len = read(fd, current_buffer, BUFFER_SIZE);
		if (read_len <= 0 || read_len > BUFFER_SIZE)
			break ;
		current_buffer[read_len] = '\0';
		previous_buffer = total_buffer;
		total_buffer = ft_strjoin(previous_buffer, current_buffer);
		previous_buffer = reset_ptr(previous_buffer);
		if (ft_strchr(total_buffer, '\n') != NULL)
			break ;
	}
	free(current_buffer);
	return (total_buffer);
}

/* Get the text before \n or \0 */
static char	*get_line(char *text)
{
	char	*line;
	int		i;

	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	line[i + 1] = '\0';
	while (i > -1)
	{
		line[i] = text[i];
		i--;
	}
	return (line);
}

/* Get the text after \n */
static char	*get_remainder(char *text)
{
	char	*remainder;
	size_t	len;
	size_t	i;

	remainder = ft_strchr(text, '\n');
	if (!remainder)
		return (NULL);
	remainder++;
	text = remainder;
	len = ft_strlen(remainder);
	remainder = malloc((len + 1) * sizeof(char));
	i = 0;
	while (i < len)
	{
		remainder[i] = text[i];
		i++;
	}
	remainder[i] = '\0';
	return (remainder);
}
