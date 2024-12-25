/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean_exp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:23:58 by mel-akar          #+#    #+#             */
/*   Updated: 2024/12/25 12:46:43 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

bool	is_safe(char c, int i, int j)
{
	int	x;
	int	y;

	y = (*get_data())->y;
	x = (*get_data())->x;
	return (i >= 0 && j >= 0 && i < y && j < x && c != ' ');
}

bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

bool	outsiders(char c)
{
	return (c != 'N' && c != 'S' && c != 'W' && c != 'E' && \
			c != ' ' && c != '0' && c != '1');
}

bool	check_char(char **map, int *pl, int i, int j)
{
	t_data	*data;

	data = (*get_data());
	if (map[i][j] == '0' && (!is_safe(map[i][j - 1], i, j - 1) || \
		!is_safe(map[1 + i][j], 1 + i, j) || \
		!is_safe(map[i - 1][j], i - 1, j) || \
		!is_safe(map[i][1 + j], i, 1 + j)))
		return (1);
	else if (is_player(map[i][j]) && ++*(pl) && \
		(!is_safe(map[i][j - 1], i, j - 1) && \
		!is_safe(map[1 + i][j], 1 + i, j) && \
		!is_safe(map[i - 1][j], i - 1, j) && \
		!is_safe(map[i][1 + j], i, 1 + j)))
		return (1);
	else if (outsiders(map[i][j]))
		return (1);
	if (is_player(map[i][j]))
	{
		data->py = i;
		data->px = j;
	}
	return (0);
}

bool	is_map(char *s)
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
