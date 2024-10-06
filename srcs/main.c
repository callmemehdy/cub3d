/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:32:54 by mel-akar          #+#    #+#             */
/*   Updated: 2024/10/06 20:57:56 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
*/

void	ft_error(char *message, int ex_stt)
{
	ft_free_all();
	printf("Error\n");
	message && (printf("%s\n", message));
	exit(ex_stt);
}

char	**get_map(t_data *data)
{
	// char	**s;
	char	*str;
	char	*buff;
	
	'M' && (buff = NULL);
	str = get_next_line(data->map_fd);
	if (!str)
		ft_error(MAP_ERR, MAP_STT);
	while (str)
	{
		buff = ft_strjoin(buff, str);
		str = get_next_line(data->map_fd);
		if (!str)
		{
			ft_free(str);
			break ;
		}
	}
	printf("%s\n", buff);
	return (char **)1337;
}

t_data	*parse_map(char *game_name, char *map_path)
{
	t_data	*data;
	char	**map;

	data = ft_malloc(sizeof(t_data));
	if (!data)
		ft_error(ALLOC_ERR, ALLOC_STT);
	data->title = game_name;
	data->map_fd = open(map_path, O_RDONLY);
	if (data->map_fd < 0)
		ft_error(FILE_ERR, FILE_STT);
	map = get_map(data);
	if (!map)
		ft_error(MAP_ERR, MAP_STT);
	return (data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		ft_error(ARG_ERR, ARG_STT);
	data = parse_map(av[0], av[1]);
	(void)data;
	return (0);
}
