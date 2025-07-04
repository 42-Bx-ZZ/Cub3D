/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 03:34:40 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/04 09:06:09 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	swap_frame(t_data *data, int i)
{
	if (data->ennemies[i].alive == 0
		&& data->ennemies[i].f.ptr == data->map.textures.ennemy[2].ptr)
	{
		data->ennemies[i].f = data->map.textures.ennemy[0];
		return ;
	}
	data->ennemies[i].last_hit--;
	data->ennemies[i].frame++;
	if (data->ennemies[i].last_hit <= 0
		&& data->ennemies[i].f.ptr == data->map.textures.ennemy[2].ptr)
		data->ennemies[i].f = data->map.textures.ennemy[0];
	else if (data->ennemies[i].frame % 30 == 0)
	{
		data->ennemies[i].frame = 0;
		if (data->ennemies[i].f.ptr == data->map.textures.ennemy[0].ptr)
			data->ennemies[i].f = data->map.textures.ennemy[1];
		else
			data->ennemies[i].f = data->map.textures.ennemy[0];
	}
}

void	move_ennemy(t_data *data, int i)
{
	float	dx;
	float	dy;

	dx = data->game.p_x - data->ennemies[i].x;
	dy = data->game.p_y - data->ennemies[i].y;
	data->ennemies[i].dir = atan2f(dy, dx);
	dx = data->ennemies[i].x + cosf(data->ennemies[i].dir) * 0.04;
	dy = data->ennemies[i].y + sinf(data->ennemies[i].dir) * 0.04;
	if (!is_blocked(data, dx, dy, HITBOX))
	{
		data->ennemies[i].x = dx;
		data->ennemies[i].y = dy;
		swap_frame(data, i);
	}
	else
	{
		if (!is_blocked(data, dx, data->ennemies[i].y, HITBOX))
			data->ennemies[i].x = dx;
		if (!is_blocked(data, data->ennemies[i].x, dy, HITBOX))
			data->ennemies[i].y = dy;
	}
}

void	ennemy_moves(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->gameplay.z_count)
	{
		if (data->ennemies[i].alive)
			move_ennemy(data, i);
		i++;
	}
}
