/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c_noob <c_noob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:38:41 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/17 22:32:59 by c_noob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_mlx *mlx);
static void	init_bg(t_mlx *mlx);

void	setup(t_mlx *mlx, t_data *data)
{
	mlx->data = data;
	mlx->mlxi = salloc(mlx_init(W_WIDTH, W_HEIGHT, data->title, 0), 1);
	mlx->player = salloc(ft_malloc(sizeof(t_player)), 0);
	mlx->width = data->x * TSIZE;
	mlx->height = data->y * TSIZE;
	mlx->rays = ft_malloc(sizeof(t_ray) * NUM_RAYS);
	mlx->lastframe = 0;
	mlx->img = NULL;
	mlx_set_window_pos(mlx->mlxi, 600, 300);
	init_player(mlx);
	mlx->bg = mlx_new_image(mlx->mlxi, W_WIDTH, W_HEIGHT);
	init_bg(mlx);
}

static void	init_player(t_mlx *mlx)
{
	char	c;

	c = mlx->data->map[mlx->data->py][mlx->data->px];
	if (c == 'E')
		mlx->player->angle = 0;
	else if (c == 'S')
		mlx->player->angle = M_PI / 2;
	else if (c == 'W')
		mlx->player->angle = M_PI;
	else if (c == 'N')
		mlx->player->angle = 3 * M_PI / 2;
	mlx->player->x = mlx->data->px * TSIZE + (TSIZE / 2);
	mlx->player->y = mlx->data->py * TSIZE + (TSIZE / 2);
	mlx->player->radius = 6;
	mlx->player->turndir = 0;
	mlx->player->walkdir = 0;
	mlx->player->strafe = 0;
	mlx->player->walksp = 4 * TSIZE_SCALE;
	mlx->player->turnsp = (3 * TSIZE) * (M_PI / 180);
}

static void	init_bg(t_mlx *mlx)
{
	int	x;
	int	y;

	y = -1;
	while (++y < W_HEIGHT)
	{
		x = -1;
		while (++x < W_WIDTH)
			mlx_put_pixel(mlx->bg, x, y, get_rgba(255, 255, 255, 128));
	}
	mlx_image_to_window(mlx->mlxi, mlx->bg, 0, 0);
}
