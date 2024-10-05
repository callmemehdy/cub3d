/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:32:54 by mel-akar          #+#    #+#             */
/*   Updated: 2024/10/05 10:12:14 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *message, int ex_stt)
{
	ft_free_all();
	message && (printf("%s\n", message));
	exit(ex_stt);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
		ft_error(ARG_ERR, ARG_EX_STT);
	return (0);
}
