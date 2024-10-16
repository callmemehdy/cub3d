/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:33:26 by mel-akar          #+#    #+#             */
/*   Updated: 2024/10/16 15:03:02 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool is_map(char *s)
{
	int		i;

	i = -1;
	if (!s)
		return (true);
	while (s[++i] && s[i] != '\n')
	{
		if (s[i] != ' ' && s[i] != '1')
			return (false);
	}
	return (true);
}

bool	onlynl(char *s)
{
	int		i;

	i = -1;
	if (!s)
		return (true);
	while (s[++i])
	{
		if (s[i] == '\n' || s[i] == ' ')
			continue ;
		else
			return (false);
	}
	return (true);
}

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

void	ft_sep(t_data *data)
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


void	line2list(t_line **list, char *s)
{
	t_line *node;
	t_line *tmp;

	if (!list)
		return ;
	node = ft_malloc(sizeof(t_line));
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

void	free_lines(t_line *lines)
{
	t_line *tmp;

	while (lines)
	{
		tmp = lines;
		lines = lines->next;
		ft_free(tmp->s);
		ft_free(tmp);
	}
}