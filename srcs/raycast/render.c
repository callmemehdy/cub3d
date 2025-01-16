/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:16:07 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/16 13:28:56 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_player(t_mlx *mlx);
static void	render_rays(t_mlx *mlx);

void	render_walls(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < mlx->nrays)
	{
		float	prodist = (W_WIDTH / 2) / tan(FOV / 2);
		int		prowallheight = (TSIZE / mlx->rays[i].dist) * prodist;
		int		walltop = (W_HEIGHT / 2) - (prowallheight / 2);
		if (walltop < 0)
			walltop = 0;
		int		wallbot = (W_HEIGHT / 2) + (prowallheight / 2);
		if (wallbot > W_HEIGHT)
			wallbot = W_HEIGHT;
		int	y = walltop;
		while (y < wallbot)
		{
			mlx_put_pixel(mlx->img, i, y, get_rgba(0, 51, 102, 255));
			y++;
		}
	}
}

void	render(t_mlx *mlx)
{
	mlx_delete_image(mlx->mlxi, mlx->img);
	mlx->img = mlx_new_image(mlx->mlxi, W_WIDTH, W_HEIGHT);
	render_walls(mlx);
	render_minimap(mlx->img);
	render_rays(mlx);
	render_player(mlx);
	mlx_image_to_window(mlx->mlxi, mlx->img, 0, 0);
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
	t_line	line;

	i = -1;
	while (++i < mlx->nrays)
	{
		line.x0 = mlx->player->x * SCALE;
		line.y0 = mlx->player->y * SCALE;
		line.x1 = mlx->rays[i].wallx * SCALE;
		line.y1 = mlx->rays[i].wally * SCALE;
		drawline(mlx, line, get_rgba(102, 102, 255, 100));
	}
}
