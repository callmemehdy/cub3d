/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:16:07 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/17 20:06:18 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_player(t_mlx *mlx);
// static void	render_rays(t_mlx *mlx);

char	*ft_fill_line(char *s, t_data *data, t_player *player, int index)
{
	char 	*tmp;
	int		i;
	int		j;

	s = 0;
	i = (int)(player->y / TSIZE_SCALE) - 4 + index;
	j = (int)(player->x / TSIZE_SCALE) - 4;
	if (i >= 0 && i < data->y)
	{
		s = ft_malloc(sizeof(char) * 10);
		tmp = s;
		while (j <= (int)(player->x / TSIZE_SCALE + 4))
		{
			if (j >= 0 && j < data->x)
				*s = data->map[i][j];
			else
				*s = '1';
			s++;
			j++;
		}
		*s = 0;
		return (tmp);
	}
	else
		s = ft_strdup("111111111");
	return (s);
}

char	**kernel_masking(t_data *data, t_player *player)
{
	char	**kernel;
	int		i;

	i = -1;
	kernel = ft_malloc(sizeof(char *) * (size_t)10);
	if (!kernel)
		ft_error(ALLOC_ERR, ALLOC_STT);
	while (++i < 9)
		kernel[i] = ft_fill_line(0, data, player, i);
	kernel[i] = 0;
	return (kernel);
}


void	mini_map_testing(t_mlx *mlx, int img)
{
	char 		**map;
	t_rect		tile;
	int			x;
	int			y;
	int			height = 9, width = 9;

	y = -1;
	int offset_x = (int)(mlx->player->x) % TSIZE_SCALE;
	int offset_y = (int)(mlx->player->y) % TSIZE_SCALE;
	// printf("x:%d_y:%d\n", offset_x, offset_y);
	map = kernel_masking(*get_data(), mlx->player);
	while (++y < height)
	{
		x = -1;
		while (++x < width)
		{
			tile.x = (x * TSIZE_SCALE);
			tile.y = (y * TSIZE_SCALE);
			tile.width = TSIZE_SCALE;
			tile.height = TSIZE_SCALE;
			tile.fillclr = get_rgba(0, 0, 0, 200);
			if ((y < height && x < width) && (map[y][x] == '0' || is_player(map[y][x])))
				tile.fillclr = get_rgba(255, 255, 255, 0);
			tile.edgeclr = tile.fillclr;
			if (img == IMG)
				drawrect(mlx->img, tile);
			else
				drawrect(mlx->bg, tile);
		}
	}
}

void	render(t_mlx *mlx)
{
	mlx_delete_image(mlx->mlxi, mlx->img);
	mlx->img = mlx_new_image(mlx->mlxi, W_WIDTH, W_HEIGHT);
	mini_map_testing(mlx, IMG);
	render_player(mlx);
	mlx_image_to_window(mlx->mlxi, mlx->img, 0, 0);
}

void	render_buffer(t_mlx *mlx)
{
	mlx_texture_to_image(mlx->mlxi, mlx->texture);
}

/*
	ive replaced img arg in the above func with mlx struct.
*/
// void	render_minimap(t_mlx *mlx, int img)
// {
// 	t_data		*data;
// 	t_rect		tile;
// 	int			x;
// 	int			y;

// 	y = -1;
// 	data = *get_data();
// 	while (++y < data->y)
// 	{
// 		x = -1;
// 		while (++x < data->x)
// 		{
// 			tile.x = x * TSIZE_SCALE;
// 			tile.y = y * TSIZE_SCALE;
// 			tile.width = TSIZE_SCALE;
// 			tile.height = TSIZE_SCALE;
// 			tile.fillclr = get_rgba(0, 0, 0, 255);
// 			if (data->map[y][x] == '0' || is_player(data->map[y][x]))
// 				tile.fillclr = get_rgba(255, 255, 255, 255);
// 			tile.edgeclr = tile.fillclr;
// 			if (img == IMG)
// 				drawrect(mlx->img, tile);
// 			else
// 				drawrect(mlx->bg, tile);
// 		}
// 	}
// }

static void	render_player(t_mlx *mlx)
{
	t_circle	circle;

	circle.cx = round(4 * TSIZE_SCALE + (TSIZE_SCALE / 2));
	circle.cy = round(4 * TSIZE_SCALE + (TSIZE_SCALE / 2));
	circle.radius = mlx->player->radius * 1;
	circle.color = get_rgba(0, 255, 150, 150);
	drawcircle(mlx, circle);
}

// static void	render_rays(t_mlx *mlx)
// {
// 	int		i;
// 	t_line	line;

// 	i = -1;
// 	while (++i < mlx->nrays)
// 	{
// 		line.x0 = mlx->player->x * SCALE;
// 		line.y0 = mlx->player->y * SCALE;
// 		line.x1 = mlx->rays[i].wallx * SCALE;
// 		line.y1 = mlx->rays[i].wally * SCALE;
// 		drawline(mlx, line, get_rgba(102, 102, 255, 100));
// 	}
// }
