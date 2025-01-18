/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_II.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:33:26 by mel-akar          #+#    #+#             */
/*   Updated: 2025/01/16 09:55:19 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

bool	_edgelines(char *s)
{
	if (!s)
		return (false);
	s -= 1;
	while (*(++s) && *s != 10)
	{
		if (*s == '1' || *s == ' ')
			continue ;
		else
			return (false);
	}
	return (true);
}

void	slicemap(t_data *data)
{
	char	**s;
	int		i;

	i = 0;
	s = data -> map;
	if (!s)
		return ;
	while (s[i] && !is_map(s[i]))
		i++;
	data -> config = data -> map;
	data -> map = data -> map + i;
	data -> confsize = i;
}

void	line2list(t_linegnl **list, char *s)
{
	t_linegnl	*node;
	t_linegnl	*tmp;

	if (!list)
		return ;
	node = ft_malloc(sizeof(t_linegnl));
	if (!node)
		ft_error(ALLOC_ERR, ALLOC_STT);
	if (list && !*list)
	{
		node -> s = ft_strdup(s);
		node -> next = NULL;
		*list = node;
	}
	else if (list)
	{
		tmp = *list;
		node -> s = ft_strdup(s);
		node -> next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

unsigned
int	rgbshifter(char *s, int level)
{
	unsigned int	rgb;

	if (!s || !*s || !level)
		return (0);
	while (*s && *s >= 'A' && *s <= 'Z')
		s++;
	's' && (rgb = 0, s = skip(s));
	rgb = atob(s);
	while (*s && *s >= '0' && *s <= '9')
		s++;
	s = skip(s);
	if (*s != ',' && level > 1)
		ft_error(MAP_ERR, MAP_STT);
	if ((*s != ' ' && *s != 0 && *s != 10) && level == 1)
		ft_error(MAP_ERR, MAP_STT);
	*s == ',' && (s++);
	return ((rgbshifter(s, level - 1) << 8) | rgb);
}

t_byte	atob(char *s)
{
	int		i;
	int		res;

	'M' && (res = 0, i = -1);
	if (!(*s >= '0' && *s <= '9'))
		ft_error(MAP_ERR, MAP_STT);
	while (s[++i] >= '0' && s[i] <= '9' && s[i])
	{
		res = (res * 10) + (s[i] - 48);
		if (res > UCHAR_MAX)
			ft_error(MAP_ERR, MAP_STT);
	}
	return ((t_byte)res);
}
