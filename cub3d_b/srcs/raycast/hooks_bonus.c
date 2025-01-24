/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:59:27 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/24 18:09:03 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	key_release(mlx_key_data_t keydata, t_mlx *mlx);

void	init_mouse_pos(t_mlx *mlx, int mid_x, int mid_y)
{
	mlx_set_mouse_pos(mlx->mlxi, mid_x, mid_y);
	mlx_set_cursor_mode(mlx->mlxi, MLX_MOUSE_HIDDEN);
	mlx->first_mouse = true;	
}

void mouse_hdl(double x, double y, void* param)
{
	t_mlx			*mlx;
	t_dimension		dim;
	int				mid_x;
	int				mid_y;

	1 && (mid_x = W_WIDTH / 2, mid_y = W_HEIGHT / 2, mlx = *get_mlx());
	if (!mlx->first_mouse)
		init_mouse_pos(mlx, mid_x, mid_y);
	else
	{
		mlx_get_monitor_size(0, &dim.mon_w, &dim.mon_h);
		mlx_get_window_pos(mlx->mlxi, &dim.win_x, &dim.win_y);
		if (dim.win_x < 0)
			mid_x = ((W_WIDTH + dim.win_x) / 2) - dim.win_x;
		else if (dim.win_x + W_WIDTH > dim.mon_w)
			mid_x = (dim.mon_w - dim.win_x) / 2;
		if (mid_x > x)
			mlx->player->angle -= 0.04;
		else if (mid_x < x)
			mlx->player->angle += 0.04;
		if (x < mid_x || x > mid_x)
			mlx_set_mouse_pos(mlx->mlxi, mid_x, mid_y);		
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
