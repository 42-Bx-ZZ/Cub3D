/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 02:12:41 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/25 03:33:55 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ennemy_on_center(t_data *data, int x_y[2], int size)
{
	int	center_x;
	int	center_y;
	int	tx;
	int	ty;
	int	color;

	center_x = data->width / 2;
	center_y = data->height / 2;
	if (center_x >= x_y[0] && center_x < x_y[0] + size
		&& center_y >= x_y[1] && center_y < x_y[1] + size)
	{
		tx = (center_x - x_y[0]) * data->map.textures.ennemy->width / size;
		ty = (center_y - x_y[1]) * data->map.textures.ennemy->height / size;
		color = data->map.textures.ennemy->data[ty
			* (data->map.textures.ennemy->size_line / 4) + tx];
		if ((color & 0x00FFFFFF) != 0 && sqrtf((data->ennemies[0].x + 0.5
					- data->game.p_x)
				* (data->ennemies[0].x + 0.5 - data->game.p_x)
				+ (data->ennemies[0].y + 0.5 - data->game.p_y)
				* (data->ennemies[0].y + 0.5 - data->game.p_y))
			< data->game.dda.zbuffer[center_x])
			return (1);
	}
	return (0);
}

static int	enemy_screen_x(t_data *data, float dx, float dy)
{
	float	angle;
	int		screen_x;

	angle = atan2f(dy, dx) - data->game.dir;
	if (angle < -M_PI)
		angle += 2 * M_PI;
	if (angle > M_PI)
		angle -= 2 * M_PI;
	if (fabsf(angle) > (FOV * M_PI / 180.0f) / 2.0f)
		return (-1);
	screen_x = (int)((angle / ((FOV * M_PI / 180.0f) / 2.0f))
			* (data->width / 2) + (data->width / 2));
	return (screen_x);
}

static int	enemy_sprite_size(t_data *data, float dx, float dy)
{
	float	dist;

	dist = sqrtf(dx * dx + dy * dy);
	if (dist < 0.1f)
		dist = 0.1f;
	return ((int)(data->height / dist));
}

void	draw_enemy_sprite(t_data *data, int x_y[2], int size, float enemy_dist)
{
	int		s_x_y[2];
	int		t_x_y[2];
	int		color;
	int		screen_x;

	s_x_y[1] = -1;
	while (++s_x_y[1] < size && x_y[1] + s_x_y[1] < data->height)
	{
		s_x_y[0] = -1;
		while (++s_x_y[0] < size && x_y[0] + s_x_y[0] < data->width)
		{
			screen_x = x_y[0] + s_x_y[0];
			if (screen_x >= 0 && screen_x < data->width
				&& enemy_dist < data->game.dda.zbuffer[screen_x])
			{
				t_x_y[0] = s_x_y[0] * data->map.textures.ennemy->width / size;
				t_x_y[1] = s_x_y[1] * data->map.textures.ennemy->height / size;
				color = data->map.textures.ennemy->data[t_x_y[1]
					* (data->map.textures.ennemy->size_line / 4) + t_x_y[0]];
				if ((color & 0x00FFFFFF) != 0)
					put_pixel_img(&data->frame, screen_x, x_y[1]
						+ s_x_y[1], color);
			}
		}
	}
}

void	draw_enemy(t_data *data, int i)
{
	float	d_x_y[2];
	int		screen_x;
	int		size;
	int		x_y[2];

	if (!data->ennemies[i].alive)
		return ;
	d_x_y[0] = data->ennemies[i].x + 0.5 - data->game.p_x;
	d_x_y[1] = data->ennemies[i].y + 0.5 - data->game.p_y;
	screen_x = enemy_screen_x(data, d_x_y[0], d_x_y[1]);
	if (screen_x < 0 || screen_x >= data->width)
		return ;
	size = enemy_sprite_size(data, d_x_y[0], d_x_y[1]);
	x_y[1] = (data->height / 2) - (size / 2);
	x_y[0] = screen_x - (size / 2);
	draw_enemy_sprite(data, x_y, size, sqrtf(d_x_y[0] * d_x_y[0]
			+ d_x_y[1] * d_x_y[1]));
	if (ennemy_on_center(data, x_y, size) && data->keys.e)
		data->ennemies[i].alive = 0;
}
