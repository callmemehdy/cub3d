/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:12:53 by mel-akar          #+#    #+#             */
/*   Updated: 2024/10/16 17:06:10 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static
bool	info_validity(t_data *data, t_check *c)
{
	int		boolean;
	char	*s;
	int		i;

	'H' && (s = data -> c_path, i = 0x0);
	boolean = c->c_c ^ 1 + c->ea_c ^ 1 + c->no_c ^ 1;
	boolean += c->so_c ^ 1 + c->we_c ^ 1 + c->f_c ^ 1;
	while (*(s + i))
	{
		if (ft_isdigit(s[i]) && ++c->fields)
			while (ft_isdigit(s[i]))
				i++;
		else
			i++;
	}
	'H' && (s = data -> f_path, i = 0x0);
	while (*(s + i))
	{
		if (ft_isdigit(s[i]) && ++c->fields)
			while (ft_isdigit(s[i]))
				i++;
		else
			i++;
	}
	return (boolean == 0x0 && c->fields == 0x6);
}

static
void	check_line(t_data *data, char *line, t_check *c)
{
	char	*parsed;

	parsed = skip(line);
	if (!ft_strncmp(parsed, EA, 2) && ++c->ea_c)
		data->ea_path = line2path(line);
	else if (!ft_strncmp(parsed, WE, 2) && ++c->we_c)
		data->we_path = line2path(line);
	else if (!ft_strncmp(parsed, SO, 2) && ++c->so_c)
		data->so_path = line2path(line);
	else if (!ft_strncmp(parsed, NO, 2) && ++c->no_c)
		data->no_path = line2path(line);
	else if (!ft_strncmp(parsed, F, 1) && ++c->f_c)
	{
		data -> f_path = line2path(line);
		data -> frgb = rgbshifter(parsed, 3);
	}
	else if (!ft_strncmp(parsed, C, 1) && ++c->c_c)
	{
		data -> c_path = line2path(line);
		data -> crgb = rgbshifter(parsed, 3);
	}
	else
		ft_error(MAP_ERR, MAP_STT);
}

static
void	content_parse(t_data *data)
{
	char		**s;
	int			i;
	t_check		c;

	c = (t_check){0};
	'M' && (s = data -> config, i = -1);
	while (*(s + ++i) && i < data -> confsize)
		check_line(data, s[i], &c);
	if (!info_validity(data, &c))
		ft_error(MAP_ERR, MAP_STT);
	if (!bool_map(data))
		ft_error(MAP_ERR, MAP_STT);
	// will check the bool map 
}

static
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
		line2list(&data->lines, str);
		'M' && (free(str), str = NULL);
		str = get_next_line(data->map_fd);
		if (!str)
			break ;
	}
	s = ft_split(buff, '\n');
	if (!ft_preprocess(data->lines))
		ft_error(MAP_ERR, MAP_STT);
	'L' && (free_lines(data->lines), data->lines = 0);
	return (free(buff), close(data->map_fd), s);
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
	data->map = map;
	slicemap(data);
	content_parse(data);
	return (data);
}
