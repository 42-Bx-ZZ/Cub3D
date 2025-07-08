/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 08:47:20 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/09 00:41:28 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	earn_money(t_data *data, int type)
{
	if (type == 0)
	{
		data->player.money += EARN_HIT;
		data->gameplay.last_earn = EARN_HIT;
		data->player.earn_frames = 20;
	}
	else if (type == 1)
	{
		data->player.money += EARN_KILL;
		data->gameplay.last_earn = EARN_KILL;
		data->player.earn_frames = 20;
	}
}

void	hit_ennemy(t_data *data, int i)
{
	data->player.targeting = 0;
	data->keys.mouse.fire_frames = 20;
	data->keys.mouse.firing = 0;
	data->ennemies[i].hp = data->ennemies[i].hp - data->player.gun.power;
	if (data->ennemies[i].hp <= 0)
	{
		data->ennemies[i].alive = 0;
		earn_money(data, 1);
	}
	else
	{
		data->ennemies[i].last_hit = 20;
		data->ennemies[i].frame = 0;
		data->ennemies[i].f = data->map.textures.ennemy[2];
		earn_money(data, 0);
	}
}

int	check_spawn(t_data *data, int y, int x)
{
	char	**map;

	map = data->map.setup;
	if (check_way(map, x, y, data))
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
	data->gameplay.round++;
	data->gameplay.ennemy_hp = ENNEMY_HP + (data->gameplay.round / 5);
	printf("\n=== ROUND %d ===\n", data->gameplay.round);
	printf("Zombie HP: %d\n", data->gameplay.ennemy_hp);
	while (i < data->gameplay.z_count)
	{
		swap_frame(data, i);
		data->ennemies[i].alive = check_spawn(data,
				data->ennemies[i].x_start, data->ennemies[i].y_start);
		data->ennemies[i].x = data->ennemies[i].x_start + 0.5;
		data->ennemies[i].y = data->ennemies[i].y_start + 0.5;
		data->ennemies[i].hp = data->gameplay.ennemy_hp;
		i++;
	}
}
