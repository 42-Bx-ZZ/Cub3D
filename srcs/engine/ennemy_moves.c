/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 03:34:40 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/25 04:23:11 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	move_ennemy_y(t_data *data, float dy, int i)
{
	char	**map;

	map = data->map.setup;
	if (map[(int)(dy - HITBOX)][(int)(data->ennemies[i].x - HITBOX)] != '1'
		&& map[(int)(dy + HITBOX)][(int)(data->ennemies[i].x - HITBOX)] != '1'
		&& map[(int)(dy - HITBOX)][(int)(data->ennemies[i].x + HITBOX)] != '1'
		&& map[(int)(dy + HITBOX)][(int)(data->ennemies[i].x + HITBOX)] != '1')
		return (1);
	return (0);
}

int	move_ennemy_x(t_data *data, float dx, int i)
{
	char	**map;

	map = data->map.setup;
	if (map[(int)(data->ennemies[i].y - HITBOX)][(int)(dx - HITBOX)] != '1'
		&& map[(int)(data->ennemies[i].y + HITBOX)][(int)(dx - HITBOX)] != '1'
		&& map[(int)(data->ennemies[i].y - HITBOX)][(int)(dx + HITBOX)] != '1'
		&& map[(int)(data->ennemies[i].y + HITBOX)][(int)(dx + HITBOX)] != '1')
		return (1);
	return (0);
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
	if (move_ennemy_x(data, dx, i))
		data->ennemies[i].x = dx;
	if (move_ennemy_y(data, dy, i))
		data->ennemies[i].y = dy;
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
