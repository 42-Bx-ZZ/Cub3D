/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:41:36 by zaiicko           #+#    #+#             */
/*   Updated: 2025/06/26 19:37:04 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_all_data(t_data *data)
{
	if (data->cub_file)
		ft_free_tab(data->cub_file);
	if (data->map.setup_without_sp)
		ft_free_tab(data->map.setup_without_sp);
	if (data->map.setup)
		ft_free_tab(data->map.setup);
}

void	free_all_and_print_exit(t_data *data, char *msg)
{
	free_all_data(data);
	ft_print_exit(msg);
}
