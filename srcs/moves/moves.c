/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:09:13 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/16 14:03:47 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	moves(int key, t_data *data)
{
	if ((int)data->game.p_x > 0 && (int)data->game.p_y > 0 && data->map.setup[(int)data->game.p_y][(int)data->game.p_x])
	{
		if (key == UP && data->map.setup[(int)round(data->game.p_y - STEP)][(int)data->game.p_x] != '1')
			data->game.p_y -= STEP;
		if (key == DOWN && data->map.setup[(int)round(data->game.p_y + STEP)][(int)data->game.p_x] != '1')
			data->game.p_y += STEP;
	 	if (key == LEFT && data->map.setup[(int)data->game.p_y][(int)round(data->game.p_x - STEP)] != '1')
		 		data->game.p_x -= STEP;
		if (key == RIGHT && data->map.setup[(int)data->game.p_y][(int)round(data->game.p_x + STEP)] != '1')
			data->game.p_x += STEP;
	}
	return ;
}

void	view(int key, t_data *data)
{
	if (key == R_ARROW)
		data->game.dir += 0.2;
	if (key == L_ARROW)
		data->game.dir -= 0.2;
	printf("dir = %f\n", data->game.dir);
	return ;
}

int keys_hook(int key, t_data *data)
{
	draw_view(data, 0);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		moves(key, data);
    else if (key == L_ARROW || key == R_ARROW)
		view(key, data);
	draw_view(data, 1);
    if (key == ESC)
        clean_exit(data);
    return (0);
}
