/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:53:26 by ael-amma          #+#    #+#             */
/*   Updated: 2024/12/14 16:06:09 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game(void)
{
	t_data *data = *get_data();

	mlx_t *mlx = mlx_init(data->x * 32, data->y * 32, data->title, true);
	mlx_image_t *img = mlx_new_image(mlx, data->x * 32, data->y * 32);
	for (int i = 0; i < data->y; ++i) {
		for (int j = 0; j < data->x; ++j) {
			mlx_put_pixel(img, j * 32, i * 32, 0x99FF0000);
		}
	}
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
}
