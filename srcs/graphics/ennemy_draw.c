/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 02:12:41 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/04 08:53:44 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ennemy_on_center(t_data *data, int x_y[2], int size, int i)
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
		if ((color & 0x00FFFFFF) != 0 && sqrtf((data->ennemies[i].x + 0.5
					- data->game.p_x)
				* (data->ennemies[i].x + 0.5 - data->game.p_x)
				+ (data->ennemies[i].y + 0.5 - data->game.p_y)
				* (data->ennemies[i].y + 0.5 - data->game.p_y))
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

int	enemy_sprite_size(t_data *data, float dx, float dy)
{
	float	dist;

	dist = sqrtf(dx * dx + dy * dy);
	if (dist < 0.1f)
		dist = 0.1f;
	return ((int)(data->height / dist));
}

void	draw_enemy_sprite(t_data *data, int x_y[2], int s[2], float dist)
{
	int		s_x_y[2];
	int		t_x_y[2];
	int		color;
	int		screen_x;

	s_x_y[1] = -1;
	while (++s_x_y[1] < s[0] && x_y[1] + s_x_y[1] < data->height)
	{
		s_x_y[0] = -1;
		while (++s_x_y[0] < s[0] && x_y[0] + s_x_y[0] < data->width)
		{
			screen_x = x_y[0] + s_x_y[0];
			if (screen_x >= 0 && screen_x < data->width
				&& dist < data->game.dda.zbuffer[screen_x])
			{
				t_x_y[0] = s_x_y[0] * data->ennemies[s[1]].f.width / s[0];
				t_x_y[1] = s_x_y[1] * data->ennemies[s[1]].f.height / s[0];
				color = data->ennemies[s[1]].f.data[t_x_y[1]
					* (data->ennemies[s[1]].f.size_line / 4) + t_x_y[0]];
				if ((color & 0x00FFFFFF) != 0)
					put_pixel_img(&data->frame, screen_x, x_y[1]
						+ s_x_y[1], color_shaders(color, data, dist));
			}
		}
	}
}

void	draw_enemy(t_data *data, int i)
{
	float	d_x_y[2];
	int		screen_x;
	int		s[2];
	int		x_y[2];

	if (!data->ennemies[i].alive)
		return ;
	d_x_y[0] = data->ennemies[i].x - data->game.p_x;
	d_x_y[1] = data->ennemies[i].y - data->game.p_y;
	screen_x = enemy_screen_x(data, d_x_y[0], d_x_y[1]);
	if (screen_x < 0 || screen_x >= data->width)
		return ;
	s[0] = enemy_sprite_size(data, d_x_y[0], d_x_y[1]);
	x_y[1] = (data->height / 2) - (s[0] / 2);
	x_y[0] = screen_x - (s[0] / 2);
	s[1] = i;
	draw_enemy_sprite(data, x_y, s, sqrtf(d_x_y[0] * d_x_y[0]
			+ d_x_y[1] * d_x_y[1]));
	if (ennemy_on_center(data, x_y, s[0], i) && data->keys.mouse.l_click == 1)
	{
		hit_ennemy(data, i);
	}
}
