/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:38:20 by mel-akar          #+#    #+#             */
/*   Updated: 2024/12/31 15:50:02 by mel-akar         ###   ########.fr       */
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

// resolution

# define W_WIDTH 2000
# define W_HEIGHT 1000

// RAYCASTING DIRECTIVES

// DIRECTION ANGLES
# define N PI / 2
# define S (3 * PI) / 2
# define E PI
# define W 2 * PI	
# define ROTA 0.04
# define FACT  2

# define FOV 60 // player field of view
# define T_SIZE (30 * FACT) // tile size
# define PI 3.14159265 //
# define P_SPEED  3 // movement speed of the player
# define RAYS_NUM W_WIDTH


// typedefing
typedef struct s_data t_data;

typedef	enum e_r_l // enum for right or left directions
{
	RIGHT,
	LEFT
}		t_r_l;

typedef	enum e_u_d // enum for up or down directions
{
	UP,
	DOWN
}		t_u_d;

typedef struct		s_player
{
	int			p_x; // x coordinate of the player
	int			p_y; // y coordinate of the player
	double		p_angle; // player angle 
	double		fov; // field of view in radian
	t_data		*data; // data matrice
	mlx_image_t	*img; // img pointer
}					t_player;

typedef	struct		s_ray
{
	double		r_angle; // ray angle which depends on the the player angle and the fov
	double		r_distance; // its distance from the player cors to the wall hit cors
	int			w_hitx;	    // wall intersection x coor
	int			w_hity;		// wall intersection y coor
	t_r_l		is_up;	// ray direction: right or left 
	t_u_d		is_right;	// ray direction: up or down
}					t_ray;



// parse shit

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

struct s_data
{
	char			*title;
	int				map_fd;
	t_line			*lines;
	// boolean map things
	char			**map;
	int				x;			// map width
	int				y;			// map height
	int				px;			// player coordinates
	int				py;			// player coordinates
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
};

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

// ray casting
void	game(void);

/*
	Key Components of Active Learning Strategies
	At the heart of active learning are three fundamental components: Engagement,
	Reflection, and Application. Learners actively engage with the material,
	reflect on the content’s relevance and meaning,
	and apply what they’ve learned in practical, often collaborative, situations.
	Here’s how those three components work in more detail:
	-Engagement: This aspect describes a mix of concentration and interest.
	Students focus on the topic in hand because it is taught in a manner that makes it intrinsically interesting.
	-Reflection: Students are asked to consciously reflect on the subjects they have been learning.
	This helps personalise and imprint the knowledge, and the repetition of key points helps fix them in memory.
	-Application: This aspect focuses on the practical use of key pieces of learning. By making the topic practical,
	students learn how useful the subject can be, motivating them to remember and focus.
	Another key element of active learning is that it’s frequently collaborative.
	Not only do learners benefit from interaction with the educator, but they join forces in team exercises,
	or share their opinions and experiences in group discussion.
*/


#endif