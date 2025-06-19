/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:09:13 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/19 17:58:09 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	moves(int key, t_data *data)
{
	float	t_step;

	t_step = STEP;
	if ((data->keys.up && (data->keys.right || data->keys.left))
		|| (data->keys.down && (data->keys.right || data->keys.left)))
		t_step = STEP * 0.60;
	if (data->game.p_x > 0 && data->game.p_y > 0 && data->map.setup[(int)data->game.p_y][(int)data->game.p_x])
	{
		if (key == UP && data->map.setup[(int)(data->game.p_y + (sin(data->game.dir) * STEP))][(int)(data->game.p_x + (cos(data->game.dir) * STEP))] != '1')
		{
			data->game.p_x += cos(data->game.dir) * t_step;
			data->game.p_y += sin(data->game.dir) * t_step;
		}
		if (key == DOWN && data->map.setup[(int)(data->game.p_y - (sin(data->game.dir) * STEP))][(int)(data->game.p_x - (cos(data->game.dir) * STEP))] != '1')
		{
			data->game.p_x -= cos(data->game.dir) * t_step;
			data->game.p_y -= sin(data->game.dir) * t_step;
		}
	 	if (key == LEFT && data->map.setup[(int)(data->game.p_y - (cos(data->game.dir + M_PI_2) * STEP))][(int)(data->game.p_x - (sin(data->game.dir + M_PI_2) * STEP))] != '1')
		{
			data->game.p_x -= cos(data->game.dir + M_PI_2) * t_step;
			data->game.p_y -= sin(data->game.dir + M_PI_2) * t_step;
		}
		if (key == RIGHT && data->map.setup[(int)(data->game.p_y + (cos(data->game.dir + M_PI_2) * STEP))][(int)(data->game.p_x + (sin(data->game.dir + M_PI_2) * STEP))] != '1')
		{
			data->game.p_x += cos(data->game.dir + M_PI_2) * t_step;
			data->game.p_y += sin(data->game.dir + M_PI_2) * t_step;
		}
		t_step = STEP;
	}
}

