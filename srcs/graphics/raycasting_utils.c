/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:46:33 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/23 10:40:49 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_img	*wall_side(t_data *data)
{
	int	x;
	int	y;
	int	prev_x;
	int	prev_y;

	x = (int)data->game.rays[0];
	y = (int)data->game.rays[1];
	prev_x = (int)data->game.rays[2];
	prev_y = (int)data->game.rays[3];
	if (x != prev_x)
	{
		if (x > prev_x)
			return (&data->map.textures.west);
		else 
			return (&data->map.textures.east);
	}
	else
	{
		if (y > prev_y)
			return (&data->map.textures.north);
		else
			return (&data->map.textures.south);
	}
	return (&data->map.textures.north);
}

int	get_frame(int y, int size[2], t_data *data, int r)
{
	t_img	*img;
	int		tex_x;
	int		tex_y;
	float	wall_hit;
	int		color;

	img = wall_side(data);
	if (img == &data->map.textures.east || img == &data->map.textures.west)
		wall_hit = data->game.rays[1] - floorf(data->game.rays[1]);
	else
		wall_hit = data->game.rays[0] - floorf(data->game.rays[0]);
	tex_x = (int)(wall_hit * img->width);
	y = size[0];
	while (y < size[1] && y < HEIGHT)
	{
		tex_y = (int)(((float)(y - size[0]) / (size[1] - size[0])) * img->height);
		color = img->data[tex_y * (img->size_line / 4) + tex_x];
		put_pixel_img(&data->frame, r, y, color);
		y++;
	}
	return (0);
}
