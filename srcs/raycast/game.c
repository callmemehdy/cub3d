/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:35:24 by ael-amma          #+#    #+#             */
/*   Updated: 2024/12/24 18:38:39 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game(void)
{
	setup();
	render_minimap();
	printf("%f\n", M_PI);
	mlx_image_to_window((*get_rdata())->mlx, (*get_rdata())->img, 0, 0);
	mlx_loop((*get_rdata())->mlx);
}
