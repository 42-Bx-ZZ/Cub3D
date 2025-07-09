/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:41:36 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/09 22:48:47 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	free_all_txt_struct(t_data *data)
{
	if (data->map.textures.door_path)
		free(data->map.textures.door_path);
	if (data->map.textures.zback_path)
		free(data->map.textures.zback_path);
	if (data->map.textures.zfront_path)
		free(data->map.textures.zfront_path);
	if (data->map.textures.north_path)
		free(data->map.textures.north_path);
	if (data->map.textures.south_path)
		free(data->map.textures.south_path);
	if (data->map.textures.east_path)
		free(data->map.textures.east_path);
	if (data->map.textures.west_path)
		free(data->map.textures.west_path);
}

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

void	free_all_data(t_data *data)
{
	if (data->cub_file)
		ft_free_tab(data->cub_file);
	if (data->map.setup_without_sp)
		ft_free_tab(data->map.setup_without_sp);
	if (data->map.setup)
		ft_free_tab(data->map.setup);
	free_all_txt_struct(data);
}

void	free_all_and_print_exit(t_data *data, char *msg)
{
	free_all_data(data);
	ft_print_exit(msg);
}
