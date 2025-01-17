/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c_noob <c_noob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:16:07 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/17 22:22:21 by c_noob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_player(t_mlx *mlx);

void	render(t_mlx *mlx)
{
	mlx_delete_image(mlx->mlxi, mlx->img);
	mlx->img = mlx_new_image(mlx->mlxi, W_WIDTH, W_HEIGHT);
	render_map(mlx);
	render_player(mlx);
	mlx_image_to_window(mlx->mlxi, mlx->img, 0, 0);
}

void	render_map(t_mlx *mlx)
{
	int			x;
	int			y;
	char 		**map;
	t_rect		tile;
	int			height = floor(W_WIDTH / 4 / TSIZE), width = floor(W_WIDTH / 4 / TSIZE);

	y = -1;
	int offset_x = (int)(mlx->player->x) % TSIZE_SCALE;
	int offset_y = (int)(mlx->player->y) % TSIZE_SCALE;
	map = map_mask(*get_data(), mlx->player);
	while (++y < height)
	{
		x = -1;
		while (++x < width)
		{
			tile.x = (x * TSIZE_SCALE);
			tile.y = (y * TSIZE_SCALE);
			tile.width = TSIZE_SCALE;
			tile.height = TSIZE_SCALE;
			tile.fillclr = get_rgba(0, 0, 0, 200);
			if ((y < height && x < width) && (map[y][x] == '0' || is_player(map[y][x])))
				tile.fillclr = get_rgba(255, 255, 255, 0);
			tile.edgeclr = tile.fillclr;
			drawrect(mlx->img, tile);
		}
	}
}

static void	render_player(t_mlx *mlx)
{
	int			pos;
	t_circle	circle;

	pos = W_WIDTH / 4 / TSIZE / 2;
	circle.cx = round(pos * TSIZE_SCALE + (TSIZE_SCALE / 2));
	circle.cy = round(pos * TSIZE_SCALE + (TSIZE_SCALE / 2));
	circle.radius = mlx->player->radius * 1;
	circle.color = get_rgba(0, 255, 150, 150);
	drawcircle(mlx, circle);
	/*************************************************/
	t_line	penis;
	penis.x0 = round(pos * TSIZE_SCALE + (TSIZE_SCALE / 2));
	penis.y0 = round(pos * TSIZE_SCALE + (TSIZE_SCALE / 2));
	penis.x1 = penis.x0 + cos(mlx->player->angle) * TSIZE_SCALE;
	penis.y1 = penis.y0 + sin(mlx->player->angle) * TSIZE_SCALE;
	drawline(mlx, penis, get_rgba(0, 255, 150, 150));
	/*************************************************/
}

// static void	render_rays(t_mlx *mlx)
// {
// 	int		i;
// 	t_line	line;

// 	i = -1;
// 	while (++i < mlx->nrays)
// 	{
// 		line.x0 = mlx->player->x * SCALE;
// 		line.y0 = mlx->player->y * SCALE;
// 		line.x1 = mlx->rays[i].wallx * SCALE;
// 		line.y1 = mlx->rays[i].wally * SCALE;
// 		drawline(mlx, line, get_rgba(102, 102, 255, 100));
// 	}
// }
