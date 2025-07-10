/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 23:49:40 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/10 11:38:09 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	free_all_txt_struct(t_data *data)
{
	if (data->map.textures.door_path)
		free(data->map.textures.door_path);
	if (data->map.textures.z_hit)
		free(data->map.textures.z_hit);
	if (data->map.textures.z_idle)
		free(data->map.textures.z_idle);
	if (data->map.textures.z_move)
		free(data->map.textures.z_move);
	if (data->map.textures.boss_idle)
		free(data->map.textures.boss_idle);
	if (data->map.textures.boss_move)
		free(data->map.textures.boss_move);
	if (data->map.textures.north_path)
		free(data->map.textures.north_path);
	if (data->map.textures.south_path)
		free(data->map.textures.south_path);
	if (data->map.textures.east_path)
		free(data->map.textures.east_path);
	if (data->map.textures.west_path)
		free(data->map.textures.west_path);
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
