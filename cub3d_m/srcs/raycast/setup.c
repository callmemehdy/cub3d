/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:24:00 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/21 17:27:31 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_mlx *mlx);

void	setup(t_mlx *mlx, t_data *data)
{
	mlx->data = data;
	mlx->mlxi = salloc(mlx_init(W_WIDTH, W_HEIGHT, data->title, 0), 1);
	mlx->player = salloc(ft_malloc(sizeof(t_player)), 0);
	mlx->width = data->x * TSIZE;
	mlx->height = data->y * TSIZE;
	mlx->rays = salloc(ft_malloc(sizeof(t_ray) * NUM_RAYS), 0);
	mlx->lastframe = 0;
	mlx->img = NULL;
	mlx->no = salloc(mlx_load_png(mlx->data->no_path), 0);
	mlx->so = salloc(mlx_load_png(mlx->data->so_path), 0);
	mlx->we = salloc(mlx_load_png(mlx->data->we_path), 0);
	mlx->ea = salloc(mlx_load_png(mlx->data->ea_path), 0);
	mlx_set_window_pos(mlx->mlxi, 600, 300);
	init_player(mlx);
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
	mlx->player->walksp = 5 * TSIZE;
	mlx->player->turnsp = (3 * TSIZE) * (M_PI / 180);
}
