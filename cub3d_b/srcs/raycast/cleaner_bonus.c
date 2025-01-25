/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:35:32 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/25 17:17:09 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	*salloc(void *ptr)
{
	if (!ptr)
		ft_exit(*get_mlx(), EXIT_FAILURE);
	return (ptr);
}

void	ft_exit(t_mlx *mlx, int exit_stat)
{
	if (mlx->no)
		mlx_delete_texture(mlx->no);
	if (mlx->so)
		mlx_delete_texture(mlx->so);
	if (mlx->ea)
		mlx_delete_texture(mlx->ea);
	if (mlx->we)
		mlx_delete_texture(mlx->we);
	clean_frames();
	mlx_delete_image(mlx->mlxi, mlx->img);
	mlx_close_window(mlx->mlxi);
	mlx_terminate(mlx->mlxi);
	if (exit_stat)
		ft_error(NULL, exit_stat);
	ft_free_all();
	exit(exit_stat);
}
