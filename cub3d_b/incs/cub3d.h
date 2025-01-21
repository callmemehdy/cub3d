/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:38:20 by mel-akar          #+#    #+#             */
/*   Updated: 2025/01/21 21:57:16 by mel-akar         ###   ########.fr       */
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
# include <errno.h>
# include <string.h>

# define SPRITE_H 300
# define SPRITE_W 288

typedef struct s_frames
{
	mlx_texture_t	*gun_txt[5];
	mlx_image_t		*gun[5];
}			t_frames;

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
# define PI M_PI //

// enumslike string
# define EA "EA"
# define WE "WE"
# define SO "SO"
# define NO "NO"
# define F	"F"
# define C	"C"

/*********raycast*********/

//	Field of view
# define FOV (60 * ( M_PI / 180))

//	Size of tiles
# define TSIZE	32

//	Minimap Scale Factor
# define SCALE 1

//	Size of tiles multiplied by the scale factor
# define TSIZE_SCALE (int)(TSIZE * SCALE)

//	Two PI
# define T_PI (M_PI * 2)

//	Window width
# define W_WIDTH 1920	// 2048

//	Window Height
# define W_HEIGHT 1056	//	1280

//	Width of the ray
# define NUM_RAYS W_WIDTH

//	Frame Per Second
# define FPS 60

//	Frame Time Length in ms
# define FTL (1000 / FPS)

// typedefing
typedef struct s_data t_data;
typedef unsigned char	t_byte;

// parse shit

typedef struct s_addr
{
	void			*addr;
	struct s_addr	*next;
}				t_addr;

typedef struct s_linegnl
{
	char				*s;
	struct s_linegnl	*next;
}				t_linegnl;

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
	t_linegnl		*lines;
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

/*********raycast*********/

typedef struct s_player t_player;
typedef struct s_ray	t_ray;

typedef struct s_mlx
{
	mlx_t			*mlxi;
	mlx_image_t		*img;
	mlx_image_t		*bg;
	mlx_image_t		*frame;
	t_player		*player;
	t_data			*data;
	t_ray			*rays;
	int				width;
	int				height;
	int				lastframe;
}				t_mlx;

struct s_player
{
	float	x;
	float	y;
	int		radius;
	int		turndir;
	int		walkdir;
	int		strafe;
	float	angle;
	float	walksp;
	float	turnsp;
};

typedef struct	s_rect
{
	int			x;
	int			y;
	int 		width;
	int 		height;
	int			color;
	t_player	player;
}				t_rect;

typedef struct	s_circle
{
	int	cx;
	int	cy;
	int	radius;
	int	color;
}				t_circle;

typedef struct	s_line
{
	float	x0;
	float	y0;
	float	x1;
	float	y1;
	int		dx;
	int		dy;
}				t_line;

struct	s_ray
{
	float	angle;
	float	wallx;
	float	wally;
	float	dist;
	bool	wallvert;
	bool	down;
	bool	right;
	int		wallcontent;
};

typedef struct	s_raydata
{
	float	fx;
	float	fy;
	float	dx;
	float	dy;
	float	nextx;
	float	nexty;
	bool	down;
	bool	right;
}				t_rdata;

typedef struct	s_raydif
{
	float	horzx;
	float	horzy;
	float	vertx;
	float	verty;
	float	angle;
	int		horzcont;
	int		vertcont;
	bool	horzflag;
	bool	vertflag;
}				t_rdif;

typedef struct	s_wall
{
	int		x;
	int		y;
	int		height;
	int		top;
	int		bot;
	int		color;
}				t_wall;

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
void			line2list(t_linegnl **list, char *s);
bool			onlynl(char *s);
char			*skip(char *s);
char			*revskip(char *s);
bool			_edgelines(char *s);
void			free_lines(t_linegnl *lines);
bool			ft_preprocess(t_linegnl *lines);
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
bool			outtabound(int y, int x);
bool			is_map_first(char *s);

// global struct
t_data	**get_data(void);
t_mlx	**get_mlx(void);

/*********raycast*********/

//	cleaner.c
void	*salloc(void *ptr, bool mlx);
void	ft_mlxerror(void);
void	ft_exit(t_mlx *mlx);

//	draw.c
void	drawrect(mlx_image_t *img, t_rect tile);
void	drawcircle(t_mlx *mlx, t_circle circle);
void	drawline(t_mlx *mlx, t_line line, uint32_t color);

//	game.c
void	game(void);

//	hooks.c
void	key_press(mlx_key_data_t keydata, void *vmlx);

//	raycast.c
void	horz_intersect(t_mlx *m, t_player *p, t_rdata *data, t_rdif *dif);
void	vert_intersect(t_mlx *m, t_player *p, t_rdata *data, t_rdif *dif);
void	load_rays(t_mlx *mlx, t_player *p, t_rdif dif, int id);

//	render_utils.c
char	**map_mask(t_data *data, t_player *player);
char	*fill_line(char *s, t_data *data, t_player *player, int index);

//	render.c
void	render(t_mlx *mlx);
void	render_map(t_mlx *mlx);

//	setup.c
void	setup(t_mlx *mlx, t_data *data);

//	update.c
void	update(t_mlx *mlx);

//	utils.c
int		get_rgba(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
int		rgbtoa(uint32_t rgb);
bool	wallhit(float x, float y);
float	norm_angle(float angle);
float	linelen(float x1, float y1, float x2, float y2);

#endif