/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:35:32 by ael-amma          #+#    #+#             */
/*   Updated: 2024/12/18 17:57:26 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_rdata	**get_rdata(void)
{
	static t_rdata	*data;

	return (&data);
}

void	*salloc(void *ptr)
{
	if (!ptr)
	{
		ft_free_all();
		perror("Error");
		exit(1);
	}
	return (ptr);
}

void	free_rdata(t_rdata *data)
{
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	free(data->mlx);
}
