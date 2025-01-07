/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:53:20 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/07 11:19:23 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawrect(mlx_image_t *img, t_rect tile)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tile.height)
	{
		j = -1;
		while (++j < tile.width)
		{
			if (!i % TSIZE || !j % TSIZE)
				mlx_put_pixel(img, tile.x + j, tile.y + i, tile.edgeclr);
			else
				mlx_put_pixel(img, tile.x + j, tile.y + i, tile.fillclr);
		}
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

void	drawline(t_mlx *mlx, t_lin line, uint32_t color)
{
	int	err;
	int	err2;

	if (line.x0 < line.x1)
		line.sx = 1;
	if (line.y0 < line.y1)
		line.sy = 1;
	err = line.dx - line.dy;
	while (1)
	{
		mlx_put_pixel(mlx->img, line.x0, line.y0, color);
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		err2 = 2 * err;
		if (err2 > -line.dx)
		{
			err -= line.dy;
			line.x0 += line.sx;
		}
		if (err2 < line.dy)
		{
			err += line.dx;
			line.y0 += line.sy;
		}
	}
}
