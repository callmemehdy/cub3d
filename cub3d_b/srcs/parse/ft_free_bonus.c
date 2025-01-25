/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:54:38 by mel-akar          #+#    #+#             */
/*   Updated: 2025/01/25 04:18:07 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static
size_t	list_size(t_addr *list)
{
	size_t	size;

	if (!list)
		return (0);
	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

void	ft_free(void *add)
{
	bool	garbage;

	garbage = 0;
	if (list_size(*get_list()) == 1 && (*get_list())->addr == add)
		garbage = 1;
	delete_node(get_list(), add);
	(void)(garbage == 1 && ((*get_list()) = 0));
}

void	ft_free_all(void)
{
	t_addr	**list;

	list = get_list();
	destroy_addr(*list);
	list = NULL;
}

void	free_lines(t_linegnl *lines)
{
	t_linegnl	*tmp;

	while (lines)
	{
		tmp = lines;
		lines = lines->next;
		ft_free(tmp->s);
		ft_free(tmp);
	}
}

bool	check_door(char **map, int i, int j)
{
	t_data	*data;

	data = *get_data();
	if (i < 0 || i >= data->y || j < 0 || j >= data->x)
		return (1);
	if (map[i][j] == 'D' && \
			!(((map[i][j - 1] == '0' && map[i][j + 1] == '0') && \
			(map[i - 1][j] == '1' && map[i + 1][j] == '1')) || \
			((map[i][j - 1] == '1' && map[i][j + 1] == '1') && \
			(map[i - 1][j] == '0' && map[i + 1][j] == '0'))))
		return (1);
	return (0);
}
