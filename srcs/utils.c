/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:41:36 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/09 23:57:57 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	count_z(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'Z')
				data->map.z++;
			j++;
		}
		i++;
	}
}

int	ft_tablen(char **map)
{
	int	i;

	if (!map || !*map)
		return (0);
	i = 0;
	while (map[i])
		i++;
	return (i);
}

double	elapsed_time(void)
{
	static struct timeval	last;
	struct timeval			now;
	double					time;

	last.tv_usec = 0;
	last.tv_sec = 0;
	gettimeofday(&now, NULL);
	time = (now.tv_sec - last.tv_sec) + (now.tv_usec - last.tv_usec) / 1e9;
	last = now;
	return (time);
}
