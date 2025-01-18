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

/*
	◦ The map must be closed/surrounded by walls, if not the program must return
	an error.
	◦ Except for the map content, each type of element can be separated by one or
	more empty line(s).
	◦ Except for the map content which always has to be the last, each type of
	element can be set in any order in the file.
	◦ Except for the map, each type of information from an element can be separated
	by one or more space(s).
	◦ The map must be parsed as it looks in the file. Spaces are a valid part of the
	map and are up to you to handle. You must be able to parse any kind of map,
	as long as it respects the rules of the map.
	mehdy's notes:
			> check until i found a line that contains only spaces and ones or EOF
			> check the line's boundaries and check the zero's , player's ups 
			  and downs and rights, lefts. check the number of the players
			  if its more than 1 error if zero leads to a space error if 
			  the player can go to a space error ,,, etc
			> check for an outsider string with the config ,,,
			> rgb values must be seperated by commas
*/

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
	// gotta parse the file extension
	if (ac != 2 || !_extension(av[1]))
		ft_error(ARG_ERR, ARG_STT);
	load_and_parse(av[0], av[1]);
	game();
	ft_free_all();
	return (0);
}
