/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:06:41 by mel-akar          #+#    #+#             */
/*   Updated: 2024/11/18 16:48:46 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


char	*rmjoin(char *s, size_t maxlen)
{
	size_t		len;
	char		*buff;

	len = ft_strlen(s);
	len < maxlen && (len = maxlen);
	buff = ft_malloc(sizeof(char) * len);
	if (!buff)
		ft_error(ALLOC_ERR, ALLOC_STT);
	
}

size_t	longest_line(char **s)
{
	int		i;
	size_t	maxlen;
	size_t	len;

	'?' && (maxlen = 0, i = -1);
	while (s[++i])
	{
		len = ft_strlen(s[i]);
		if (len > maxlen)
			maxlen = len;
	}
	return (maxlen);
}

char	**to_rec(char **s)
{
	
}

bool	bool_map(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	'v' && (map = data->map, i = -1);
	if (!map)
		return (false);
	if (!_edgelines(*map))
		return (false);
	map = to_rec(map);
	while (*(map + ++i))
	{
		j = -1;
		while (*(*(map + i) + ++j))
		{
			printf("%c", *(*(map + i) + j));
		}
		printf("\n");
		// check everyline's ['0', 'N', 'S', 'E', 'W']'s chars
		// if they're surrounded by any space ... if they, error.
	}
	return (true);
}