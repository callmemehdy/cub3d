/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tools_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:42:25 by mel-akar          #+#    #+#             */
/*   Updated: 2025/01/25 17:37:21 by mel-akar         ###   ########.fr       */
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

void	switch_door_state(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'D')
		data->map[y][x] = 'O';
	else if (data->map[y][x] == 'O')
		data->map[y][x] = 'D';
}
