/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_IV.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:59:21 by mel-akar          #+#    #+#             */
/*   Updated: 2025/01/08 11:07:13 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

bool	outtabound(int y, int x)
{
	int	w;
	int	h;

	h = (*get_data())->y;
	w = (*get_data())->x;
	if (y >= h || x >= w || y < 0 || x < 0)
		return (1);
	return (0);
}

bool	is_map_first(char *s)
{
	int		i;

	i = -1;
	if (!s)
		return (true);
	if (s[0] == '\n')
		return (false);
	while (s[++i])
	{
		if (s[i] == ' ' || s[i] == '1' || s[i] == '\n')
			continue ;
		else
			return (false);
	}
	return (true);
}
