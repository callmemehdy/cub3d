/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:53:26 by ael-amma          #+#    #+#             */
/*   Updated: 2024/12/31 16:00:07 by mel-akar         ###   ########.fr       */
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

void	cast_single_ray(t_ray	*ray, int ray_id)
{
	ray->is_up = ray->r_angle > 0 && ray->r_angle < PI;
	ray->is_right = ray->r_angle < PI / 2 || ray->r_angle > 3 * PI / 3;
}

void	test_rays(t_player *player)
{
	int		ray_count;
	double	ray_inc;
	t_ray	rays[W_WIDTH];

	ray_count = 0;
	ray_inc = player->fov / W_WIDTH;
	rays[ray_count].r_angle = player->p_angle - (player->fov / 2);
	while (ray_count < W_WIDTH)
	{
		rays[ray_count] = (t_ray){0};
		ray_count > 0 && (rays[ray_count].r_angle = rays[ray_count - 1].r_angle + ray_inc);
		cast_single_ray(&rays[ray_count], ray_count);
		++ray_count;
	}
}

void	bres_line(t_player *player, int xp, int yp)
{
	int dx, dy, step;
	double xstep, ystep;

	dx = xp - player->p_x;
	dy = yp - player->p_y;
	step = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
	xstep = dx / (double)step;
	ystep = dy / (double)step;
	printf("%f\n", xstep);
	printf("%f\n", ystep);
	double x = player->p_x, y = player->p_y;
	for (int i = 0;i <= step;i++) {
		mlx_put_pixel(player->img, round(x), round(y), 0x0000FFFF);
		x+=xstep;
		y+=ystep;
	}
	// todo
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
	player.fov = FOV * PI / 180;
	player.data = data;
	player.img = img;
	render_squares(img, data);
	// test_rays(&player);
	printf("x: %d\n", player.p_x);
	printf("y: %d\n", player.p_y);
	bres_line(&player, 1470, 0);
	mlx_put_pixel(img, player.p_x, player.p_y, 0x0000FFFF);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, hooks, &player);
	mlx_loop(mlx);
	// todo
}
