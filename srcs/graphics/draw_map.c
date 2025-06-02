/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:44:10 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/02 16:50:25 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	put_pixel(t_data *data, char c, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->map.textures.m_wall.ptr, i * data->map.textures.m_wall.width, j * data->map.textures.m_wall.height);
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->map.textures.m_floor.ptr, i * data->map.textures.m_floor.width, j * data->map.textures.m_floor.height);
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
		mlx_put_image_to_window(data->mlx, data->win, data->map.textures.m_player.ptr, i * data->map.textures.m_player.width, j * data->map.textures.m_player.height);
}

void	draw_map(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	map = data->map.setup;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			put_pixel(data, map[i][j], j, i);
	}
}