/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:38:20 by mel-akar          #+#    #+#             */
/*   Updated: 2024/12/11 14:48:12 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include <ctype.h>
# include "get_next_line.h"
# include <MLX42.h>

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
# define MAP_STT 1

// enumslike string
# define EA "EA"
# define WE "WE"
# define SO "SO"
# define NO "NO"
# define F	"F"
# define C	"C"

typedef unsigned char	t_byte;

// # define __

typedef struct s_addr
{
	void			*addr;
	struct s_addr	*next;
}				t_addr;

typedef struct s_line
{
	char			*s;
	struct s_line	*next;
}				t_line;

// memory management shit ...
void			ft_free(void *add);
void			ft_free_all(void);
void			*ft_malloc(size_t size);
t_addr			**get_list(void);
void			destroy_addr(t_addr *list);
void			delete_node(t_addr **list, void *data);

// file handling shit ...
char			*get_next_line(int fd);

// cubeThings

typedef struct s_data
{
	char			*title;
	int				map_fd;
	t_line			*lines;
	// boolean map things
	char			**map;
	int				x;			// map width
	int				y;			// map height
	// 1st half of the map
	char			**config;
	int				confsize;
	// textures , colors things	
	char			*no_path;
	char			*so_path;
	char			*ea_path;
	char			*we_path;
	char			*c_path;
	char			*f_path;
	unsigned int	frgb;
	unsigned int	crgb;
}					t_data;

typedef struct s_check
{
	int			ea_c;
	int			we_c;
	int			so_c;
	int			no_c;
	int			f_c;
	int			c_c;
	int			fields;
}				t_check;

// some useful utils
char			**ft_split(char const *str, char c);
void			ft_bzero(void *buffer, size_t n);
char			*ft_strdup(char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_error(char *message, int ex_stt);
bool			ft_isdigit(char c);
bool			ft_isspace(char c);
// size_t	ft_strlen(char *s);
// map parsing utils too
char			*line2path(char *s);
void			line2list(t_line **list, char *s);
bool			onlynl(char *s);
char			*skip(char *s);
char			*revskip(char *s);
bool			_edgelines(char *s);
void			free_lines(t_line *lines);
bool			ft_preprocess(t_line *lines);
t_byte			atob(char *s);

unsigned int	rgbshifter(char *s, int level);
t_data			*load_and_parse(char *game_name, char *map_path);
void			slicemap(t_data *data);
bool			is_map(char *s);
bool			bool_map(t_data *data);
bool			is_safe(char c, int i, int j);
bool			is_player(char c);
bool			outsiders(char c);
bool			check_char(char **map, int *pl, int i, int j);

// global struct
t_data			**get_data(void);

#endif