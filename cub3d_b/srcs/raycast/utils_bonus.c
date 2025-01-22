/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:34:54 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/22 09:26:15 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_rgba(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	rgbtoa(uint32_t rgb)
{
	return (rgb << 24 | ((rgb >> 8) & 255) << 16 | ((rgb >> 16) & 255) << 8 | 255);
}

bool	wallhit(float x, float y)
{
	int		mapx;
	int		mapy;
	t_data	*data;
	t_mlx	*mlx;

	mlx = *get_mlx();
	data = mlx->data;
	if (x < 0 || x >= mlx->width || y < 0 || y >= mlx->height)
		return (true);
	mapx = floor(x / TSIZE);
	mapy = floor(y / TSIZE);
	return (data->map[mapy][mapx] != '0' \
		&& !is_player(data->map[mapy][mapx]));
}

float	norm_angle(float angle)
{
	angle = remainder(angle, T_PI);
	if (angle < 0)
		angle = T_PI + angle;
	return (angle);
}

float	linelen(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
