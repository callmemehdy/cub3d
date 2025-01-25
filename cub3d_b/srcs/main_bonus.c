/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:32:54 by mel-akar          #+#    #+#             */
/*   Updated: 2025/01/25 03:11:21 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	_extension(char *s);

int	main(int ac, char **av)
{
	if (ac != 2 || !_extension(av[1]))
		ft_error(ARG_ERR, ARG_STT);
	load_and_parse(av[0], av[1]);
	game();
	return (0);
}

t_data	**get_data(void)
{
	static t_data	*data;

	return (&data);
}

t_mlx	**get_mlx(void)
{
	static t_mlx	*mlx;

	return (&mlx);
}

void	ft_error(char *message, int ex_stt)
{
	ft_free_all();
	(void)write(2, "Error\n", 6);
	if (message)
	{
		(void)write(2, message, ft_strlen(message));
		(void)write(2, "\n", 1);
	}
	exit(ex_stt);
}

static
bool	_extension(char *s)
{
	int		len;

	if (NULL == s)
		return (false);
	len = ft_strlen(s) - 4;
	if (len >= 0 && !ft_strncmp(s + len, ".cub", 4))
		return (true);
	return (false);
}
