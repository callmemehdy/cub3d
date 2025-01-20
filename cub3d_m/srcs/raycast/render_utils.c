/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:23:35 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/19 18:20:08 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	i = (int)(player->y / TSIZE_SCALE) - 7 + index;
	j = (int)(player->x / TSIZE_SCALE) - 7;
	if (i >= 0 && i < data->y)
	{
		s = ft_malloc(sizeof(char) * 16);
		tmp = s;
		while (j <= (int)(player->x / TSIZE_SCALE + 7))
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

int	get_pixel(t_mlx *mlx, t_wall wall, int x)
{
	// uint32_t		*pixels;
	// pixels = ft_malloc(sizeof(uint32_t) * curr->width * curr->height);
	// for (int i = 0; i < curr->width * curr->height; i++)
	// {
	// 	pixels[i] = (curr->pixels[i * 4] << 24) |
	// 				(curr->pixels[i * 4 + 1] << 16) | 
	// 				(curr->pixels[i * 4 + 2] << 8) | 
	// 				(curr->pixels[i * 4 + 3]);
	// }
	// for (int i = 0; i < curr->width * curr->height; i++)
	// {
	// 	if (i % curr->width == 0)
	// 		printf("\n");
	// 	if (pixels[i] == UINT32_MAX)
	// 		printf("### ");
	// 	else
	// 		printf("%3u ", pixels[i]);
	// }
	// printf("\n");
	// exit(1);

	int	y = (int)(wall.y * mlx->texture->height) % mlx->texture->height;
	int	index = y * mlx->texture->width + x;
	uint8_t		*pixels = mlx->texture->pixels;
	uint32_t	pixel = (uint32_t)pixels[index * 4] << 24 |
					(uint32_t)pixels[index * 4 + 1] << 16 |
					(uint32_t)pixels[index * 4 + 2] << 8 |
					(uint32_t)pixels[index * 4 + 3];
	return (pixel);
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
