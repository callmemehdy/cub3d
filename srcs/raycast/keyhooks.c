/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:59:27 by ael-amma          #+#    #+#             */
/*   Updated: 2024/12/25 15:57:46 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	key_release(mlx_key_data_t keydata, t_mlx *mlx);

void	game_loop(void *vmlx)
{
	t_mlx	*mlx;

	mlx = vmlx;
	mlx_delete_image(mlx->mlxi, mlx->img);
	mlx->img = mlx_new_image(mlx->mlxi, mlx->win_w, mlx->win_h);
	render_minimap(mlx);
	mlx_image_to_window(mlx->mlxi, mlx->img, 0, 0);
}

void	key_press(mlx_key_data_t keydata, void *vmlx)
{
	t_mlx	*mlx;

	mlx = vmlx;
	if (keydata.key == MLX_KEY_ESCAPE)
		ft_exit(mlx);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		mlx->player->walk = 1;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		mlx->player->turn = -1;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		mlx->player->walk = -1;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		mlx->player->turn = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		mlx->player->rot = -1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		mlx->player->rot = 1;
	key_release(keydata, mlx);
}

static void	key_release(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		mlx->player->walk = 0;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		mlx->player->turn = 0;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		mlx->player->walk = 0;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		mlx->player->turn = 0;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		mlx->player->rot = 0;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		mlx->player->rot = 0;
}
