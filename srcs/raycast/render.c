/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:16:07 by ael-amma          #+#    #+#             */
/*   Updated: 2024/12/18 14:25:34 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_minimap(void)
{
	int			i;
	int			j;
	uint32_t	color;
	t_rect		tile;
	t_data		*data;

	i = -1;
	data = *get_data();
	while (++i < data->y)
	{
		j = -1;
		while (++j < data->x)
		{
			tile.x = j * SIZE_SCALE;
			tile.y = i * SIZE_SCALE;
			tile.width = SIZE_SCALE;
			tile.height = SIZE_SCALE;
			color = 0x000000FF;
			if (data->map[i][j] == '0')
				color = 0xFFFFFFFF;
			drawrect((*get_rdata())->img, tile, color);
		}
	}
}
