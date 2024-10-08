/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:38:20 by mel-akar          #+#    #+#             */
/*   Updated: 2024/10/08 22:30:23 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include "get_next_line.h"

// cli arguments error
# define ARG_ERR "invalid program input\nUsage: ./cub3d [map's path]"
# define ARG_STT 42

// heap allocation errors
# define ALLOC_ERR "memory allocation problem occured\nmalloc function failed"
# define ALLOC_STT 37

// file handling errors
# define FILE_ERR "invalid file descriptor\nopen function failed"
# define FILE_STT 21

// map content errors
# define MAP_ERR "invalid map content"
# define MAP_STT 255

// enumslike string
# define EA "EA"
# define WE "WE"
# define SO "SO"
# define NO "NO"

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

// file handling shit ...
char	*get_next_line(int fd);

// cubeThings

typedef	struct		s_data
{
	char			*title;
	// boolean map things
	int				map_fd;
	char			**map;
	// textures , colors things	
	char			**config;
	size_t			confsize;
	char			*no_path;
	char			*so_path;
	char			*ea_path;
	char			*we_path;
	unsigned int	frgb;
	unsigned int	crgb;
}					t_data;

// some useful utils
char	**ft_split(char const *str, char c);
void	ft_bzero(void *buffer, size_t n);
char	*ft_strdup(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_error(char *message, int ex_stt);
// map parsing bruh 
t_data	*load_and_parse(char *game_name, char *map_path);

#endif