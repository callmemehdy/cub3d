/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:12:53 by mel-akar          #+#    #+#             */
/*   Updated: 2024/10/10 10:28:44 by mel-akar         ###   ########.fr       */
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

bool	half1_validity(t_data *data)
{
	bool boolean;

	boolean = data->no_path && data->so_path &&
			  data->we_path && data->ea_path;
	return (boolean);
}

void	content_parse(t_data *data)
{
	t_check		c;
	char		**s;
	int			i;

	'M' && (s = data -> map, i = -1);
	data -> config = data -> map;
	while (!is_map(s[++i]));
	data -> map = data -> map + i;
	'A' && (data -> confsize = i, i = -1);
	c = (t_check){0};
	while (*(s + ++i) && i < data -> confsize)
	{
		if (!ft_strncmp(skip(s[i]), EA, 2) && ++c.ea_c)
			 data -> ea_path = line2path(s[i]);
		else if (!ft_strncmp(skip(s[i]), WE, 2) && ++c.we_c)
			data -> we_path = line2path(s[i]);
		else if (!ft_strncmp(skip(s[i]), SO, 2) && ++c.so_c)
			data -> so_path = line2path(s[i]);
		else if (!ft_strncmp(skip(s[i]), NO, 2) && ++c.no_c)
			data -> no_path = line2path(s[i]);
		else if (!ft_strncmp(skip(s[i]), F, 1) && ++c.f_c)
			data -> frgb = rgbshifter(skip(s[i]), 3);
		else if (!ft_strncmp(skip(s[i]), C, 1) && ++c.c_c)
			data -> crgb = rgbshifter(skip(s[i]), 3);
	}
	printf("ceiling count==>[%d]\n", c.c_c);
	printf("floor count==>\t[%d]\n", c.f_c);
	printf("east count==>\t[%d]\n", c.ea_c);
	printf("west count==>\t[%d]\n", c.we_c);
	printf("south count==>\t[%d]\n", c.so_c);
	printf("north count==>\t[%d]\n", c.no_c);
	// if (!half1_validity(data))
	// 	ft_error(MAP_ERR, MAP_STT);
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
	return (free(buff), close(data->map_fd),s);
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
