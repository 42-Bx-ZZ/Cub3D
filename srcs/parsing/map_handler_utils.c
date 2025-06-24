/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 03:41:56 by zaiicko           #+#    #+#             */
/*   Updated: 2025/06/24 19:46:21 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	check_empty_line_case(t_data *data, int i, int j)
{
	j = i;
	while (j < data->cub_len)
	{
		if (data->cub_file[j][0] != 0)
		{
			if (check_chars_in_string(VALID_CHARS, data->cub_file[j]))
			{
				free_all_and_print_exit(data,
					"Error\nThe map need to be in one part\n");
			}
			free_all_and_print_exit(data,
				"Error\nThe map aren't last in cub_file\n");
		}
		j++;
	}
}

static int	count_and_check(t_data *data, int i, int j, int len)
{
	while (data->cub_file[i])
	{
		if (data->cub_file[i][0])
		{
			i++;
			len++;
		}
		else if (data->cub_file[i][0] == 0)
			check_empty_line_case(data, i, j);
	}
	return (len);
}

int	count_map_lenght(t_data *data, int i)
{
	int	len;
	int	j;

	len = 0;
	j = 0;
	len = count_and_check(data, i, j, len);
	return (len);
}

void	check_if_all_cub_data(t_data *data)
{
	if (!data->map.textures.east_path || !data->map.textures.west_path
		|| !data->map.textures.south_path || !data->map.textures.north_path
		|| data->map.textures.c_flag == 0 || data->map.textures.f_flag == 0
		|| !data->map.setup || !data->map.textures.door_path)
		free_all_and_print_exit(data,
			"Error\nLack of data required in cub_file\n");
}
