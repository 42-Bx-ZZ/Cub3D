/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:56:38 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/08 11:59:38 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_gun(t_data *data)
{
	int		gun_x;
	int		gun_y;
	int		x;
	int		y;
	int		color;

	gun_x = data->width - data->player.gun.idle.width;
	gun_y = data->height - data->player.gun.idle.height;
	y = 0;
	while (y < data->player.gun.idle.height)
	{
		x = 0;
		while (x < data->player.gun.idle.width)
		{
			color = data->player.gun.idle.data[y
				* (data->player.gun.idle.size_line / 4) + x];
			if ((color & 0x00FFFFFF) != 0)
				put_pixel_img(&data->frame, gun_x + x, gun_y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_items(t_data *data)
{
	int	i;

	i = data->gameplay.z_count - 1;
	sort_ennemies(data);
	while (i >= 0)
	{
		if (data->ennemies[i].alive)
			draw_enemy(data, i);
		i--;
	}
	if (data->keys.mouse.firing && data->player.targeting
		&& data->player.gun.stance == 0)
		hit_ennemy(data, data->player.target);
	else if (data->keys.mouse.firing)
	{
		data->keys.mouse.fire_frames = 20;
		data->keys.mouse.firing = 0;
	}
	swap_gun_stance(data);
	draw_crosshair(data);
	draw_gun(data);
	map_on_frame(data);
}
