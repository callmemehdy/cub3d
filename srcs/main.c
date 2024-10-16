/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:32:54 by mel-akar          #+#    #+#             */
/*   Updated: 2024/10/16 15:31:39 by mel-akar         ###   ########.fr       */
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
	printf("Error\n");
	message && (printf("%s\n", message));
	exit(ex_stt);
}

int	main(int ac, char **av)
{
	t_data	*data;

	// have to delete the testing rule in makefile
	if (ac != 2)
		ft_error(ARG_ERR, ARG_STT);
	data = load_and_parse(av[0], av[1]);
	ft_free_all();
	(void)data;
	(void)av;
	return (0);
}
