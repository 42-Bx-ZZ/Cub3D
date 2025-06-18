/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 03:41:56 by zaiicko           #+#    #+#             */
/*   Updated: 2025/06/18 03:42:46 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	count_map_lenght(t_data *data, int i)
{
	int	len;

	len = 0;
	while (data->cub_file[i])
	{
		if (data->cub_file[i][0])
		{
			i++;
			len++;
		}
		else if (data->cub_file[i][0] == 0 && data->cub_file[i + 1])
			free_all_and_print_exit(data,
				"Error\nMap can't be separeted by '\\n'\n");
		else
			break ;
	}
	return (len);
}
