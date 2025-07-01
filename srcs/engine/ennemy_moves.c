/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 03:34:40 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/01 10:37:43 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	swap_frame(t_data *data)
{
	t_img	f;
	t_img	f_f;

	data->map.textures.frame++;
	if (data->map.textures.frame >= 15)
	{
		f = data->map.textures.ennemy[0];
		f_f = data->map.textures.ennemy[1];
		data->map.textures.ennemy[1] = f;
		data->map.textures.ennemy[0] = f_f;
		data->map.textures.frame = 0;
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
		swap_frame(data);
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
	while (i < ENNEMY_NBR)
	{
		if (data->ennemies[i].alive)
			move_ennemy(data, i);
		i++;
	}
}
