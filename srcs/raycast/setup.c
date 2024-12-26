/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:38:41 by ael-amma          #+#    #+#             */
/*   Updated: 2024/12/26 14:57:23 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_all(t_data *data, t_mlx *mlx);
static void	init_player(t_mlx *mlx);

void	setup(t_data *data)
{
	t_mlx	mlx;

	init_all(data, &mlx);
	mlx_key_hook(mlx.mlxi, key_press, &mlx);
	mlx_loop_hook(mlx.mlxi, game_loop, &mlx);
	mlx_loop(mlx.mlxi);
	ft_exit(&mlx);
}

static void	init_all(t_data *data, t_mlx *mlx)
{
	get_monitor_size(mlx);
	mlx->data = data;
	mlx->mlxi = salloc(mlx_init(mlx->win_w, mlx->win_h, data->title, 1), 1);
	mlx->player = salloc(ft_malloc(sizeof(t_player)), 0);
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
	mlx->player->x = (mlx->data->px * TSIZE_SCALE) + TSIZE_SCALE / 2;
	mlx->player->y = (mlx->data->py * TSIZE_SCALE) + TSIZE_SCALE / 2;
	mlx->player->fov = FOV * M_PI / 180;
}
