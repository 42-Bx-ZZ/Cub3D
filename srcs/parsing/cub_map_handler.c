/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:02:55 by zaiicko           #+#    #+#             */
/*   Updated: 2025/05/18 01:36:58 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	check_and_parse_cub_file(t_data *data)
{
	int	i;

	i = 0;
	while (data->cub_file[i])
	{
		if (ft_strncmp(data->cub_file[i], "NO ", 3) == 0)
			check_and_parse_wall_path(data, data->cub_file[i], "NO");
		else if (ft_strncmp(data->cub_file[i], "SO ", 3) == 0)
			check_and_parse_wall_path(data, data->cub_file[i], "SO");
		else if (ft_strncmp(data->cub_file[i], "WE ", 3) == 0)
			check_and_parse_wall_path(data, data->cub_file[i], "WE");
		else if (ft_strncmp(data->cub_file[i], "EA ", 3) == 0)
			check_and_parse_wall_path(data, data->cub_file[i], "EA");
		else if (data->cub_file[i][0] != '\0')
			free_all_and_print_exit(data, "Error\nWrong data in cub file");
		i++;
	}
}
