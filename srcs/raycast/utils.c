/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:34:54 by ael-amma          #+#    #+#             */
/*   Updated: 2024/12/25 15:03:06 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_monitor_size(t_mlx *mlx)
{
	void	*tmp;

	tmp = salloc(mlx_init(1, 1, "", 0), 1);
	mlx_get_monitor_size(0, &mlx->win_w, &mlx->win_h);
	mlx_close_window(tmp);
	mlx_terminate(tmp);
}

int	get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	drawrect(mlx_image_t *img, t_rect tile, uint32_t color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tile.height)
	{
		j = -1;
		while (++j < tile.width)
			mlx_put_pixel(img, tile.x + j, tile.y + i, color);
	}
}
