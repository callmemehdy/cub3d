/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:53:26 by ael-amma          #+#    #+#             */
/*   Updated: 2024/12/25 15:56:06 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	put_tile(mlx_image_t *img, int y, int x, unsigned int color)
{
	
	for (int i = y; i < y + T_SIZE; i++) {
		for (int j = x; j < x + T_SIZE; j++) {
			mlx_put_pixel(img, j, i, color);
		}
	}
}

void	game(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_data		*data;
	t_player	player;

	player = (t_player){0};
	data = *get_data();
	mlx = mlx_init(W_WIDTH, W_HEIGHT, data->title, true);
	img = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
	for (int i = 0; i < data->y; i++) {
		for (int j = 0; j < data->x; j++) {
			if (data->map[i][j] == '1') {
				put_tile(img, i * T_SIZE, j * T_SIZE, 0xFF0000FF);
			}
			else if (data->map[i][j] == '0')
				put_tile(img, i * T_SIZE, j * T_SIZE, 0x00FF00FF);
			else if (is_player(data->map[i][j]))
				put_tile(img, i * T_SIZE, j * T_SIZE, 0x0000FFFF);
			else		
				put_tile(img, i * T_SIZE, j * T_SIZE, 0xFF00FFFF);
		}
	}
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	// todo
}
