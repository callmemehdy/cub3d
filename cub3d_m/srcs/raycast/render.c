/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:23:44 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/20 12:01:28 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void				render_game(t_mlx *mlx);
static void				paint_wall(t_mlx *mlx, t_wall wall);
static int				get_pixel(t_mlx *mlx, t_wall wall, int offx);
static mlx_texture_t	*which_texture(t_mlx *mlx, int i);

void	render(t_mlx *mlx)
{
	mlx_delete_image(mlx->mlxi, mlx->img);
	mlx->img = mlx_new_image(mlx->mlxi, W_WIDTH, W_HEIGHT);
	render_game(mlx);
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

static void	paint_wall(t_mlx *mlx, t_wall wall)
{
	int		offx;

	wall.y = -1;
	while (++wall.y < wall.top)
		mlx_put_pixel(mlx->img, wall.x, wall.y, fetch_rgba(mlx->data->crgb));
	if (mlx->rays[wall.x].wallvert)
		offx = (int)mlx->rays[wall.x].wally % TSIZE;
	else
		offx = (int)mlx->rays[wall.x].wallx % TSIZE;
	wall.y = wall.top - 1;
	while (++wall.y < wall.bot)
		mlx_put_pixel(mlx->img, wall.x, wall.y, get_pixel(mlx, wall, offx));
	wall.y = wall.bot - 1;
	while (++wall.y < W_HEIGHT)
		mlx_put_pixel(mlx->img, wall.x, wall.y, fetch_rgba(mlx->data->frgb));
}

static int	get_pixel(t_mlx *mlx, t_wall wall, int offx)
{
	int				offy;
	int				dist_top;
	mlx_texture_t	*tx;

	tx = mlx->texture;
	dist_top = wall.y + (wall.height / 2) - (W_HEIGHT / 2);
	offy = dist_top * ((float)TSIZE / wall.height);
	if (tx == mlx->so || tx == mlx->we)
		offx = TSIZE - 1 - offx;
	return (tx->pixels[(TSIZE * offy + offx) * 4] << 24
		| tx->pixels[(TSIZE * offy + offx) * 4 + 1] << 16
		| tx->pixels[(TSIZE * offy + offx) * 4 + 2] << 8
		| tx->pixels[(TSIZE * offy + offx) * 4 + 3]);
}

static mlx_texture_t	*which_texture(t_mlx *mlx, int i)
{
	if (mlx->rays[i].wallvert)
	{
		if (mlx->rays[i].right)
			return (mlx->ea);
		else
			return (mlx->we);
	}
	else
	{
		if (mlx->rays[i].down)
			return (mlx->so);
		else
			return (mlx->no);
	}
}
