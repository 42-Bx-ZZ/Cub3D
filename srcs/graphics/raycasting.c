/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:40:58 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/19 19:11:37 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	wall_side(float rays[4])
{
	int	x;
	int	y;
	int	prev_x;
	int	prev_y;

	x = (int)rays[0];
	y = (int)rays[1];
	prev_x = (int)rays[2];
	prev_y = (int)rays[3];
	if (x != prev_x)
	{
		if (x > prev_x)
			return ('W');
		else
			return ('E');
	}
	else
	{
		if (y > prev_y)
			return ('N');
		else
			return ('S');
	}
	return ('N');
}

void	draw_wall(t_data *data, int r, int size[2], char w)
{
	int	y;
	int	color;

	if (w == 'N')
		color = 0xF20000;
	else if (w == 'S')
		color = 0xFF69B4;
	else if (w == 'E')
		color = 0x0000FF;
	else
		color = 0x000000;
	y = size[0];
	while (y < size[1])
	{
		mlx_pixel_put(data->mlx, data->win, r, y, color);
		y++;
	}
}

void	draw_ceiling(t_data *data, int r, int size[2], int color)
{
	int	y;

	y = 0;
	while (y < size[0])
	{
		mlx_pixel_put(data->mlx, data->win, r, y, color);
		y++;
	}
}

void	draw_floor(t_data *data, int r, int size[2], int color)
{
	int	y;

	y = size[1];
	while (y < HEIGHT)
	{
		mlx_pixel_put(data->mlx, data->win, r, y, color);
		y++;
	}
}

void	raycasting(t_data *data, float ray_angle, float rays[4], int r)
{
	float	ray_size;
	float	corrected_size;
	int		wall_height;
	int		size[2];

	ray_size = sqrt((rays[0] - data->game.p_x) * (rays[0] - data->game.p_x)
			+ (rays[1] - data->game.p_y) * (rays[1] - data->game.p_y));
	corrected_size = ray_size * cos(ray_angle - data->game.dir);
	wall_height = (int)(HEIGHT / corrected_size);
	size[0] = (HEIGHT / 2) - (wall_height / 2);
	if (size[0] < 0)
		size[0] = 0;
	size[1] = (HEIGHT / 2) + (wall_height / 2);
	if (size[1] > HEIGHT)
		size[1] = HEIGHT;
	draw_ceiling(data, r, size, 0xFFFFF);
	draw_wall(data, r, size, wall_side(rays));
	draw_floor(data, r, size, 0x00FF00);
}
