/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_screen_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:30:24 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/04 14:18:05 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	scale_pixel_loop(t_data *data, int *src_data, int *dst_data,
		int params[4])
{
	int	x;
	int	y;
	int	src_x;
	int	src_y;
	int	color;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			src_x = (x * params[0]) / data->width;
			src_y = (y * params[1]) / data->height;
			if (src_x >= 0 && src_x < params[0] && src_y >= 0
				&& src_y < params[1])
				color = src_data[src_y * (params[2] / 4) + src_x];
			else
				color = 0x000000;
			dst_data[y * (data->frame.size_line / 4) + x] = color;
			x++;
		}
		y++;
	}
}

void	copy_scaled_image(t_data *data, void *src_img, int src_w, int src_h)
{
	int		*src_data;
	int		*dst_data;
	int		params[4];

	src_data = (int *)mlx_get_data_addr(src_img, &params[2], &params[3],
			&params[0]);
	dst_data = data->frame.data;
	if (!src_data || !dst_data)
		return ;
	params[0] = src_w;
	params[1] = src_h;
	params[2] = params[3];
	params[3] = 0;
	scale_pixel_loop(data, src_data, dst_data, params);
}

void	draw_loading_bar_on_buffer(t_data *data, int progress)
{
	int	bar_x;
	int	bar_y;
	int	bar_width;
	int	x;
	int	y;

	bar_x = (data->width - LOADING_BAR_WIDTH) / 2;
	bar_y = data->height - 80;
	bar_width = (LOADING_BAR_WIDTH * progress) / LOADING_STEPS;
	y = bar_y;
	while (y < bar_y + LOADING_BAR_HEIGHT)
	{
		x = bar_x;
		while (x < bar_x + bar_width)
		{
			if (x >= 0 && x < data->width && y >= 0 && y < data->height)
				data->frame.data[y * (data->frame.size_line / 4) + x]
					= 0xFFFFFF;
			x++;
		}
		y++;
	}
}

static void	draw_opening_mask(t_data *data, int mask_height)
{
	int	y;
	int	x;

	y = 0;
	while (y < mask_height)
	{
		x = 0;
		while (x < data->width)
		{
			data->frame.data[y * (data->frame.size_line / 4) + x] = 0x000000;
			data->frame.data[(data->height - 1 - y)
				* (data->frame.size_line / 4) + x] = 0x000000;
			x++;
		}
		y++;
	}
}

void	opening_animation(t_data *data)
{
	int	step;
	int	mask_height;

	update_frame(data, FOV, RAYS, data->map.setup);
	step = 0;
	while (step < OPENING_ANIMATION_STEPS)
	{
		update_frame(data, FOV, RAYS, data->map.setup);
		mask_height = (data->height / 2) * (OPENING_ANIMATION_STEPS - step)
			/ OPENING_ANIMATION_STEPS;
		draw_opening_mask(data, mask_height);
		mlx_put_image_to_window(data->mlx, data->win, data->frame.ptr, 0, 0);
		mlx_do_sync(data->mlx);
		usleep(20000);
		step++;
	}
}
