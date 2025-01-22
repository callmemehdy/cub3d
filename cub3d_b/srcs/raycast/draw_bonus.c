/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:47:14 by c_noob            #+#    #+#             */
/*   Updated: 2025/01/22 09:26:15 by ael-amma         ###   ########.fr       */
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

void	drawline(t_mlx *mlx, t_line line, uint32_t color)
{
	int		i;
	float	step;
	double	xstep;
	double	ystep;

	line.dx = line.x1 - line.x0;
	line.dy = line.y1 - line.y0;
	step = abs(line.dy);
	if (abs(line.dx) > abs(line.dy))
		step = abs(line.dx);
	xstep = line.dx / step;
	ystep = line.dy / step;
	i = -1;
	while (++i <= step)
	{
		mlx_put_pixel(mlx->img, round(line.x0), round(line.y0), color);
		line.x0 += xstep;
		line.y0 += ystep;
	}
}
