/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 08:30:43 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/01 17:09:06 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	argb_colors(int a, int rgb[3])
{
	return ((a << 24) | (rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}


int	color_shaders(int color, t_data *data)
{
	float	factor;
	int		rgb[3];
	float	max_dist;
	float	min_bright;

	max_dist = 7.0f;
	min_bright = 0.1f;
	if (data->game.perp_wall >= max_dist)
		factor = min_bright;
	else
		factor = 1.0f - ((data->game.perp_wall / max_dist) * (1.0f - min_bright));
	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = color & 0xFF;
	rgb[0] = (int)(rgb[0] * factor);
	rgb[1] = (int)(rgb[1] * factor);
	rgb[2] = (int)(rgb[2] * factor);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}
