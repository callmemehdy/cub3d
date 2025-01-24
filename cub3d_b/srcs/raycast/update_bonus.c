/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:18:57 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/24 20:09:31 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	move_player(t_mlx *mlx, t_player *p);
static void	door(t_mlx *mlx, t_player *p);
static void	raycasting(t_player *p);
static void	castray(t_player *p, float angle, int id);

void	update(t_mlx *mlx)
{
	move_player(mlx, mlx->player);
	door(mlx, mlx->player);
	raycasting(mlx->player);
}

static void	move_player(t_mlx *mlx, t_player *p)
{
	float		newpx;
	float		newpy;
	float		speed;
	float		mvstep;

	p->angle += p->turndir * p->turnsp * mlx->mlxi->delta_time;
	speed = p->walksp;
	if (p->walkdir && p->strafe)
		speed /= sqrt(2);
	mvstep = p->walkdir * speed * mlx->mlxi->delta_time;
	newpx = p->x + cos(p->angle) * mvstep;
	newpy = p->y + sin(p->angle) * mvstep;
	mvstep = p->strafe * speed * mlx->mlxi->delta_time;
	newpx += cos(p->angle + M_PI_2) * mvstep;
	newpy += sin(p->angle + M_PI_2) * mvstep;
	if (!wallhit(newpx, newpy))
	{
		p->x = newpx;
		p->y = newpy;
	}
}

static void	door(t_mlx *mlx, t_player *p)
{
	int		dx;
	int		dy;
	int		px;
	int		py;
	int		face;
	int		dist;
	char	content;
	t_data	*data;

	data = mlx->data;
	face = (NUM_RAYS / 2) - 1;
	if (mlx->key)
	{
		px = (int)p->x / TSIZE;
		py = (int)p->y / TSIZE;
		dist = (int)mlx->rays[face].dist / TSIZE;
		if (dist <= 2)
		{
			content = mlx->rays[face].wallcontent;
			if (content == 'D')
			{
				dist++;
				if (mlx->rays[face].wallvert)
				{
					dx = px + (mlx->rays[face].right ? dist : -dist);
					dy = py;
				}
				else
				{
					dy = py + (mlx->rays[face].down ? dist : -dist);
					dx = px;
				}
				// if ((mlx->rays[face].wallvert && px == dx) || (!mlx->rays[face].wallvert && py == dy))
				if ((mlx->rays[face].wallvert && px == dx) ||
					(!mlx->rays[face].wallvert && py == dy))
				{
					printf("here\n");
					if (dx >= 0 && dx < data->x && dy >= 0 && dy < data->y)
						data->map[dy][dx] = 'O';
				}
			}
			else
			{
				dy = -2;
				while (++dy <= 1)
				{
					dx = -2;
					while (++dx <= 1)
					{
						int checkx = px + dx;
						int checky = py + dy;
						if (checkx >= 0 && checkx < data->x && checky >= 0 && checky < data->y)
						{
							// printf("(%d, %d)\n", checkx, checky);
							if (data->map[checky][checkx] == 'O')
							{
								data->map[checky][checkx] = 'D';
								break ;
							}
						}		
					}
				}
			}
			// for (int i = 0; data->map[i]; i++)
			// {
			// 	for (int j = 0; data->map[i][j]; j++)
			// 		printf("%c ", data->map[i][j]);
			// 	printf("\n");
			// }
		}
	}
}
			// {
			// 	int	j = 0;
			// 	int	facingx;
			// 	int facingy;
			// 	if (!mlx->rays[face].down)
			// 	{
			// 		facingx = 0;
			// 		facingy = -1;
			// 	}
			// 	else if (mlx->rays[face].down)
			// 	{
			// 		facingx = 0;
			// 		facingy = 1;
			// 	}
			// 	else if (!mlx->rays[face].right)
			// 	{
			// 		facingx = -1;
			// 		facingy = 0;
			// 	}
			// 	else if (mlx->rays[face].right)
			// 	{
			// 		facingx = 1;
			// 		facingy = 0;
			// 	}
			// 	while (++j <= 2)
			// 	{
			// 		int	check_x = px + facingx * j;
			// 		int check_y = py + facingy * j;
			// 		if (check_x >= 0 && check_x < data->x && check_y >= 0 && check_y < data->y)
			// 		{
			// 			if (data->map[check_y][check_x] == 'O')
			// 				data->map[check_y][check_x] = 'D';
			// 		}
			// 		else
			// 			break ;
			// 	}
			// }
				// printf("(%d, %d)\t(%d, %d)\n", px, py, dx, dy);	
				// printf("%c\n", data->map[dy][dx]);
				// printf("(%d, %d)\t(%d, %d)\n", ((int)p->x / TSIZE), ((int)p->y / TSIZE), dx, dy);
				// printf("%c\n", data->map[dy][dx]);
				// data->map[dx][dy] = 'O';
				// printf("%d\n", dist);
		// if (data->map[py + 1][px] == 'D')
		// 	data->map[py + 1][px] = 'O';
		// else if (data->map[py - 1][px] == 'D')
		// 	data->map[py - 1][px] = 'O';
		// else if (data->map[py][px + 1] == 'D')
		// 	data->map[py][px + 1] = 'O';
		// else if (data->map[py][px - 1] == 'D')
		// 	data->map[py][px - 1] = 'O';
		// else if (data->map[py + 1][px] == 'O')
		// 	data->map[py + 1][px] = 'D';
		// else if (data->map[py - 1][px] == 'O')
		// 	data->map[py - 1][px] = 'D';
		// else if (data->map[py][px + 1] == 'O')
		// 	data->map[py][px + 1] = 'D';
		// else if (data->map[py][px - 1] == 'O')
		// 	data->map[py][px - 1] = 'D';

static void	raycasting(t_player *p)
{
	int		id;
	float	ray_angle;

	id = -1;
	ray_angle = p->angle - ((FOV * (M_PI / 180)) / 2);
	while (++id < NUM_RAYS)
	{
		castray(p, ray_angle, id);
		ray_angle += (FOV * (M_PI / 180)) / NUM_RAYS;
	}
}

static void	castray(t_player *p, float angle, int id)
{
	t_mlx	*mlx;
	t_rdif	dif;
	t_rdata	data;

	angle = norm_angle(angle);
	data.down = (angle > 0 && angle < M_PI);
	data.right = (angle < M_PI_2 || angle > M_PI * 1.5);
	dif.angle = angle;
	mlx = *get_mlx();
	horz_intersect(mlx, p, &data, &dif);
	vert_intersect(mlx, p, &data, &dif);
	load_rays(mlx, p, dif, id);
	mlx->rays[id].angle = angle;
	mlx->rays[id].down = data.down;
	mlx->rays[id].right = data.right;
}
