/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:40:58 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/24 15:56:04 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_wall(t_data *data, size_t r, int size[2])
{
	get_frame(size[0], size, data, r);

}

void	draw_ceiling(t_data *data, size_t r, int size[2], int color)
{
	int	y;

	y = 0;
	while (y < size[0])
	{
		put_pixel_img(&data->frame, r, y, color);
		y++;
	}
}

void	draw_floor(t_data *data, size_t r, int size[2], int color)
{
	int	y;

	y = size[1];
	while (y < HEIGHT)
	{
		put_pixel_img(&data->frame, r, y, color);
		y++;
	}
}

void	raycasting(t_data *data, size_t r)
{
	float	wall_dist;
	int		wall_height;
	int		size[2];
	float	*rays;

	rays = data->game.rays;
	wall_dist = rays[4];
	if (wall_dist < 0.001)
		wall_dist = 0.001;
	wall_height = (int)(HEIGHT / wall_dist);
	size[0] = (HEIGHT / 2) - (wall_height / 2);
	size[1] = (HEIGHT / 2) + (wall_height / 2);
	draw_ceiling(data, r, size, 0xFFFFF);
	draw_wall(data, r, size);
	draw_floor(data, r, size, 0x00FF00);
}
