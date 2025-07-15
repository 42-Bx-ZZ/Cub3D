/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:12:55 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/15 10:39:21 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	back_tracking(t_data *data, char **map, int y, int x)
{
	if (!map[y][x - 1] || !map[y - 1] || !map[y + 1] || !map[y][x + 1]
		|| map[y][x - 1] == ' ' || map[y][x + 1] == ' '
		|| map[y - 1][x] == ' ' || map[y + 1][x] == ' ')
	{
		ft_free_tab(map);
		free_all_and_print_exit(data,
			"Error\nMap must be surrounded by walls\n");
	}
	map[y][x] = 'G';
	if (map[y + 1][x] != 'G' && map[y + 1][x] != '1')
		back_tracking(data, map, y + 1, x);
	if (map[y - 1][x] != 'G' && map[y - 1][x] != '1')
		back_tracking(data, map, y - 1, x);
	if (map[y][x + 1] != 'G' && map[y][x + 1] != '1')
		back_tracking(data, map, y, x + 1);
	if (map[y][x - 1] != 'G' && map[y][x - 1] != '1')
		back_tracking(data, map, y, x - 1);
}

// static void	check_after_back(t_data *data, char **map)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (y < data->map.len)
// 	{
// 		x = 0;
// 		while (map[y][x])
// 		{
// 			if (map[y][x] == 'N' || map[y][x] == 'S'
// 					|| map[y][x] == 'E' || map[y][x] == 'W' || map[y][x] == 'Z')
// 				free_all_and_print_exit(data,
// 					"Error\nFinish the game are not possible\n");
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	check_if_finishable(t_data *data)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (data->map.len + 1));
	if (!map)
		free_all_and_print_exit(data, "Error\nMalloc failed\n");
	i = 0;
	while (data->map.setup[i])
	{
		map[i] = ft_strdup(data->map.setup[i]);
		if (!map[i])
		{
			ft_free_tab(map);
			free_all_and_print_exit(data, "Error\nMalloc failed\n");
		}
		i++;
	}
	map[i] = NULL;
	back_tracking(data, map, data->map.y_player, data->map.x_player);
	//check_after_back(data, map);
	ft_free_tab(map);
}
