/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:45:00 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/03 14:45:00 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_left_horizontal_segment(t_data *data, int screen_center_x,
		int screen_center_y, int spread_value)
{
	int	horizontal_pos;
	int	thickness_offset;
	int	base_distance;

	base_distance = 5;
	horizontal_pos = -(15 + spread_value);
	while (horizontal_pos <= -(base_distance + spread_value))
	{
		thickness_offset = -1;
		while (thickness_offset <= 1)
		{
			put_pixel_img(&data->frame, screen_center_x + horizontal_pos,
				screen_center_y + thickness_offset, 0xFFFFFF);
			thickness_offset++;
		}
		horizontal_pos++;
	}
}

void	draw_right_horizontal_segment(t_data *data, int screen_center_x,
		int screen_center_y, int spread_value)
{
	int	horizontal_pos;
	int	thickness_offset;
	int	base_distance;

	base_distance = 5;
	horizontal_pos = base_distance + spread_value;
	while (horizontal_pos <= 15 + spread_value)
	{
		thickness_offset = -1;
		while (thickness_offset <= 1)
		{
			put_pixel_img(&data->frame, screen_center_x + horizontal_pos,
				screen_center_y + thickness_offset, 0xFFFFFF);
			thickness_offset++;
		}
		horizontal_pos++;
	}
}

void	draw_top_vertical_segment(t_data *data, int screen_center_x,
		int screen_center_y, int spread_value)
{
	int	vertical_pos;
	int	thickness_offset;
	int	base_distance;

	base_distance = 5;
	vertical_pos = -(15 + spread_value);
	while (vertical_pos <= -(base_distance + spread_value))
	{
		thickness_offset = -1;
		while (thickness_offset <= 1)
		{
			put_pixel_img(&data->frame, screen_center_x + thickness_offset,
				screen_center_y + vertical_pos, 0xFFFFFF);
			thickness_offset++;
		}
		vertical_pos++;
	}
}

void	draw_bottom_vertical_segment(t_data *data, int screen_center_x,
		int screen_center_y, int spread_value)
{
	int	vertical_pos;
	int	thickness_offset;
	int	base_distance;

	base_distance = 5;
	vertical_pos = base_distance + spread_value;
	while (vertical_pos <= 15 + spread_value)
	{
		thickness_offset = -1;
		while (thickness_offset <= 1)
		{
			put_pixel_img(&data->frame, screen_center_x + thickness_offset,
				screen_center_y + vertical_pos, 0xFFFFFF);
			thickness_offset++;
		}
		vertical_pos++;
	}
}
