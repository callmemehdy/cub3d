/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:53:26 by ael-amma          #+#    #+#             */
/*   Updated: 2024/12/18 14:57:37 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	put_square(mlx_image_t	*img, int x, int y, int tile_size)
{
	int tmp = y;
	
	while (y < tmp + 32) {
		x = 0;
		if (y % 32 == 0) {
			while (x < tile_size) {
				mlx_put_pixel(img, x, y, 0x00FF00FF);
				x++;
			}
			y++;
			continue ;
		}
		while (x < tile_size) {
			if (x % 32 == 0) {
				mlx_put_pixel(img, x, y, 0x00FF00FF);
				x++;
				continue ;
			}
			mlx_put_pixel(img, x, y, 0xFF0000FF);
			x++;
		}
		y++;
	}

}

void	game(void)
{
	t_data *data = *get_data();

	mlx_t *mlx = mlx_init(data->x * 32, data->y * 32, data->title, true);
	mlx_image_t *img = mlx_new_image(mlx, data->x * 32, data->y * 32);
	for (int i = 0; i  < data->y; i++) {
		put_square(img, 0,  i * 32, data->x * 32);
	}
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
}
