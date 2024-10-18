/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:06:41 by mel-akar          #+#    #+#             */
/*   Updated: 2024/10/17 15:11:10 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	bool_map(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	'v' && (map = data->map, i = -1);
	if (!map)
		return (false);
	if (!_edgelines(*map))
		return (false);
	while (*(map + ++i))
	{
		j = -1;
		while (*(*(map + i) + ++j))
		{
			printf("%c", *(*(map + i) + j));
		}
		// check everyline's ['0', 'N', 'S', 'E', 'W']'s chars
		// if they're surrounded by any space ... if they, error.		
	}
	return (true);
}