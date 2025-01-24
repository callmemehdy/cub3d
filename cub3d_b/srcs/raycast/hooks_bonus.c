/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:59:27 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/24 03:07:09 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	key_release(mlx_key_data_t keydata, t_mlx *mlx);

int		curr_x;
bool	first = false;

void mouse_hdl(double x, double y, void* param)
{
	t_mlx			*mlx;
	int				padder;
	int				win_x;

	// make some var for the center of the visible portion of the window
	1 && (mlx = *get_mlx(), padder = 0);
	if (!first)
	{
		mlx_set_mouse_pos(mlx->mlxi, W_WIDTH / 2, W_HEIGHT / 2);
		mlx_set_cursor_mode(mlx->mlxi, MLX_MOUSE_HIDDEN);
		first = true;
	}
	else
	{
		mlx_get_window_pos(mlx->mlxi, &win_x, &padder);
		if (curr_x > x)
			mlx->player->angle -= 0.04;
		else if (curr_x < x)
			mlx->player->angle += 0.04;
		curr_x = x;
		if (x < W_WIDTH / 2 || x > W_WIDTH / 2 || win_x < 0)
			mlx_set_mouse_pos(mlx->mlxi, W_WIDTH / 2, W_HEIGHT / 2);		
	}
}


void	key_press(mlx_key_data_t keydata, void *vmlx)
{
	t_mlx	*mlx;

	mlx = vmlx;
	mlx_cursor_hook(mlx->mlxi, mouse_hdl, NULL);
	if (keydata.key == MLX_KEY_ESCAPE)
		ft_exit(mlx);
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
