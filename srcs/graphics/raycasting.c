/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:40:58 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/22 16:18:48 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_wall(t_data *data, int r, int size[2])
{
	get_frame(size[0], size, data, r);

}

void	draw_ceiling(t_data *data, int r, int size[2], int color)
{
	int	y;

	y = 0;
	while (y < size[0])
	{
		put_pixel_img(&data->frame, r, y, color);
		y++;
	}
}

void	draw_floor(t_data *data, int r, int size[2], int color)
{
	int	y;

	y = size[1];
	while (y < HEIGHT)
	{
		put_pixel_img(&data->frame, r, y, color);
		y++;
	}
}

void	raycasting(t_data *data, float ray_angle, int r)
{
	float	ray_size;
	float	corrected_size;
	int		wall_height;
	int		size[2];
	float	*rays;

	rays = data->game.rays;
	ray_size = sqrtf((rays[0] - data->game.p_x) * (rays[0] - data->game.p_x)
			+ (rays[1] - data->game.p_y) * (rays[1] - data->game.p_y));
	corrected_size = ray_size * cosf(ray_angle - data->game.dir);
	// if (corrected_size < 0.01)
	// 	corrected_size = 0.01;
	wall_height = (int)(HEIGHT / corrected_size);
	size[0] = (HEIGHT / 2) - (wall_height / 2);
	// if (size[0] < 0)
	// 	size[0] = 0;
	size[1] = (HEIGHT / 2) + (wall_height / 2);
	// if (size[1] > HEIGHT)
	// 	size[1] = HEIGHT;
	draw_ceiling(data, r, size, 0xFFFFF);
	draw_wall(data, r, size);
	draw_floor(data, r, size, 0x00FF00);
}
