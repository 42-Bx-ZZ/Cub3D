/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:35:36 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/25 01:46:50 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	open_door(t_data *data)
{
	int		x;
	int		y;
	char	**map;

	x = data->game.p_x;
	y = data->game.p_y;
	map = data->map.setup;
	if (map[y][x] && map[y + 1] && map[y + 1][x] && map[y + 1][x] == 'D'
		&& data->keys.e && data->player.money >= 500)
		return (map[y + 1][x] = '0', 500);
	if (map[y][x] && map[y - 1] && map[y - 1][x] && map[y - 1][x] == 'D'
		&& data->keys.e && data->player.money >= 500)
		return (map[y - 1][x] = '0', 500);
	if (map[y][x] && map[y][x + 1] && map[y][x + 1] && map[y][x + 1] == 'D'
		&& data->keys.e && data->player.money >= 500)
		return (map[y][x + 1] = '0', 500);
	if (map[y][x] && map[y][x - 1] && map[y][x - 1] && map[y][x - 1] == 'D'
		&& data->keys.e && data->player.money >= 500)
		return (map[y][x - 1] = '0', 500);
	return (0);
}

void	door_check(t_data *data)
{
	int	temp;

	temp = data->player.money;
	if (data->player.money >= 500 && data->keys.e)
		data->player.money -= open_door(data);
	if (temp != data->player.money)
		printf("Your new sold is: %d\n", data->player.money);
}
