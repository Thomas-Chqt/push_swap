/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:48:56 by tchoquet          #+#    #+#             */
/*   Updated: 2023/07/08 19:54:59 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"

static void	reset_buffer(char *buffer, size_t len);
static char	*free_str(char *str);
static char	*append_buff(char *str, void const *buff, size_t buff_len);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	ssize_t		read_len;

	line = append_buff(NULL, buffer, str_ichr(buffer, '\n', BUFFER_SIZE) + 1);
	if (line == NULL)
		return (NULL);
	reset_buffer(buffer, BUFFER_SIZE);
	while (line[0] == '\0' || line[ft_strlen(line) - 1] != '\n')
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len < 0)
			return (free_str(line));
		line = append_buff(line, buffer, str_ichr(buffer, '\n', read_len) + 1);
		if (line == NULL || line[0] == '\0')
			return (free_str(line));
		reset_buffer(buffer, read_len);
		if (read_len < BUFFER_SIZE)
			return (line);
	}
	return (line);
}

static void	reset_buffer(char *buffer, size_t len)
{
	size_t	i;
	size_t	n_index;

	if (len == 0)
		return ;
	i = 0;
	n_index = str_ichr(buffer, '\n', len);
	while (i <= n_index)
		buffer[i++] = 0;
	memcpy_zero(buffer, buffer + n_index + 1, len - (n_index + 1));
}

static char	*free_str(char *str)
{
	free(str);
	return (NULL);
}

static char	*append_buff(char *str, void const *buff, size_t buff_len)
{
	char	*output_str;
	size_t	i;
	size_t	y;

	output_str = malloc(sizeof(char) * (ft_strlen(str) + buff_len + 1));
	i = 0;
	while (str && str[i])
	{
		output_str[i] = str[i];
		i++;
	}
	y = 0;
	while (y < buff_len)
		output_str[i++] = ((char *)buff)[y++];
	output_str[i] = '\0';
	free(str);
	return (output_str);
}
