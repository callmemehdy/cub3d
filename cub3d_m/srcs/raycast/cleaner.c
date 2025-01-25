/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:35:32 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/24 22:05:37 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*salloc(void *ptr)
{
	if (!ptr)
		ft_exit(*get_mlx(), EXIT_FAILURE);
	return (ptr);
}

void	ft_exit(t_mlx *mlx, int	exit_stat)
{
	mlx_delete_image(mlx->mlxi, mlx->img);
	mlx_close_window(mlx->mlxi);
	mlx_terminate(mlx->mlxi);
	if (exit_stat)
		ft_error(NULL, exit_stat);
	ft_free_all();
	exit(EXIT_SUCCESS);
}
