/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:16:07 by ael-amma          #+#    #+#             */
/*   Updated: 2024/12/26 15:20:42 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_minimap(t_mlx *mlx)
{
	int			i;
	int			j;
	t_rect		tile;
	uint32_t	color;

	i = -1;
	while (++i < mlx->data->y)
	{
		j = -1;
		while (++j < mlx->data->x)
		{
			tile.x = j * TSIZE_SCALE;
			tile.y = i * TSIZE_SCALE;
			tile.width = TSIZE_SCALE;
			tile.height = TSIZE_SCALE;
			color = get_rgba(0, 0, 0, 255);
			if (mlx->data->map[i][j] == '0')
				color = get_rgba(255, 255, 255, 255);;
			drawrect(mlx->img, tile, color);
		}
	}
}

void	render_player(t_mlx *mlx)
{
	t_rect	tile;

	tile.x = mlx->data->px * TSIZE_SCALE;
	tile.y = mlx->data->py * TSIZE_SCALE;
	tile.width = TSIZE_SCALE;
	tile.height = TSIZE_SCALE;
	drawrect(mlx->img, tile, get_rgba(0, 0, 255, 255));
}
