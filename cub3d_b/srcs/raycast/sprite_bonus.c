/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:28:21 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/25 17:32:46 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	overlay_images(mlx_image_t *base, mlx_texture_t *overlay, \
						int x_off, int y_off)
{
	uint32_t	*base_pixels;
	uint32_t	*overlay_pixels;
	u_int32_t	cxp[2];
	int			base_index;
	int			overlay_index;

	1 && (cxp[0] = 0, base_pixels = (uint32_t *)base->pixels);
	overlay_pixels = (uint32_t *)overlay->pixels;
	while (cxp[0] < overlay->height)
	{
		cxp[1] = 0;
		while (cxp[1] < overlay->width)
		{
			base_index = (cxp[0] + y_off) * base->width + (cxp[1] + x_off);
			overlay_index = cxp[0] * overlay->width + cxp[1];
			if (!((overlay_pixels[overlay_index] >> 24) & 0xFF) && ++cxp[1])
				continue ;
			base_pixels[base_index] = overlay_pixels[overlay_index];
			++cxp[1];
		}
		++cxp[0];
	}
}

static
char	*ft_join(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = ft_malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	str = ft_malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[ft_strlen(s1) + ft_strlen(s2)] = 0;
	return (str);
}

t_frame	load_frames(void)
{
	int		i;
	t_mlx	*mlx;
	char	*num;
	char	*path;
	char	*prefix;

	i = -1;
	mlx = *get_mlx();
	prefix = ft_strdup("textures/dwn/");
	while (++i < FRM_NO)
	{
		num = salloc(ft_itoa(i + 1));
		path = salloc(ft_join(prefix, salloc(ft_join(num, ".png"))));
		mlx->frames.gun_txt[i] = salloc(mlx_load_png(path));
		ft_free(num);
		ft_free(path);
	}
	ft_free(prefix);
	return (mlx->frames);
}
