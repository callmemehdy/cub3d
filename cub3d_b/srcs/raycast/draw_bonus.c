/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:47:14 by c_noob            #+#    #+#             */
/*   Updated: 2025/01/23 22:19:34 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	drawrect(mlx_image_t *img, t_rect tile)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tile.height)
	{
		j = -1;
		while (++j < tile.width)
			mlx_put_pixel(img, tile.x + j, tile.y + i, tile.color);
	}
}

void	drawcircle(t_mlx *mlx, t_circle circ)
{
	int	x;
	int	y;

	y = -circ.radius - 1;
	while (++y <= circ.radius)
	{
		x = -circ.radius - 1;
		while (++x <= circ.radius)
			if (x * x + y * y <= circ.radius * circ.radius)
				mlx_put_pixel(mlx->img, circ.cx + x, circ.cy + y, circ.color);
	}
}
