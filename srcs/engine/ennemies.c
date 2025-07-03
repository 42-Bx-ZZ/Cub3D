/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 08:47:20 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/03 18:42:49 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	hit_ennemy(t_data *data, int i)
{
	data->ennemies[i].hp--;
	if (data->ennemies[i].hp <= 0)
	{
		data->ennemies[i].alive = 0;
		//earn_money(data, 1); // 1 for kill
	}
	else
	{
		data->ennemies[i].last_hit = 20;
		data->ennemies[i].frame = 0;
		data->ennemies[i].f = data->map.textures.ennemy[2];
		// 	earn_money(data, 0);
	}
}

int	check_spawn(t_data *data, int x, int y)
{
	char	**map;

	map = data->map.setup;
	if (map[x] && map[x + 1] && map[x][y] && map[x + 1][y])
		if (map[x + 1][y] == '0')
			return (1);
	if (x > 0 && map[x] && map[x - 1] && map[x][y] && map[x - 1][y])
		if (map[x - 1][y] == '0')
			return (1);
	if (map[x] && map[x][y] && map[x][y + 1])
		if (map[x][y + 1] == '0')
			return (1);
	if (y > 0 && map[x] && map[x][y] && map[x][y - 1])
		if (map[x][y - 1] == '0')
			return (1);
	return (0);
}

int	ennemies_wiped(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->gameplay.z_count)
	{
		if (data->ennemies[i].alive == 0)
			i++;
		else
			return (0);
	}
	return (1);
}

void	revive_ennemies(t_data *data)
{
	int	i;

	i = 0;
	if (!ennemies_wiped(data))
		return ;
	data->gameplay.ennemy_hp *= 2;
	printf("%d\n", data->gameplay.ennemy_hp);
	while (i < data->gameplay.z_count)
	{
		data->ennemies[i].x = data->ennemies[i].x_start;
		data->ennemies[i].y = data->ennemies[i].y_start;
		data->ennemies[i].alive = check_spawn(data,
				data->ennemies[i].x_start, data->ennemies[i].y_start);
		data->ennemies[i].hp = data->gameplay.ennemy_hp;
		i++;
	}
	data->gameplay.round++;
}
