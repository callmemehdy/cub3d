/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:38:41 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/24 16:54:18 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_player(t_mlx *mlx);

void	setup(t_mlx *mlx, t_data *data)
{
	mlx->data = data;
	mlx->mlxi = salloc(mlx_init(W_WIDTH, W_HEIGHT, data->title, 0), 1);
	mlx->player = salloc(ft_malloc(sizeof(t_player)), 0);
	mlx->width = data->x * TSIZE;
	mlx->height = data->y * TSIZE;
	mlx->space = false;
	mlx->frames = load_frames();
	mlx->rays = ft_malloc(sizeof(t_ray) * NUM_RAYS);
	mlx->lastframe = 0;
	mlx->img = NULL;
	mlx->key = false;
	mlx->no = salloc(mlx_load_png(mlx->data->no_path), 1);
	mlx->so = salloc(mlx_load_png(mlx->data->so_path), 1);
	mlx->we = salloc(mlx_load_png(mlx->data->we_path), 1);
	mlx->ea = salloc(mlx_load_png(mlx->data->ea_path), 1);
	mlx->aim = salloc(mlx_load_png("textures/aim.png"), 1);
	mlx->cdoor = salloc(mlx_load_png("textures/bunkerCD.png"), 1);
	mlx->odoor = salloc(mlx_load_png("textures/bunkerOD.png"), 1);
	mlx->frame = salloc(mlx_load_png("textures/frame.png"), 1);
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
	mlx->player->walksp = 2 * TSIZE_SCALE;
	mlx->player->turnsp = (2 * TSIZE) * (M_PI / 180);
}
