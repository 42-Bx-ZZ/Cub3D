/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quality_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 09:52:39 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/23 11:51:43 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

size_t	max_height(char **map)
{
	size_t	max;
	size_t	temp;
	int		i;
	int		j;

	i = 0;
	max = 0;
	j = 0;
	while (map[0] && map[0][i])
	{
		temp = 0;
		j = 0;
		while (map[j] && map[j][i] && map[j][i] == '1')
			j++;
		while (map[j] && map[j][i] && map[j++][i] != '1')
			temp++;
		if (temp > max)
			max = temp;
		i++;
	}
	return (max);
}

size_t	max_width(char **map)
{
	size_t	max;
	size_t	temp;
	int		i;
	int		j;

	i = 0;
	max = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			temp = 0;
			while (map[i][j] == '1')
				j++;
			while (map[i][j] && map[i][j++] != '1')
				temp++;
			if (temp > max)
				max = temp;
		}
		i++;
	}
	return (max);
}

size_t	get_max_vue(t_data *data)
{
	size_t	width;
	size_t	height;
	// size_t	diag;
	size_t	max;

	width = max_width(data->map.setup);
	height = max_height(data->map.setup);
	// diag = max_diag(data->map.setup);
	max = 0;
	if (height > width)
		max = height;
	else
		max = width;
	// if (diag > max)
	// 	max = diag;
	return (max);
}
