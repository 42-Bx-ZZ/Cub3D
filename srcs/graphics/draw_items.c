/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:56:38 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/04 09:27:38 by lowatell         ###   ########.fr       */
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

	gun_x = data->width - data->player.gun.sprite.width;
	gun_y = data->height - data->player.gun.sprite.height;
	y = 0;
	while (y < data->player.gun.sprite.height)
	{
		x = 0;
		while (x < data->player.gun.sprite.width)
		{
			color = data->player.gun.sprite.data[y
				* (data->player.gun.sprite.size_line / 4) + x];
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

	i = 0;
	sort_ennemies(data);
	while (i < data->gameplay.z_count)
	{
		if (data->ennemies[i].alive)
			draw_enemy(data, i);
		i++;
	}
	draw_crosshair(data);
	draw_gun(data);
	map_on_frame(data);
}
