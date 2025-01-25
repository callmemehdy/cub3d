/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:16:07 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/25 00:53:51 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	render_game(t_mlx *mlx);
static void	render_player(t_mlx *mlx);
static void	render_map(t_mlx *mlx);
static void	render_sprite(t_mlx *mlx);

void	render(t_mlx *mlx)
{
	mlx_delete_image(mlx->mlxi, mlx->img);
	mlx->img = mlx_new_image(mlx->mlxi, W_WIDTH, W_HEIGHT);
	render_game(mlx);
	render_map(mlx);
	render_player(mlx);
	render_sprite(mlx);
	mlx_image_to_window(mlx->mlxi, mlx->img, 0, 0);
}

static
void	render_game(t_mlx *mlx)
{
	t_wall	wall;
	float	proj_dist;
	float	perp_dist;

	wall.x = -1;
	while (++wall.x < NUM_RAYS)
	{
		mlx->texture = which_texture(mlx, wall.x);
		perp_dist = mlx->rays[wall.x].dist * \
					cos(mlx->rays[wall.x].angle - mlx->player->angle);
		proj_dist = (W_WIDTH / 2) / tan((FOV * (M_PI / 180)) / 2);
		wall.height = (TSIZE / perp_dist) * proj_dist;
		wall.top = (W_HEIGHT / 2) - (wall.height / 2);
		if (wall.top < 0)
			wall.top = 0;
		wall.bot = (W_HEIGHT / 2) + (wall.height / 2);
		if (wall.bot > W_HEIGHT)
			wall.bot = W_HEIGHT;
		paint_wall(mlx, wall);
	}
}

static
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
			tile.color = get_rgba(64, 64, 64, 255);
			if ((y < height && x < width) && (map[y][x] == '0' || is_player(map[y][x])))
				tile.color = get_rgba(0, 0, 0, 255);
			else if (map[y][x] == 'O')
				tile.color = get_rgba(128, 128, 128, 255);
			drawrect(mlx->img, tile);
		}
	}
	free_2d(map);
}

static
void	render_player(t_mlx *mlx)
{
	int			pos;
	t_circle	circle;

	pos = 7;
	circle.cx = round(pos * TSIZE_SCALE + (TSIZE_SCALE / 2));
	circle.cy = round(pos * TSIZE_SCALE + (TSIZE_SCALE / 2));
	circle.radius = mlx->player->radius * 1;
	circle.color = get_rgba(255, 255, 255, 255);
	drawcircle(mlx, circle);
}

static
void	render_sprite(t_mlx *mlx)
{
	static int	i;
	static int frame_count;

	if (mlx->space)
	{
		i++;
		overlay_images(mlx->img, mlx->frames.gun_txt[frame_count % 50], \
		(W_WIDTH / 2) - (SPRITE_W / 2), W_HEIGHT - SPRITE_H);
		if (!(i % 2))
			frame_count++;
		if (frame_count % 50 == 49)
			'M' && (i = 1, mlx->space = false);
	}
	overlay_images(mlx->img, mlx->aim, \
	(W_WIDTH / 2) - (40 / 2), (W_HEIGHT / 2) - (40 / 2));
	overlay_images(mlx->img, mlx->frame, 0, 0);
}
