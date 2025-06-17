/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:43:16 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/17 20:49:23 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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
	return (0);
}

int	update_move(t_data *data)
{
	int moved;

	moved = 0;
	if (data->keys.up)
		moves(UP, data);
	if (data->keys.down)
		moves(DOWN, data);
	if (data->keys.left)
		moves(LEFT, data);
	if (data->keys.right)
		moves(RIGHT, data);
	if (data->keys.l_arrow)
		view(L_ARROW, data);
	if (data->keys.r_arrow)
		view(R_ARROW, data);
	if (data->keys.up || data->keys.down || data->keys.left || data->keys.right
		|| data->keys.l_arrow || data->keys.r_arrow)
		moved = 1;
	if (moved || data->keys.f)
		draw_view(data, FOV, RAYS, data->map.setup);
	return (data->keys.f = 0, 0);
}
