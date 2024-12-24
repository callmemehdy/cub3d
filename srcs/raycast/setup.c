/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:38:41 by ael-amma          #+#    #+#             */
/*   Updated: 2024/12/24 19:46:19 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialize_win(t_data *data);
static void	get_monitor_size(t_mata *mata);

void	setup(void)
{
	t_data	*data;
	t_mata	*mata;

	data = *get_data();
	initialize_win(data);
	mata = *get_mata();
	mata->player = salloc(malloc(sizeof(t_player)));
}

static void	initialize_win(t_data *data)
{
	t_mata	*mata;

	mata = salloc(malloc(sizeof(t_mata)));
	*get_mata() = mata;
	get_monitor_size(mata);
	if (data->x * SIZE_SCALE > mata->width / 2 || \
		data->y * SIZE_SCALE > mata->height / 2)
		ft_error("The map is too big :)", 1);
	mata->mlx = salloc(mlx_init(mata->width, mata->height, data->title, 1));
	mata->img = salloc(mlx_new_image(mata->mlx, mata->width, mata->height));
}

static void	get_monitor_size(t_mata *data)
{
	void	*mlx;

	mlx = salloc(mlx_init(1, 1, "", 0));
	mlx_get_monitor_size(0, &data->width, &data->height);
	mlx_close_window(mlx);
	mlx_terminate(mlx);
}
