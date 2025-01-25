/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:38:20 by mel-akar          #+#    #+#             */
/*   Updated: 2025/01/24 22:07:04 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <limits.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include <ctype.h>
# include "get_next_line_bonus.h"
# include <MLX42.h>
# include <errno.h>
# include <string.h>
# include <strings.h>

# define SPRITE_H 720
# define SPRITE_W 960

# define FRM_NO 50

typedef struct s_frame
{
	mlx_texture_t	*gun_txt[50];
	mlx_image_t		*gun[50];
}			t_frame;

// cli arguments error
# define ARG_ERR "invalid program input\nUsage: ./cub3d_bonus [map's path]"
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
# define FOV 60

//	Size of tiles
# define TSIZE	64

//	Minimap Scale Factor
# define SCALE 0.5

//	Size of tiles multiplied by the scale factor
# define TSIZE_SCALE (int)(TSIZE * SCALE)

//	Window width
# define W_WIDTH 1920

//	Window Height
# define W_HEIGHT 1056

//	Width of the ray
# define NUM_RAYS W_WIDTH

//	Frame Per Second
# define FPS 60

// typedefing
/*
	Description:	Information collected from parsing part.
	title:			Title of the window.
	map_fd:			Map file descriptor.
	line:			Lines from map file.
	map:			Map in two dimensional array.
	x:				Map width.
	y:				Map height.
	px:				Player x.
	py:				Player y.
	config:			Config part of the map file.
	confsize:		-
	no_path:		Path of the north texture file.
	so_path:		Path of the south texture file.
	ea_path:		Path of the east texture file.
	we_path:		Path of the west texture file.
	c_path:			-
	f_path:			-
	frgb:			Floor color in BGR format.
	crgb:			Ceiling color in BGR format.
*/
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
	char			**map;
	int				x;
	int				y;
	int				px;
	int				py;
	char			**config;
	int				confsize;
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
	mlx_texture_t	*frame;
	mlx_texture_t	*aim;
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	mlx_texture_t	*cdoor;
	mlx_texture_t	*odoor;
	mlx_texture_t	*texture;
	t_frame			frames;
	t_player		*player;
	t_data			*data;
	t_ray			*rays;
	uint8_t			*pixels;
	int				width;
	int				height;
	int				lastframe;
	bool			space;
	bool			key;
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
t_data			**get_data(void);
t_mlx			**get_mlx(void);

/*********raycast*********/

//	cleaner_bonus.c
void			*salloc(void *ptr);
void			ft_exit(t_mlx *mlx, int exit_stat);

//	draw_bonus.c
void			drawrect(mlx_image_t *img, t_rect tile);
void			drawcircle(t_mlx *mlx, t_circle circle);

//	game_bonus.c
void			game(void);

//	hooks_bonus.c
void			key_press(mlx_key_data_t keydata, void *vmlx);

//	raycast_bonus.c
void			horz_intersect(t_mlx *m, t_player *p, t_rdata *data, t_rdif *dif);
void			vert_intersect(t_mlx *m, t_player *p, t_rdata *data, t_rdif *dif);
void			load_rays(t_mlx *mlx, t_player *p, t_rdif dif, int id);

//	render_utils_bonus.c
char			**map_mask(t_data *data, t_player *player);
char			*fill_line(char *s, t_data *data, t_player *player, int index);
void			paint_wall(t_mlx *mlx, t_wall wall);
int				get_pixel(t_mlx *mlx, t_wall wall, int offx);
mlx_texture_t	*which_texture(t_mlx *mlx, int i);

// render_tools_bonus.c
void			ft_usleep(long milliseconds);
long			get_time(void);
void			free_2d(char **matrix);
char			*ft_itoa(int n);

//	render_utils.c
void			render(t_mlx *mlx);

//	setup_utils.c
void			setup(t_mlx *mlx, t_data *data);

//	update_utils.c
void			update(t_mlx *mlx);

//	utils_utils.c
int				get_rgba(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
int				fetch_rgba(uint32_t rgb);
bool			wallhit(float x, float y);
float			norm_angle(float angle);
float			linelen(float x1, float y1, float x2, float y2);

// sprite_bonus.c
t_frame			load_frames();
void			overlay_images(mlx_image_t *base, mlx_texture_t *overlay, int x_off, int y_off);


#endif