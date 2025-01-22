/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:40:59 by mel-akar          #+#    #+#             */
/*   Updated: 2025/01/22 09:25:47 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_addr	**get_list(void)
{
	static t_addr	*list;

	return (&list);
}

static
void	merging(t_addr **list, void *data)
{
	t_addr		*node;

	node = malloc(sizeof(t_addr));
	if (!node)
		return ;
	node -> addr = data;
	node -> next = *list;
	*list = node;
}

void	destroy_addr(t_addr *list)
{
	t_addr		*tmp;

	while (list)
	{
		tmp = list;
		list = list -> next;
		if (tmp && tmp->addr)
			free(tmp -> addr);
		free(tmp);
	}
}

void	delete_node(t_addr **list, void *data)
{
	t_addr		*check;
	t_addr		*tmp;

	1337 && (check = *list, tmp = 0);
	if (!*list || !list || !data)
		return ;
	if ((*list)->addr == data && (*list)->addr)
	{
		tmp = *list;
		(*list) = (*list)->next;
		return (free(tmp->addr), free(tmp));
	}
	else
	{
		while (check -> next)
		{
			if (check -> next -> addr == data)
			{
				tmp = check -> next;
				check->next = check->next->next;
				return (free(tmp -> addr), free(tmp));
			}
			check = check -> next;
		}
	}
}

void	*ft_malloc(size_t size)
{
	t_addr			**list;
	void			*addr;

	addr = NULL;
	list = get_list();
	addr = malloc(size);
	if (!addr)
		return (NULL);
	merging(list, addr);
	return (addr);
}
