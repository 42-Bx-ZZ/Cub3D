/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:09:13 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/16 09:53:30 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	moves(int key, t_data *data)
{
	if ((int)data->game.p_x > 0 && (int)data->game.p_y > 0 && data->map.setup[(int)data->game.p_y][(int)data->game.p_x])
		if (key == LEFT && data->map.setup[(int)round(data->game.p_y - STEP)][(int)data->game.p_x] != 1)
		{
			data->game.p_y -= STEP;
			printf("POS = %f %f\n", data->game.p_x, data->game.p_y);
		}
	return ;
}

void	view(int key, t_data *data)
{
	if (key == R_ARROW)
	{
		draw_view(data, 0);
		data->game.dir += 0.5;
		draw_view(data, 1);
	}
	if (key == L_ARROW)
	{
		draw_view(data, 0);
		data->game.dir -= 0.5;
		draw_view(data, 1);
	}
	return ;
}

int keys_hook(int key, t_data *data)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		moves(key, data);
    else if (key == L_ARROW || key == R_ARROW)
		view(key, data);
    if (key == ESC)
        clean_exit(data);
    return (0);
}
