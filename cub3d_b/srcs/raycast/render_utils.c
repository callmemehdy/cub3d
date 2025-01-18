/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:09:11 by c_noob            #+#    #+#             */
/*   Updated: 2025/01/17 23:48:20 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**map_mask(t_data *data, t_player *player)
{
	int		i;
	char	**kernel;

	i = -1;
	kernel = ft_malloc(sizeof(char *) * (size_t)16);
	if (!kernel)
		ft_error(ALLOC_ERR, ALLOC_STT);
	while (++i < 15)
		kernel[i] = fill_line(0, data, player, i);
	kernel[i] = 0;
	return (kernel);
}

char	*fill_line(char *s, t_data *data, t_player *player, int index)
{
	int		i;
	int		j;
	char 	*tmp;

	s = 0;
	i = (int)(player->y / TSIZE_SCALE) - 7 + index;
	j = (int)(player->x / TSIZE_SCALE) - 7;
	if (i >= 0 && i < data->y)
	{
		s = ft_malloc(sizeof(char) * 16);
		tmp = s;
		while (j <= (int)(player->x / TSIZE_SCALE + 7))
		{
			if (j >= 0 && j < data->x)
				*s = data->map[i][j];
			else
				*s = '1';
			s++;
			j++;
		}
		*s = 0;
		return (tmp);
	}
	else
		s = ft_strdup("111111111111111");
	return (s);
}
