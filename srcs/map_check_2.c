/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:33:26 by mel-akar          #+#    #+#             */
/*   Updated: 2024/10/13 20:18:32 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool is_map(char *s)
{
	int		i;

	i = -1;
	while (s[++i] && s[i] != '\n')
		if (s[i] != ' ' && s[i] != '1')
			return (false);
	return (true);
}

void	ft_sep(t_data *data)
{
	char	**s;
	int		i;

	i = -1;
	s = data -> map;
	while (!is_map(s[++i]))
	{}
	data -> config = data -> map;
	data -> map = data -> map + i;
	data -> confsize = i;
}


void	line2list(t_line **list, char *s)
{
	t_line *node;

	node = NULL;
	if (!list)
	{
		node = malloc(sizeof(t_line));
		if (!node)
			ft_error(ALLOC_ERR, ALLOC_STT);
		node -> s = ft_strdup(s);
		node -> next = NULL;
		list = &node; 
		return ;
	}
	else
	{
		node = ft_malloc(sizeof(t_line));
		if (!node)
			ft_error(ALLOC_ERR, ALLOC_STT);
		node -> s = ft_strdup(s);
		node -> next = *list;
		*list = node;
	}
}
