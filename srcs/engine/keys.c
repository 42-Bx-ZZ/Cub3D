/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:43:16 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/25 17:43:50 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	mouse_click(int key, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (key == L_CLICK)
	{
		if (data->keys.mouse.fire_frames <= 0)
		{
			data->keys.mouse.firing = 1;
		}
	}
	if (key == SCROLL_UP || key == SCROLL_DOWN)
		swap_gun(data);
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == UP)
		data->keys.up = 1;
	if (key == DOWN)
		data->keys.down = 1;
	if (key == LEFT)
		data->keys.left = 1;
	if (key == RIGHT)
		data->keys.right = 1;
	if (key == L_ARROW)
		data->keys.l_arrow = 1;
	if (key == R_ARROW)
		data->keys.r_arrow = 1;
	if (key == SHIFT)
		data->keys.shift = 1;
	if (key == E)
		data->keys.e = 1;
	if (key == ESC)
		clean_exit(data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == UP)
		data->keys.up = 0;
	if (key == DOWN)
		data->keys.down = 0;
	if (key == LEFT)
		data->keys.left = 0;
	if (key == RIGHT)
		data->keys.right = 0;
	if (key == L_ARROW)
		data->keys.l_arrow = 0;
	if (key == R_ARROW)
		data->keys.r_arrow = 0;
	if (key == SHIFT)
		data->keys.shift = 0;
	if (key == E)
		data->keys.e = 0;
	return (0);
}
