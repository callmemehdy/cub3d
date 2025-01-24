/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:35:32 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/24 19:04:48 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*salloc(void *ptr, bool mlx)
{
	if (!ptr)
	{
		if (mlx)
			ft_mlxerror();
		else
			ft_error(strerror(errno), EXIT_FAILURE);
	}
	return (ptr);
}

void	ft_mlxerror(void)
{
	char	*str;

	str = (char *)mlx_strerror(mlx_errno);
	while (str)
	{
		write(2, &str, 1);
		str++;
	}
	exit(EXIT_FAILURE);
}

void	ft_exit(t_mlx *mlx)
{
	mlx_delete_image(mlx->mlxi, mlx->img);
	mlx_close_window(mlx->mlxi);
	mlx_terminate(mlx->mlxi);
	ft_free_all();
	exit(EXIT_SUCCESS);
}
