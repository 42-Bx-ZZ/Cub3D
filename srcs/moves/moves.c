/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:09:13 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/16 22:42:31 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	moves(int key, t_data *data)
{
	if (data->game.p_x > 0 && data->game.p_y > 0 && data->map.setup[(int)data->game.p_y][(int)data->game.p_x])
	{
		if (key == UP && data->map.setup[(int)(data->game.p_y + (sin(data->game.dir) * STEP))][(int)(data->game.p_x + (cos(data->game.dir) * STEP))] != '1')
		{
			data->game.p_x += cos(data->game.dir) * STEP;
			data->game.p_y += sin(data->game.dir) * STEP;
		}
		if (key == DOWN && data->map.setup[(int)(data->game.p_y - (sin(data->game.dir) * STEP))][(int)(data->game.p_x - (cos(data->game.dir) * STEP))] != '1')
		{
			data->game.p_x -= cos(data->game.dir) * STEP;
			data->game.p_y -= sin(data->game.dir) * STEP;
		}
	 	if (key == LEFT && data->map.setup[(int)(data->game.p_y - (cos(data->game.dir + M_PI_2) * STEP))][(int)(data->game.p_x - (sin(data->game.dir + M_PI_2) * STEP))] != '1')
		{
			data->game.p_x -= cos(data->game.dir + M_PI_2) * STEP;
			data->game.p_y -= sin(data->game.dir + M_PI_2) * STEP;
		}
		if (key == RIGHT && data->map.setup[(int)(data->game.p_y + (cos(data->game.dir + M_PI_2) * STEP))][(int)(data->game.p_x + (sin(data->game.dir + M_PI_2) * STEP))] != '1')
		{
			data->game.p_x += cos(data->game.dir + M_PI_2) * STEP;
			data->game.p_y += sin(data->game.dir + M_PI_2) * STEP;
		}
	}
}

void	view(int key, t_data *data)
{
	if (key != R_ARROW && key != L_ARROW)
		return ;
	draw_view(data, 0);
	if (key == R_ARROW)
		data->game.dir += 0.2;
	if (key == L_ARROW)
		data->game.dir -= 0.2;
	draw_view(data, 1);
}

int keys_hook(int key, t_data *data)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
	{
		draw_view(data, 0);
		moves(key, data);
		draw_view(data, 1);
	}
    else if (key == L_ARROW || key == R_ARROW)
		view(key, data);
	else if (key == P)
		printf("dir=%f\np_x=%f\np_y=%f\nround_p_x=%f\nround_p_y=%f$\ndir_x=%f\ndir_y=%f_______\n", data->game.dir, data->game.p_x, data->game.p_y, round(data->game.p_x), round(data->game.p_y), data->game.dir_x, data->game.dir_y);
    if (key == ESC)
        clean_exit(data);
    return (0);
}
