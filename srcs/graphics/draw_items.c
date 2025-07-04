/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:56:38 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/04 08:53:28 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_items(t_data *data)
{
	int	i;

	i = 0;
	sort_ennemies(data);
	while (i < data->gameplay.z_count)
	{
		if (data->ennemies[i].alive)
			draw_enemy(data, i);
		i++;
	}
	draw_crosshair(data);
	map_on_frame(data);
}
