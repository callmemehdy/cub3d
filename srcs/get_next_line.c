/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 06:08:04 by ael-amma          #+#    #+#             */
/*   Updated: 2024/10/05 11:08:52 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_updaterest(char *rest)
{
	size_t	i;
	size_t	j;
	char	*new_rest;

	i = 0;
	while (rest[i] && rest[i] != 10)
		i++;
	if (!rest[i] || !rest[i + 1])
		return (free(rest), rest = NULL, NULL);
	new_rest = malloc((ft_strlen(rest) - i) * sizeof(char));
	if (!new_rest)
		return (free(rest), rest = NULL, NULL);
	i++;
	j = 0;
	while (i < ft_strlen(rest))
		new_rest[j++] = rest[i++];
	new_rest[j] = 0;
	return (free(rest), rest = NULL, new_rest);
}

static char	*ft_getline(char *rest)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] && rest[i] != 10)
		i++;
	if (rest[i] == 10)
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy(line, rest, i);
	line[i] = 0;
	return (line);
}

static char	*ft_getrest(int fd, char *rest)
{
	ssize_t	rdata;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rdata = 1;
	while (!ft_strchr(rest, 10) && rdata != 0)
	{
		rdata = read(fd, buffer, BUFFER_SIZE);
		if (rdata == -1)
			return (free(buffer), buffer = NULL, free(rest), NULL);
		buffer[rdata] = 0;
		rest = ft_strjoin(rest, buffer);
		if (!rest)
			return (free(buffer), buffer = NULL, NULL);
	}
	return (free(buffer), buffer = NULL, rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	rest = ft_getrest(fd, rest);
	if (!rest)
		return (NULL);
	line = ft_getline(rest);
	rest = ft_updaterest(rest);
	return (line);
}
