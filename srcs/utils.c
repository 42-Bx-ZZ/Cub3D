/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:41:36 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/10 19:19:22 by zaiicko          ###   ########.fr       */
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

void	init_game_data(t_data *data)
{
	data->player.money = MONEY;
	data->gameplay.ennemy_hp = ENNEMY_HP;
	data->player.hp = 100;
	if (HEIGHT > 0 && WIDTH > 0)
	{
		data->width = WIDTH;
		data->height = HEIGHT;
	}
	data->player.last_hit = elapsed_time();
}

void	check_args(int ac, char **av)
{
	if (ac == 2 && ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4) == 0)
		return ;
	else
		ft_print_exit("Error\nWrong arguments : ./cub3d <maps/map1.cub>\n");
}
