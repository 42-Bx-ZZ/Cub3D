/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:30:00 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/03 14:30:00 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	get_crosshair_spread(t_data *data)
{
	if (data->keys.up || data->keys.down || data->keys.left || data->keys.right)
	{
		if (data->keys.shift)
			return (25);
		else
			return (15);
	}
	return (0);
}

static void	draw_crosshair_horizontal(t_data *data, int screen_center_x,
		int screen_center_y, int spread_value)
{
	draw_left_horizontal_segment(data, screen_center_x, screen_center_y,
		spread_value);
	draw_right_horizontal_segment(data, screen_center_x, screen_center_y,
		spread_value);
}

static void	draw_crosshair_vertical(t_data *data, int screen_center_x,
		int screen_center_y, int spread_value)
{
	draw_top_vertical_segment(data, screen_center_x, screen_center_y,
		spread_value);
	draw_bottom_vertical_segment(data, screen_center_x, screen_center_y,
		spread_value);
}

void	draw_crosshair(t_data *data)
{
	int	screen_center_x;
	int	screen_center_y;
	int	spread_value;

	screen_center_x = data->width / 2;
	screen_center_y = data->height / 2;
	spread_value = get_crosshair_spread(data);
	draw_crosshair_horizontal(data, screen_center_x, screen_center_y,
		spread_value);
	draw_crosshair_vertical(data, screen_center_x, screen_center_y,
		spread_value);
}
