/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amma <ael-amma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:36:15 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/19 11:23:25 by ael-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	vertloop(t_mlx *m, t_rdata *data, t_rdif *dif);
static bool	horzloop(t_mlx *m, t_rdata *data, t_rdif *dif);

void	horz_intersect(t_mlx *m, t_player *p, t_rdata *data, t_rdif *dif)
{
	dif->horzx = 0;
	dif->horzy = 0;
	dif->horzcont = 0;
	dif->horzflag = false;
	data->fy = floor(p->y / TSIZE) * TSIZE;
	if (data->down)
		data->fy += TSIZE;
	data->fx = p->x + (data->fy - p->y) / tan(dif->angle);
	data->dy = TSIZE;
	if (!data->down)
		data->dy *= -1;
	data->dx = TSIZE / tan(dif->angle);
	if (!data->right && data->dx > 0)
		data->dx *= -1;
	if (data->right && data->dx < 0)
		data->dx *= -1;
	data->nextx = data->fx;
	data->nexty = data->fy;
	while (data->nextx > 0 && data->nextx < m->width \
		&& data->nexty > 0 && data->nexty < m->height)
		if (horzloop(m, data, dif))
			break ;
}

static bool	horzloop(t_mlx *m, t_rdata *data, t_rdif *dif)
{
	float	x;
	float	y;

	x = data->nextx;
	y = data->nexty;
	if (!data->down)
		y--;
	if (wallhit(x, y))
	{
		dif->horzx = data->nextx;
		dif->horzy = data->nexty;
		dif->horzcont = m->data->map[(int)floor(y / TSIZE)] \
									[(int)floor(x / TSIZE)];
		dif->horzflag = true;
		return (true);
	}
	else
	{
		data->nextx += data->dx;
		data->nexty += data->dy;
	}
	return (false);
}

void	vert_intersect(t_mlx *m, t_player *p, t_rdata *data, t_rdif *dif)
{
	dif->vertx = 0;
	dif->verty = 0;
	dif->vertcont = 0;
	dif->vertflag = false;
	data->fx = floor(p->x / TSIZE) * TSIZE;
	if (data->right)
		data->fx += TSIZE;
	data->fy = p->y + (data->fx - p->x) * tan(dif->angle);
	data->dx = TSIZE;
	if (!data->right)
		data->dx *= -1;
	data->dy = TSIZE * tan(dif->angle);
	if (!data->down && data->dy > 0)
		data->dy *= -1;
	if (data->down && data->dy < 0)
		data->dy *= -1;
	data->nextx = data->fx;
	data->nexty = data->fy;
	while (data->nextx > 0 && data->nextx < m->width \
		&& data->nexty > 0 && data->nexty < m->height)
		if (vertloop(m, data, dif))
			break ;
}

static bool	vertloop(t_mlx *m, t_rdata *data, t_rdif *dif)
{
	float	x;
	float	y;

	x = data->nextx;
	if (!data->right)
		x--;
	y = data->nexty;
	if (wallhit(x, y))
	{
		dif->vertx = data->nextx;
		dif->verty = data->nexty;
		dif->vertcont = m->data->map[(int)floor(y / TSIZE)] \
									[(int)floor(x / TSIZE)];
		dif->vertflag = true;
		return (true);
	}
	else
	{
		data->nextx += data->dx;
		data->nexty += data->dy;
	}
	return (false);
}

void	load_rays(t_mlx *mlx, t_player *p, t_rdif dif, int id)
{
	double	horzdist;
	double	vertdist;

	horzdist = INT32_MAX;
	vertdist = INT32_MAX;
	if (dif.horzflag)
		horzdist = linelen(p->x, p->y, dif.horzx, dif.horzy);
	if (dif.vertflag)
		vertdist = linelen(p->x, p->y, dif.vertx, dif.verty);
	if (vertdist < horzdist)
	{
		mlx->rays[id].dist = vertdist;
		mlx->rays[id].wallx = dif.vertx;
		mlx->rays[id].wally = dif.verty;
		mlx->rays[id].wallcontent = dif.vertcont;
		mlx->rays[id].wallvert = true;
	}
	else
	{
		mlx->rays[id].dist = horzdist;
		mlx->rays[id].wallx = dif.horzx;
		mlx->rays[id].wally = dif.horzy;
		mlx->rays[id].wallcontent = dif.horzcont;
		mlx->rays[id].wallvert = false;
	}
}
