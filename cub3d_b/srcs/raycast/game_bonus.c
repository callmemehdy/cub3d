/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:35:24 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/22 09:04:28 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	game_loop(void *vmlx);

void	game(void)
{
	t_mlx	mlx;

	(*get_mlx()) = &mlx;
	setup(&mlx, *get_data());
	mlx_texture_t *frame = mlx_load_png("/home/mel-akar/Downloads/map_frame.png");
	mlx.frame = mlx_texture_to_image((&mlx)->mlxi, frame);
	mlx_key_hook(mlx.mlxi, key_press, &mlx);
	mlx_loop_hook(mlx.mlxi, game_loop, &mlx);
	mlx_loop(mlx.mlxi);
	ft_exit(&mlx);
}

static void	game_loop(void *vmlx)
{
	int		wait;
	t_mlx	*mlx;

	mlx = vmlx;
	wait = FTL - ((mlx_get_time() * 1000) - mlx->lastframe);
	if (wait > 0 && wait <= FTL)
		usleep(wait * 1000);
	mlx->lastframe = mlx_get_time() * 1000;
	update(mlx);
	render(mlx);
}
