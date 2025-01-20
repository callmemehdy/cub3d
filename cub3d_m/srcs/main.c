/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:32:54 by mel-akar          #+#    #+#             */
/*   Updated: 2025/01/17 23:18:44 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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

int	main(int ac, char **av)
{
	if (ac != 2 || !_extension(av[1]))
		ft_error(ARG_ERR, ARG_STT);
	load_and_parse(av[0], av[1]);
	game();
	ft_free_all();
	return (0);
}
