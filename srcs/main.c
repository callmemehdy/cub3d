/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:32:54 by mel-akar          #+#    #+#             */
/*   Updated: 2024/10/05 14:17:27 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *message, int ex_stt)
{
	ft_free_all();
	printf("Error\n");
	message && (printf("%s\n", message));
	exit(ex_stt);
}

t_data	*parse_map(char *game_name, char *map_path)
{
	t_data	*data;

	data = ft_malloc(sizeof(t_data));
	if (!data)
		ft_error(ALLOC_ERR, ALLOC_STT);
	data->title = game_name;
	data->map_fd = open(map_path, O_RDONLY);
	if (data->map_fd < 0)
		ft_error(FILE_ERR, FILE_STT);
	return (data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		ft_error(ARG_ERR, ARG_STT);
	data = parse_map(av[0], av[1]);
	return (0);
}
