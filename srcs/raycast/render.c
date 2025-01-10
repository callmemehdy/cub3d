/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:16:07 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/08 08:36:37 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_player(t_mlx *mlx);
static void	render_rays(t_mlx *mlx);

void	render(t_mlx *mlx)
{
	render_minimap(mlx->img);
	render_rays(mlx);
	render_player(mlx);
}

void	render_minimap(mlx_image_t *img)
{
	int		x;
	int		y;
	t_rect	tile;
	t_data	*data;

	y = -1;
	data = *get_data();
	while (++y < data->y)
	{
		x = -1;
		while (++x < data->x)
		{
			tile.x = x * TSIZE_SCALE;
			tile.y = y * TSIZE_SCALE;
			tile.width = TSIZE_SCALE;
			tile.height = TSIZE_SCALE;
			tile.fillclr = get_rgba(0, 0, 0, 255);
			if (data->map[y][x] == '0' || is_player(data->map[y][x]))
				tile.fillclr = get_rgba(255, 255, 255, 255);
			tile.edgeclr = tile.fillclr;
			drawrect(img, tile);
		}
	}
}

static void	render_player(t_mlx *mlx)
{
	// ################################
	// t_lin	line;
	// line.x0 = mlx->player->x * SCALE;
	// line.y0 = mlx->player->y * SCALE;
	// line.x1 = line.x0 + cos(mlx->player->angle) * 32 * SCALE;
	// line.y1 = line.y0 + sin(mlx->player->angle) * 32 * SCALE;
	// line.dx = abs(line.x1 - line.x0);
	// line.dy = abs(line.y1 - line.y0);
	// line.sx = -1;
	// line.sy = -1;
	// drawline(mlx, line, get_rgba(255, 0, 0, 255));
	// ################################

	t_circle	circle;

	circle.cx = mlx->player->x * SCALE;
	circle.cy = mlx->player->y * SCALE;
	circle.radius = mlx->player->radius * SCALE;
	circle.color = get_rgba(0, 0, 255, 255);
	drawcircle(mlx, circle);
}

static void	render_rays(t_mlx *mlx)
{
	int		i;
	t_lin	line;

	i = -1;
	while (++i < mlx->nrays)
	{
		line.x0 = mlx->player->x * SCALE;
		line.y0 = mlx->player->y * SCALE;
		line.x1 = mlx->rays[i].wallx * SCALE;
		line.y1 = mlx->rays[i].wally * SCALE;
		line.dx = abs(line.x1 - line.x0);
		line.dy = abs(line.y1 - line.y0);
		line.sx = -1;
		line.sy = -1;
		drawline(mlx, line, get_rgba(102, 102, 255, 100));
	}
}
