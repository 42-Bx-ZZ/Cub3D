/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:41:36 by zaiicko           #+#    #+#             */
/*   Updated: 2025/06/23 12:46:46 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	print_fps(t_data *data)
{
	char	*fps;

	fps = ft_itoa(data->fps.fps / (elapsed_time() - data->fps.start));
	if (!fps)
		clean_exit(data);
	mlx_string_put(data->mlx, data->win, WIDTH - 30, 30, 0x000000, fps);
	free(fps);
}

double	elapsed_time()
{
	static struct timespec	last;
	struct	timespec		now;
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
