/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:53:26 by ael-amma          #+#    #+#             */
/*   Updated: 2024/12/25 11:58:49 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	game(void)
{
	mlx_t		*mlx;
	t_data		*data;
	t_player	player;

	player = (t_player){0};
	data = *get_data();
	mlx = mlx_init(W_WIDTH, W_HEIGHT, data->title, true);
	mlx_loop(mlx);
	// todo
}
