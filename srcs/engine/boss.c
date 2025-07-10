/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:14:24 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/10 10:14:43 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	swap_frame_boss(t_data *data, int i)
{
	if (data->ennemies[i].alive == 0
		&& data->ennemies[i].f.ptr == data->map.textures.boss[2].ptr)
	{
		data->ennemies[i].f = data->map.textures.boss[0];
		return ;
	}
	data->ennemies[i].last_hit--;
	data->ennemies[i].frame++;
	if (data->ennemies[i].last_hit <= 0
		&& data->ennemies[i].f.ptr == data->map.textures.boss[2].ptr)
		data->ennemies[i].f = data->map.textures.boss[0];
	else if (data->ennemies[i].frame % 10 == 0)
	{
		data->ennemies[i].frame = 0;
		if (data->ennemies[i].f.ptr == data->map.textures.boss[0].ptr)
			data->ennemies[i].f = data->map.textures.boss[1];
		else
			data->ennemies[i].f = data->map.textures.boss[0];
	}
}

int	is_boss(void)
{
	double			tmp;
	unsigned int	nbr;
	int				random_value;
	static int		counter = 0;

	tmp = elapsed_time();
	tmp = ((tmp - (int)tmp) * 100000000);
	nbr = (unsigned long)&tmp;
	counter++;
	random_value = ((int)tmp + nbr + counter * 7) % 10;
	return (random_value == 0);
}
