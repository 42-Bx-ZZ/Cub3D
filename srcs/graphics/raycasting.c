/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:40:58 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/17 19:14:56 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_wall(t_data *data, int r, int size[2], int color)
{
	int	y;

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
	while (y < size[1])
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

void	raycasting(t_data *data, float ray_angle, float rays[2], int r)
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
	draw_ceiling(data, r, size, 0x000000);
	draw_wall(data, r, size, 0x00FF00);
	draw_floor(data, r, size, 0x000000);
}
