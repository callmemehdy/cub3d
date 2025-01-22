/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:06:41 by mel-akar          #+#    #+#             */
/*   Updated: 2025/01/22 09:25:47 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static
char	*sp_padding(char *s, int maxlen)
{
	int			len;
	char		*buff;
	int			slen;

	'?' && (len = ft_strlen(s), slen = len);
	len < maxlen && (len = maxlen--);
	if (len == slen)
		return (s);
	buff = ft_malloc(sizeof(char) * (len + 1));
	if (!buff)
		ft_error(ALLOC_ERR, ALLOC_STT);
	while (maxlen >= 0)
	{
		if (maxlen >= slen)
			buff[maxlen] = ' ';
		else if (maxlen < slen)
			buff[maxlen] = s[--slen];
		--maxlen;
	}
	buff[len] = 0;
	ft_free(s);
	return (buff);
}

static
int	longest_line(char **s)
{
	int		i;
	int		maxlen;
	int		len;

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

static
char	**to_rec(char **s)
{
	int		i;
	int		maxlen;

	i = -1;
	maxlen = longest_line(s);
	(*get_data())->x = maxlen;
	while (s[++i])
		if ((int)ft_strlen(s[i]) < maxlen)
			s[i] = sp_padding(s[i], maxlen);
	(*get_data())->y = i;
	return (s);
}

static
bool	element_check(char **map)
{
	int		i;
	int		j;
	int		pl;
	int		width;

	'^' && (i = 0, j = 0, pl = 0);
	width = (*get_data())->x;
	while (map[i])
	{
		j = 0;
		if (skip(map[i])[0] != '1' || revskip(map[i])[0] != '1')
			return (1);
		while (map[i][j])
		{
			if (check_char(map, &pl, i, j))
				return (1);
			++j;
		}
		++i;
	}
	return (pl != 1);
}

bool	bool_map(t_data *data)
{
	char	**map;
	int		i;

	'v' && (map = data->map, i = -1);
	if (!map)
		return (false);
	map = to_rec(map);
	if (element_check(map))
		ft_error(MAP_ERR, MAP_STT);
	return (true);
}
