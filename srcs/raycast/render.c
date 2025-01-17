/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:16:07 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/17 23:39:04 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_projplane(t_mlx *mlx);
static void	render_player(t_mlx *mlx);

void	render(t_mlx *mlx)
{
	mlx_delete_image(mlx->mlxi, mlx->img);
	mlx->img = mlx_new_image(mlx->mlxi, W_WIDTH, W_HEIGHT);
	render_projplane(mlx);
	render_map(mlx);
	// render_rays(mlx);
	render_player(mlx);
	mlx_image_to_window(mlx->mlxi, mlx->img, 0, 0);
}

static void	render_projplane(t_mlx *mlx)
{
	t_wall	wall;
	float	proj_dist;
	float	perp_dist;

	wall.x = -1;
	while (++wall.x < NUM_RAYS)
	{
		perp_dist = mlx->rays[wall.x].dist * \
					cos(mlx->rays[wall.x].angle - mlx->player->angle);
		proj_dist = (W_WIDTH / 2) / tan(FOV / 2);
		wall.height = (TSIZE / perp_dist) * proj_dist;
		wall.top = (W_HEIGHT / 2) - (wall.height / 2);
		if (wall.top < 0)
			wall.top = 0;
		wall.bot = (W_HEIGHT / 2) + (wall.height / 2);
		if (wall.bot > W_HEIGHT)
			wall.bot = W_HEIGHT;
		wall.color = get_rgba(0, 51, 102, 200);
		if (mlx->rays[wall.x].wallvert)
			wall.color = get_rgba(0, 51, 102, 255);
		wall.y = -1;
		while (++wall.y < wall.top)
			mlx_put_pixel(mlx->img, wall.x, wall.y, rgbtoa(mlx->data->crgb));
		wall.y = wall.top - 1;
		while (++wall.y < wall.bot)
			mlx_put_pixel(mlx->img, wall.x, wall.y, wall.color);
		wall.y = wall.bot - 1;
		while (++wall.y < W_HEIGHT)
			mlx_put_pixel(mlx->img, wall.x, wall.y, rgbtoa(mlx->data->frgb));
	}
}

void	render_map(t_mlx *mlx)
{
	int			x;
	int			y;
	char 		**map;
	t_rect		tile;
	int			height = 15, width = 15;

	y = -1;
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
			tile.color = get_rgba(255, 255, 255, 255);
			if ((y < height && x < width) && (map[y][x] == '0' || is_player(map[y][x])))
				continue ;
			drawrect(mlx->img, tile);
		}
	}
}

static void	render_player(t_mlx *mlx)
{
	int			pos;
	t_circle	circle;

	pos = W_WIDTH / 4 / TSIZE / 2;


	/*************************************************/
	t_line	penis;
	penis.x0 = round(pos * TSIZE_SCALE + (TSIZE_SCALE / 2));
	penis.y0 = round(pos * TSIZE_SCALE + (TSIZE_SCALE / 2));
	penis.x1 = penis.x0 + cos(mlx->player->angle) * TSIZE_SCALE;
	penis.y1 = penis.y0 + sin(mlx->player->angle) * TSIZE_SCALE;
	drawline(mlx, penis, get_rgba(0, 0, 0, 255));
	/*************************************************/


	circle.cx = round(pos * TSIZE_SCALE + (TSIZE_SCALE / 2));
	circle.cy = round(pos * TSIZE_SCALE + (TSIZE_SCALE / 2));
	circle.radius = mlx->player->radius * 1;
	circle.color = get_rgba(255, 255, 255, 255);
	drawcircle(mlx, circle);
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
