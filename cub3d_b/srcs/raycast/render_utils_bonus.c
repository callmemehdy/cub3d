/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 09:03:21 by mel-akar          #+#    #+#             */
/*   Updated: 2025/01/22 16:00:46 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	**map_mask(t_data *data, t_player *player)
{
	int		i;
	char	**kernel;

	i = -1;
	kernel = ft_malloc(sizeof(char *) * (size_t)16);
	if (!kernel)
		ft_error(ALLOC_ERR, ALLOC_STT);
	while (++i < 15)
		kernel[i] = fill_line(0, data, player, i);
	kernel[i] = 0;
	return (kernel);
}

char	*fill_line(char *s, t_data *data, t_player *player, int index)
{
	int		i;
	int		j;
	char 	*tmp;

	s = 0;
	i = (int)((player->y * SCALE) / TSIZE_SCALE) - 7 + index;
	j = (int)((player->x * SCALE) / TSIZE_SCALE) - 7;
	if (i >= 0 && i < data->y)
	{
		s = ft_malloc(sizeof(char) * 16);
		tmp = s;
		while (j <= (int)((player->x / 2) / TSIZE_SCALE + 7))
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
		s = ft_strdup("111111111111111");
	return (s);
}

void	paint_wall(t_mlx *mlx, t_wall wall)
{
	int		offx;

	wall.y = -1;
	while (++wall.y < wall.top)
		mlx_put_pixel(mlx->img, wall.x, wall.y, fetch_rgba(mlx->data->crgb));
	if (mlx->rays[wall.x].wallvert)
		offx = (int)mlx->rays[wall.x].wally % TSIZE;
	else
		offx = (int)mlx->rays[wall.x].wallx % TSIZE;
	wall.y = wall.top - 1;
	while (++wall.y < wall.bot)
		mlx_put_pixel(mlx->img, wall.x, wall.y, get_pixel(mlx, wall, offx));
	wall.y = wall.bot - 1;
	while (++wall.y < W_HEIGHT)
		mlx_put_pixel(mlx->img, wall.x, wall.y, fetch_rgba(mlx->data->frgb));
}

int	get_pixel(t_mlx *mlx, t_wall wall, int offx)
{
	int				offy;
	int				dist_top;
	mlx_texture_t	*tx;

	tx = mlx->texture;
	dist_top = wall.y + (wall.height / 2) - (W_HEIGHT / 2);
	offy = dist_top * ((float)TSIZE / wall.height);
	if (tx == mlx->so || tx == mlx->we)
		offx = TSIZE - 1 - offx;
	return (tx->pixels[(TSIZE * offy + offx) * 4] << 24
		| tx->pixels[(TSIZE * offy + offx) * 4 + 1] << 16
		| tx->pixels[(TSIZE * offy + offx) * 4 + 2] << 8
		| tx->pixels[(TSIZE * offy + offx) * 4 + 3]);
}

mlx_texture_t	*which_texture(t_mlx *mlx, int i)
{
	if (mlx->rays[i].wallvert)
	{
		if (mlx->rays[i].right)
			return (mlx->ea);
		else
			return (mlx->we);
	}
	else
	{
		if (mlx->rays[i].down)
			return (mlx->so);
		else
			return (mlx->no);
	}
}
