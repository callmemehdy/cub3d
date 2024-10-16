/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:54:38 by mel-akar          #+#    #+#             */
/*   Updated: 2024/10/16 15:34:06 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(void *add)
{
	delete_node(get_list(), add);
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
