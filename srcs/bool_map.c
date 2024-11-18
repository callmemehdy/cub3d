/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:06:41 by mel-akar          #+#    #+#             */
/*   Updated: 2024/11/18 20:58:58 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


char	*sp_padding(char *s, size_t maxlen)
{
	int			len;
	char		*buff;
	int			slen;

	'?' && (len = ft_strlen(s), slen = len);
	len < (int)maxlen && (len = maxlen--);
	if (len == slen)
		return (s);
	buff = ft_malloc(sizeof(char) * (len + 1));
	if (!buff)
		ft_error(ALLOC_ERR, ALLOC_STT);
	while ((int)maxlen >= 0)
	{
		if ((int)maxlen >= slen)
			buff[maxlen] = 'P';
		else if ((int)maxlen < slen)
			buff[maxlen] = s[--slen];
		--maxlen;
	}
	ft_free(s);
	buff[len] = 0;
	return (buff);
}

size_t	longest_line(char **s)
{
	int		i;
	size_t	maxlen;
	size_t	len;

	if (!s)
		return (0);
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
	int		i;
	size_t	maxlen;

	i = -1;
	maxlen = longest_line(s);
	while (s[++i])
		if (ft_strlen(s[i]) < maxlen)
			s[i] = sp_padding(s[i], maxlen);
	return (s);
}

bool	bool_map(t_data *data)
{
	char	**map;
	int		i;

	'v' && (map = data->map, i = -1);
	if (!map)
		return (false);
	if (!_edgelines(*map))
		return (false);
	map = to_rec(map);
	return (true);
}