/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:54:38 by mel-akar          #+#    #+#             */
/*   Updated: 2024/11/20 10:32:53 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
	garbage == 1 && ((*get_list()) = 0);
}

void	ft_free_all(void)
{
	t_addr	**list;

	list = get_list();
	destroy_addr(*list);
	list = NULL;
}

void	free_lines(t_line *lines)
{
	t_line	*tmp;

	while (lines)
	{
		tmp = lines;
		lines = lines->next;
		ft_free(tmp->s);
		ft_free(tmp);
	}
}
