/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:35:24 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/25 03:13:12 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	game_loop(void *vmlx);
static void	cleaner(void *vmlx);

void	game(void)
{
	t_mlx	mlx;

	mlx = (t_mlx){0};
	(*get_mlx()) = &mlx;
	setup(&mlx, *get_data());
	mlx_key_hook(mlx.mlxi, key_press, &mlx);
	mlx_cursor_hook(mlx.mlxi, mouse_hdl, NULL);
	mlx_loop_hook(mlx.mlxi, game_loop, &mlx);
	mlx_close_hook(mlx.mlxi, cleaner, &mlx);
	mlx_loop(mlx.mlxi);
	ft_exit(&mlx, EXIT_SUCCESS);
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

static
void	cleaner(void *vmlx)
{
	t_mlx	*mlx;

	mlx = vmlx;
	ft_exit(mlx, EXIT_SUCCESS);
}
