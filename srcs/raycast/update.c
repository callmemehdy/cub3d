/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:18:57 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/16 15:12:00 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_player(t_mlx *mlx, t_player *p);
static void	raycasting(t_player *p);
static void	castray(t_player *p, float angle, int id);

void	update(t_mlx *mlx)
{
	move_player(mlx, mlx->player);
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
	if (!wallhit(newpx, p->y))
		p->x = newpx;
	if (!wallhit(p->x, newpy))
		p->y = newpy;
}

static void	raycasting(t_player *p)
{
	int		id;
	float	ray_angle;

	id = -1;
	ray_angle = p->angle - (FOV / 2);
	while (++id < NUM_RAYS)
	{
		castray(p, ray_angle, id);
		ray_angle += FOV / NUM_RAYS;
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
