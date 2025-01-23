/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tools_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:42:25 by mel-akar          #+#    #+#             */
/*   Updated: 2025/01/22 23:01:34 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

void	free_2d(char **matrix)
{
	int		len;

	len = 0;
	if (matrix)
	{
		while (matrix[len])
			ft_free(matrix[len++]);
		ft_free(matrix);
	}
}

long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (1337);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long milliseconds)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(500);
}

static
char	*ft_join(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (free(s1), s1 = NULL, NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[ft_strlen(s1) + ft_strlen(s2)] = 0;
	return (str);
}

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
