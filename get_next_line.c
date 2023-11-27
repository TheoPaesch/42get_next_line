/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:02:36 by tpaesch           #+#    #+#             */
/*   Updated: 2023/11/27 16:09:53 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// #include <stdio.h>

char	*fusion(char *s1, char *s2)
{
	char	*haa;

	haa = ft_strjoin(s1, s2);
	if (!haa)
		return (free(haa), free(s1), NULL);
	free(s1);
	return (haa);
}

char	*newline_handeling(char *st_buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (st_buffer[i] && st_buffer[i] != '\n')
		i++;
	if (st_buffer[i] == '\n')
		i++;
	if (!st_buffer[i])
		return (free(st_buffer), NULL);
	temp = ft_calloc(((ft_strlen(st_buffer) - i) + 1), sizeof(char));
	if (!temp)
		return (NULL);
	while (st_buffer[i] && st_buffer[i] != '\0')
		temp[j++] = st_buffer[i++];
	free(st_buffer);
	return (temp);
}

char	*line_extraction(char *st_buffer)
{
	int		i;
	char	*temp;

	i = 0;
	if (!st_buffer[i])
		return (NULL);
	while (st_buffer[i] && st_buffer[i] != '\n')
		i++;
	if (st_buffer[i] == '\n')
		i++;
	temp = ft_calloc(i + 1, sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (st_buffer[i] && st_buffer[i] != '\n')
	{
		temp[i] = st_buffer[i];
		i++;
	}
	if (st_buffer[i] == '\n')
		temp[i] = st_buffer[i];
	i++;
	return (temp);
}

char	*de_read_sandstorm(int fd, char *ret)
{
	char	read_input[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	if (!ret)
	{
		ret = ft_calloc(1, 1);
		if (!ret)
			return (free(ret), NULL);
	}
	bytes_read = read(fd, read_input, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		read_input[bytes_read] = '\0';
		ret = fusion(ret, read_input);
		if (!ret)
			return (free(ret), NULL);
		if (ft_strchr(read_input, '\n') || bytes_read == 0)
			break ;
		bytes_read = read(fd, read_input, BUFFER_SIZE);
	}
	if (bytes_read <= 0 && ret[0] == '\0')
		return (free(ret), NULL);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*st_buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(st_buffer);
		st_buffer = NULL;
		return (NULL);
	}
	st_buffer = de_read_sandstorm(fd, st_buffer);
	if (!st_buffer)
		return (free(st_buffer), NULL);
	line = line_extraction(st_buffer);
	st_buffer = newline_handeling(st_buffer);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char	*str;

// 	while ((str = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", str);
// 		free(str);
// 	}
// }
