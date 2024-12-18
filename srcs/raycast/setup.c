/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:38:41 by ael-amma          #+#    #+#             */
/*   Updated: 2024/12/18 18:31:15 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_monitor_size(void);

void	initialize(void)
{
	t_data	*data;
	t_rdata	*rdata;

	data = *get_data();
	rdata = salloc(malloc(sizeof(t_rdata)));
	*get_rdata() = rdata;
	get_monitor_size();
	// if (data->x * SIZE_SCALE > rdata->width / 2 || \
	// 	data->y * SIZE_SCALE > rdata->height / 2)
	// 	ft_error("Try a smaller map :)", 1);
	rdata->mlx = salloc(mlx_init(rdata->width, rdata->height, data->title, 1));
	rdata->img = salloc(mlx_new_image(rdata->mlx, rdata->width, rdata->height));
}

void	setup(void)
{
	t_data	*data;
	t_rdata	*rdata;

	data = *get_data();
	rdata = *get_rdata();
	rdata->player = salloc(malloc(sizeof(t_player)));
}

static void	get_monitor_size(void)
{
	void	*mlx;
	t_rdata	*rdata;

	rdata = *get_rdata();
	mlx = salloc(mlx_init(1, 1, "", 0));
	mlx_get_monitor_size(0, &rdata->width, &rdata->height);
	mlx_close_window(mlx);
	mlx_terminate(mlx);
}
