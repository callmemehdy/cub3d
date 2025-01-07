/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:53:26 by ael-amma          #+#    #+#             */
/*   Updated: 2025/01/07 09:03:51 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	 put_tile(mlx_image_t *img, int y, int x, unsigned int color)
{
	for (int i = y; i < y + T_SIZE; i++) {
		for (int j = x; j < x + T_SIZE; j++) {
			if (j % T_SIZE == 0 || i % T_SIZE == 0) {
				mlx_put_pixel(img, j, i, 0xFFFF0012);
			}
			else
				mlx_put_pixel(img, j, i, color);
		}
	}
}

void	render_squares(mlx_image_t *img, t_data *data)
{
	for (int i = 0; i < data->y; i++) {
		for (int j = 0; j < data->x; j++) {
			if (data->map[i][j] == '1') {
				put_tile(img, i * T_SIZE, j * T_SIZE, 0x000000FF);
			}
			else if (is_player(data->map[i][j]) || data->map[i][j] == '0')
				put_tile(img, i * T_SIZE, j * T_SIZE, 0xFFFFFFFF);
			else		
				put_tile(img, i * T_SIZE, j * T_SIZE, 0xFF00FFFF);
		}
	}
}
void bres_line(t_player *player, int xp, int yp, bool hit)
{
    if (!hit)
        return;

    int x0 = player->p_x;
    int y0 = player->p_y;

    int dx = abs(xp - x0);
    int dy = abs(yp - y0);

    int sx = (x0 < xp) ? 1 : -1;
    int sy = (y0 < yp) ? 1 : -1;

    int err = dx - dy; // Error term

    while (1) {
        mlx_put_pixel(player->img, x0, y0, 0x0000FFFF); // Draw the pixel

        if (x0 == xp && y0 == yp) // Reached the end point
            break;

        int e2 = err * 2;

        if (e2 > -dy) { // Move horizontally
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx) { // Move vertically
            err += dx;
            y0 += sy;
        }
    }
}


// void	bres_line(t_player *player, int xp, int yp, bool hit)
// {
// 	int dx, dy, step;
// 	double xstep, ystep;

// 	if (!hit)
// 		return ;
// 	dx = xp - player->p_x;
// 	dy = yp - player->p_y;
// 	step = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
// 	xstep = dx / (double)step;
// 	ystep = dy / (double)step;
// 	printf("%f\n", xstep);
// 	printf("%f\n", ystep);
// 	double x = player->p_x, y = player->p_y;
// 	for (int i = 0;i <= step;i++) {
// 		mlx_put_pixel(player->img, round(x), round(y), 0x0000FFFF);
// 		x+=xstep;
// 		y+=ystep;
// 	}
// 	// todo
// }

void	hooks(mlx_key_data_t key, void *p)
{
	t_player *player;


	// this is a code for player's movement testing
	// gotta make some boundries checks


	//////////////////////////////
	//minimpa max width & height//
	//////////////////////////////
	player = (t_player *)p;
	if (key.key == MLX_KEY_W && key.action == MLX_REPEAT) {
		player->p_y -= P_SPEED;
		render_squares(player->img, player->data);
		mlx_put_pixel(player->img, player->p_x, player->p_y, 0x0000FFFF);		
	} else if (key.key == MLX_KEY_S && key.action == MLX_REPEAT) {
		player->p_y += P_SPEED;
		render_squares(player->img, player->data);
		mlx_put_pixel(player->img, player->p_x, player->p_y, 0x0000FFFF);
	} else if (key.key == MLX_KEY_A && key.action == MLX_REPEAT) {
		player->p_x -= P_SPEED;
		render_squares(player->img, player->data);
		mlx_put_pixel(player->img, player->p_x, player->p_y, 0x0000FFFF);		
	} else if (key.key == MLX_KEY_D && key.action == MLX_REPEAT) {
		player->p_x += P_SPEED;
		render_squares(player->img, player->data);
		mlx_put_pixel(player->img, player->p_x, player->p_y, 0x0000FFFF);			
	} else if (key.key == MLX_KEY_ESCAPE)
		exit(0);
}

void	find_horinter(t_ray *ray, double *hx, double *hy, double *inter_x, double *inter_y)
{
	float	yinter;
	float	xinter;
	float	x_step;
	float	y_step;

	// gotta use this coordinates to check if the intersections are on a wall.
	yinter = floor(ray->player->p_y / (double)T_SIZE) * T_SIZE ;
	!ray->is_up && (yinter += T_SIZE);
	xinter = ray->player->p_x + (yinter - ray->player->p_y) / tan(ray->r_angle); 
	y_step = T_SIZE;
	ray->is_up && (y_step *= -1);
	x_step = T_SIZE / tan(ray->r_angle);
	(!ray->is_right && x_step > 0) && (x_step *= -1);
	(ray->is_right && x_step < 0) && (x_step *= -1);
	*hx = round(x_step);
	*hy = y_step;
	*inter_x = xinter; 
	*inter_y = yinter;
}

bool	is_wall(int	x, int y)
{
	t_data *data;

	data = *get_data();
	// printf("y: %d,x: %d", y * T_SIZE, x * T_SIZE);
	// exit(0);
	if (data->map[y / T_SIZE][x / T_SIZE] == '1')
		return true;
	return (false);
}

void	cast_single_ray(t_ray	*ray, int ray_id)
{
	double		hx; // xstep
	double		hy; // ystep
	double		hx_inc;
	double		hy_inc;
	// int		vx;
	// int		vy;

	ray->is_up = (ray->r_angle < 2 * PI && ray->r_angle  > PI);
	ray->is_right = (ray->r_angle < PI / 2 || ray->r_angle > 3 * PI / 2);
	find_horinter(ray, &hx, &hy, &hx_inc, &hy_inc);
	while (hx_inc >= 0 && hx_inc < W_WIDTH && hy_inc >= 0 && hy_inc < W_HEIGHT)
	{
		if (is_wall(round(hx_inc), round(ray->is_up ? hy_inc - 1 : hy_inc))) {
			puts("hate everything about you!\n");
			ray->w_hitx = round(hx_inc);
			ray->w_hity = round(hy_inc);
			ray->hit = true;
			break ;
		} else {
			hx_inc += hx;
			hy_inc += hy;
		}
	}
	bres_line(ray->player, ray->w_hitx, ray->w_hity, ray->hit);
	// find_verinter(ray, &vx, &vy);
}

double	sanitizing_angle(double  ray_angle)
{
	ray_angle = remainder(ray_angle, 2 * PI);
	if (ray_angle < 0) {
		ray_angle += (2 * PI);
	}
	return (ray_angle);	
}

void	test_rays(t_player *player)
{
	int		ray_count;
	double	ray_inc; 
	double	ray_ang; 
	t_ray	rays[W_WIDTH];

	ray_count = 0;
	ray_ang = sanitizing_angle(player->p_angle - player->fov/2);
	ray_inc = player->fov / (double)W_WIDTH;
	rays[ray_count] = (t_ray){0};
	while (ray_count < 2000)
	{
		rays[ray_count].player = player;
		rays[ray_count].r_angle = sanitizing_angle(ray_ang);
		cast_single_ray(&rays[ray_count], ray_count);
		++ray_count;
		ray_ang += ray_inc;
	}
}


void	game(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_data		*data;
	t_player	player;

	player = (t_player){0};
	data = *get_data();
	mlx = mlx_init(W_WIDTH, W_HEIGHT, data->title, true);
	img = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
	player.p_x = data->px * T_SIZE + (T_SIZE / 2);
	player.p_y = data->py * T_SIZE + (T_SIZE / 2);
	player.fov = (double)FOV * (PI / (double)180);
	player.data = data;
	player.img = img;
	player.p_angle = N;
	render_squares(img, data);
	test_rays(&player);
	mlx_put_pixel(img, player.p_x, player.p_y, 0x0000FFFF);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, hooks, &player);
	mlx_loop(mlx);
	// todo
}
