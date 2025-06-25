/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:41:36 by zaiicko           #+#    #+#             */
/*   Updated: 2025/06/25 12:36:34 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	static struct timespec	last;
	struct timespec			now;
	double					time;

	last.tv_nsec = 0;
	last.tv_sec = 0;
	clock_gettime(CLOCK_MONOTONIC, &now);
	time = (now.tv_sec - last.tv_sec) + (now.tv_nsec - last.tv_nsec) / 1e9;
	last = now;
	return (time);
}

void	free_all_data(t_data *data)
{
	if (data->cub_file)
		ft_free_tab(data->cub_file);
}

void	free_all_and_print_exit(t_data *data, char *msg)
{
	free_all_data(data);
	ft_print_exit(msg);
}
