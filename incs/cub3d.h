/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:38:20 by mel-akar          #+#    #+#             */
/*   Updated: 2024/10/05 10:10:42 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define ARG_ERR "invalid program input\nUsage: ./cub3d [map's path]"
# define ARG_EX_STT 42

typedef struct s_addr
{
	void			*addr;
	struct s_addr	*next;
}				t_addr;

// memory management shit ...
void	ft_free(void *add);
void	ft_free_all(void);
void	*ft_malloc(size_t size);
t_addr	**get_list(void);
void	destroy_addr(t_addr *list);
void	delete_node(t_addr **list, void *data);

#endif