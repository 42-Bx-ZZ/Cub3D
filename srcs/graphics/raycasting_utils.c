/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:46:33 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/01 10:19:55 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_img	*wall_side(t_data *data)
{
	if (data->map.setup[(int)data->game.dda.y][(int)data->game.dda.x] &&
		data->map.setup[(int)data->game.dda.y][(int)data->game.dda.x] == 'D')
		return (&data->map.textures.door);
	if (data->game.dda.side == 0)
	{
		if (data->game.dda.ray_dir_x > 0)
			return (&data->map.textures.west);
		return (&data->map.textures.east);
	}
	else
	{
		if (data->game.dda.ray_dir_y > 0)
			return (&data->map.textures.north);
		return (&data->map.textures.south);
	}
}

int	get_frame(int y, int size[2], t_data *data, int r)
{
	t_img	*img;
	int		tex_x;
	int		tex_y;
	float	wall_hit;
	int		color;

	img = wall_side(data);
	if (data->game.dda.side == 0)
		wall_hit = data->game.rays[1] - floorf(data->game.rays[1]);
	else
		wall_hit = data->game.rays[0] - floorf(data->game.rays[0]);
	tex_x = (int)(wall_hit * img->width);
	y = size[0];
	while (y < size[1] && y < data->height)
	{
		tex_y = (int)(((float)(y - size[0])
					/ (size[1] - size[0])) * img->height);
		color = img->data[tex_y * (img->size_line / 4) + tex_x];
		put_pixel_img(&data->frame, r, y, color);
		y++;
	}
	return (0);
}
