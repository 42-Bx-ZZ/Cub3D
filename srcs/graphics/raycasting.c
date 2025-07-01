/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:40:58 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/01 17:22:22 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_crosshair(t_data *data)
{
	int	x;
	int	y;
	int	i;

	x = WIDTH / 2;
	y = HEIGHT / 2;
	i = -10;
	while (i <= 10)
	{
		if (i != 0)
		{
			put_pixel_img(&data->frame, x + i, y, 0xFFFFFF);
			put_pixel_img(&data->frame, x, y + i, 0xFFFFFF);
		}
		i++;
	}
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
	while (y < data->height)
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

	wall_dist = data->game.perp_wall;
	if (wall_dist < 0.001)
		wall_dist = 0.001;
	wall_height = (int)(data->height / wall_dist);
	size[0] = (data->height / 2) - (wall_height / 2);
	size[1] = (data->height / 2) + (wall_height / 2);
	draw_ceiling(data, r, size, argb_colors(0, data->map.textures.ceiling_color));
	get_frame(size[0], size, data, r);
	draw_floor(data, r, size, argb_colors(0, data->map.textures.floor_color));
}
