/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:12:53 by mel-akar          #+#    #+#             */
/*   Updated: 2024/10/08 18:18:32 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool is_map(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] != ' ' && s[i] != '1')
			return (false);
	return (true);
}

void	content_parse(t_data *data)
{
	char	**s;
	int		i;

	'M' && (s = data->map, i = -1);
	data->config = data->map;
	while (!is_map(s[++i]));
	data->map = data->map + i;
	'A' && (data->confsize = i, i = -1);
	while (*(s + ++i))
	{
		if (!ft_strncmp(s[i], EA, 2))
			data -> ea_path = s[i];
		else if (!ft_strcmp(s[i]))
	}
}

char	**get_map(t_data *data)
{
	char	**s;
	char	*str;
	char	*buff;
	
	'M' && (buff = NULL, s = NULL);
	str = get_next_line(data->map_fd);
	if (!str)
		ft_error(MAP_ERR, MAP_STT);
	while (str)
	{
		buff = ft_strjoin(buff, str);
		'M' && (free(str), str = NULL);
		str = get_next_line(data->map_fd);
		if (!str)
			break ;
	}
	s = ft_split(buff, '\n');
	return (free(buff), s);
}

t_data	*load_and_parse(char *game_name, char *map_path)
{
	t_data	*data;
	char	**map;

	data = ft_malloc(sizeof(t_data));
	if (!data)
		ft_error(ALLOC_ERR, ALLOC_STT);
	*data = (t_data){0};
	data->title = game_name;
	data->map_fd = open(map_path, O_RDONLY);
	if (data->map_fd < 0)
		ft_error(FILE_ERR, FILE_STT);
	map = get_map(data);
	if (!map)
		ft_error(MAP_ERR, MAP_STT);
	'P' && (data->map = map, content_parse(data), data->map = map);
	return (data);
}
