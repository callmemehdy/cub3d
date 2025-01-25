/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:13:41 by mel-akar          #+#    #+#             */
/*   Updated: 2025/01/25 02:54:11 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	counter(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count += 1;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	stuffing(char *s, int n, int i)
{
	while (n)
	{
		s[i--] = (n % 10) + 48;
		n /= 10;
	}
}

static char	*strfill(char *s, int n)
{
	int	i;

	i = counter(n);
	s[i] = '\0';
	i--;
	if (n < 0)
	{
		n *= -1;
		s[0] = '-';
		stuffing(s, n, i);
	}
	else if (n > 0)
		stuffing(s, n, i);
	else
		s[i] = 48;
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		min;

	min = -2147483648;
	if (n == min)
		return (ft_strdup("-2147483648"));
	s = malloc(counter(n) + 1);
	if (s == NULL)
		return (NULL);
	s = strfill(s, n);
	return (s);
}

void	clean_frames()
{
	t_mlx	*mlx;
	int		i;

	mlx = *get_mlx();
	i = -1;
	while (++i < FRM_NO)
		mlx_delete_texture(mlx->frames.gun_txt[i]);
	mlx_delete_texture(mlx->frame);
	mlx_delete_texture(mlx->aim);
	mlx_delete_texture(mlx->door);
}
