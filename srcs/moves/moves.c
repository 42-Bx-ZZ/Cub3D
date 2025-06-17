/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:09:13 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/17 19:43:35 by lowatell         ###   ########.fr       */
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

