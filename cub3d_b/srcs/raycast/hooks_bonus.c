/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:59:27 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/24 22:13:03 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	key_release(mlx_key_data_t keydata, t_mlx *mlx);


// Mouse handler function matching MLX42's required signature
void mouse_hdl(mouse_key_t key, action_t action, modifier_key_t mods, void* param)
{
    if (action == MLX_PRESS)
        printf("Mouse button %d pressed\n", key);
    else if (action == MLX_RELEASE)
        printf("Mouse button %d released\n", key);
}


void	key_press(mlx_key_data_t keydata, void *vmlx)
{
	t_mlx	*mlx;

	mlx = vmlx;
	mlx_mouse_hook(mlx->mlxi, mouse_hdl, NULL);
	if (keydata.key == MLX_KEY_ESCAPE)
		ft_exit(mlx, EXIT_SUCCESS);
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W)
			mlx->player->walkdir = 1;
		else if (keydata.key == MLX_KEY_S)
			mlx->player->walkdir = -1;
		else if (keydata.key == MLX_KEY_A)
			mlx->player->strafe = -1;
		else if (keydata.key == MLX_KEY_D)
			mlx->player->strafe = 1;
		else if (keydata.key == MLX_KEY_LEFT)
			mlx->player->turndir = -1;
		else if (keydata.key == MLX_KEY_RIGHT)
			mlx->player->turndir = 1;
		else if (keydata.key == MLX_KEY_E)
			mlx->key = true;
		else if (keydata.key == MLX_KEY_SPACE)
			mlx->space = true;	
	}
	key_release(keydata, mlx);
}

static void	key_release(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_W)
			mlx->player->walkdir = 0;
		else if (keydata.key == MLX_KEY_S)
			mlx->player->walkdir = 0;
		else if (keydata.key == MLX_KEY_A)
			mlx->player->strafe = 0;
		else if (keydata.key == MLX_KEY_D)
			mlx->player->strafe = 0;
		else if (keydata.key == MLX_KEY_LEFT)
			mlx->player->turndir = 0;
		else if (keydata.key == MLX_KEY_RIGHT)
			mlx->player->turndir = 0;
	}
}
