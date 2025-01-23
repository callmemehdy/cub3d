/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:28:21 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/23 22:31:46 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_frame	load_frames()
{
	t_mlx		*mlx;
	char 		*num;
	char 		*name;
	char 		*path;
	int			i;
	char		*prefix;

	i = -1;
	mlx = *get_mlx();
	prefix = strdup("textures/dwn/");
	while (++i < FRM_NO)
	{
		num = ft_itoa(i + 1);
		name = ft_join(num, ".png");
		path = ft_join(prefix, name);
		mlx->frames.gun_txt[i] = mlx_load_png(path);
		// gotta protect & make some cleaner function to get rid of this garbage pngs
		free(num);
		free(path);
		free(name);
	}
	free(prefix);
	return (mlx->frames);
}

void	overlay_images(mlx_image_t *base, mlx_texture_t *overlay, int x_off, int y_off)
{
	uint32_t	*base_pixels;
	uint32_t	*overlay_pixels;
	int			cxp[2];
	int			base_index;
	int			overlay_index;

	1 && (cxp[0] = 0, base_pixels = (uint32_t*)base->pixels);
	overlay_pixels = (uint32_t*)overlay->pixels;
	while (cxp[0] < overlay->height)
	{
		cxp[1] = 0;
		while (cxp[1] < overlay->width)
		{
			base_index = (cxp[0] + y_off) * base->width + (cxp[1] + x_off);
			overlay_index = cxp[0] * overlay->width + cxp[1];
			if (!((overlay_pixels[overlay_index] >> 24) & 0xFF) && ++cxp[1])
				continue;
			base_pixels[base_index] = overlay_pixels[overlay_index];
			++cxp[1];
		}
		++cxp[0];
	}
}
