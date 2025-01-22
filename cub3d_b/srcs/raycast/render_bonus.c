/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:16:07 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/22 11:36:54 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	render_game(t_mlx *mlx);
static void	render_player(t_mlx *mlx);

// void	overlay_images(mlx_image_t *base, mlx_image_t *overlay, int x_off, int y_off)
// {
// 	uint32_t	*base_pixels;
// 	uint32_t	*overlay_pixels;
// 	int			cxp[2]; // x,y coors
// 	int			base_index;
// 	int			overlay_index;

// 	1 && (cxp[0] = 0, base_pixels = (uint32_t*)base->pixels);
// 	overlay_pixels = (uint32_t*)overlay->pixels;
// 	while (cxp[0] < overlay->height)
// 	{
// 		cxp[1] = 0;
// 		while (cxp[1] < overlay->width)
// 		{
// 			base_index = (cxp[0] + y_off) * base->width + (cxp[1] + x_off);
// 			overlay_index = cxp[0] * overlay->width + cxp[1];
// 			if (!((overlay_pixels[overlay_index] >> 24) & 0xFF) && ++cxp[1])
// 				continue;
// 			// use any color here to represent the frame color hh
// 			// base_pixels[base_index] = ((u_int32_t)140 << 24) |\
// 			// ((uint32_t)200 << 16) |\
// 			// ((uint32_t)0 << 8) | 0;
// 			base_pixels[base_index] = overlay_pixels[overlay_index];
// 			++cxp[1];
// 		}
// 		++cxp[0];
// 	}
// }

// void	render_sprite(mlx_image_t *sprite)
// {
// 	t_mlx			*mlx;

// 	mlx = *get_mlx();
// 	overlay_images(mlx->img, sprite, (W_WIDTH / 2) - (SPRITE_W / 2), W_HEIGHT - SPRITE_H);
// 	mlx_delete_image(mlx->mlxi, sprite);
// }

// void	render_aim()
// {
// 	t_mlx			*mlx;
// 	mlx_image_t		*sprite;
// 	mlx_texture_t	*text;

// 	mlx = *get_mlx();
// 	text = mlx_load_png("/home/mel-akar/1337CC/Cub3d/cub3d_b/textures/aim.png");
// 	sprite = mlx_texture_to_image(mlx->mlxi, text);
// 	mlx_delete_texture(text);
// 	overlay_images(mlx->img, sprite, (W_WIDTH / 2) - (40 / 2), (W_HEIGHT / 2) - (40 / 2));
// 	mlx_delete_image(mlx->mlxi, sprite);
	
// }

void	render(t_mlx *mlx)
{
	mlx_delete_image(mlx->mlxi, mlx->img);
	mlx->img = mlx_new_image(mlx->mlxi, W_WIDTH, W_HEIGHT);
	render_game(mlx);
	render_map(mlx);
	render_player(mlx);
	// free the kernel ...
	// render_sprite(mlx->sprite);
	// render_aim();
	// overlay_images(mlx->img, mlx->frame, 0, 0);
	mlx_image_to_window(mlx->mlxi, mlx->img, 0, 0);
}

static void	render_game(t_mlx *mlx)
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

	pos = 7;


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
