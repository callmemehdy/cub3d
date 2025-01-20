/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:35:24 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/19 11:23:14 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	game_loop(void *vmlx);

void	game(void)
{
	t_mlx	mlx;

	(*get_mlx()) = &mlx;
	setup(&mlx, *get_data());
	mlx_key_hook(mlx.mlxi, key_press, &mlx);
	mlx_loop_hook(mlx.mlxi, game_loop, &mlx);
	mlx_loop(mlx.mlxi);
	ft_exit(&mlx);
}

static void	game_loop(void *vmlx)
{
	int		wait;
	int		framtime;
	t_mlx	*mlx;

	mlx = vmlx;
	framtime = 1000 / FPS;
	wait = framtime - ((mlx_get_time() * 1000) - mlx->lastframe);
	if (wait > 0 && wait <= framtime)
		usleep(wait * 1000);
	mlx->lastframe = mlx_get_time() * 1000;
	update(mlx);
	render(mlx);
}
