/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:13:41 by mel-akar          #+#    #+#             */
/*   Updated: 2025/01/22 10:01:16 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_frame	load_frames()
{
	t_frame		data;
	t_mlx		*mlx;

	mlx = *get_mlx();
	data.gun_txt[0] = mlx_load_png("/home/mel-akar/1337CC/Cub3d/cub3d_b/textures/1.png");
	data.gun_txt[1] = mlx_load_png("/home/mel-akar/1337CC/Cub3d/cub3d_b/textures/2.png");
	data.gun_txt[2] = mlx_load_png("/home/mel-akar/1337CC/Cub3d/cub3d_b/textures/3.png");
	data.gun_txt[3] = mlx_load_png("/home/mel-akar/1337CC/Cub3d/cub3d_b/textures/4.png");
	data.gun_txt[4] = mlx_load_png("/home/mel-akar/1337CC/Cub3d/cub3d_b/textures/5.png");
	if (!data.gun_txt[0] || !data.gun_txt[1] || !data.gun_txt[2]\
						 || !data.gun_txt[3] || !data.gun_txt[4])
	{
		ft_error(ALLOC_ERR, ALLOC_STT);
	}
	data.gun[0] = mlx_texture_to_image(mlx->mlxi, data.gun_txt[0]);	
	data.gun[1] = mlx_texture_to_image(mlx->mlxi, data.gun_txt[1]);	
	data.gun[2] = mlx_texture_to_image(mlx->mlxi, data.gun_txt[2]);	
	data.gun[3] = mlx_texture_to_image(mlx->mlxi, data.gun_txt[3]);	
	data.gun[4] = mlx_texture_to_image(mlx->mlxi, data.gun_txt[4]);	
	if (!data.gun[0] || !data.gun[1] || !data.gun[2]\
					 || !data.gun[3] || !data.gun[4])
	{
		ft_error(ALLOC_ERR, ALLOC_STT);
	}
	mlx_delete_texture(data.gun_txt[0]);
	mlx_delete_texture(data.gun_txt[1]);
	mlx_delete_texture(data.gun_txt[2]);
	mlx_delete_texture(data.gun_txt[3]);
	mlx_delete_texture(data.gun_txt[4]);
	return (data);
}

void	shoot_down(t_mlx *mlx, t_frame *frm)
{
	int		times;

	times = 0;
	while (times < 5)
	{
		mlx_image_to_window(mlx->mlxi, frm->gun[times], 0, 0);
		// render(mlx);
		++times;
	}
}