/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 08:30:43 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/29 08:46:03 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	argb_colors(int a, int rgb[3])
{
	return ((a << 24) | (rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int	red_filter(int color, t_data *data)
{
	int		a;
	int		r;
	int		g;
	int		b;
	float	factor;

	if (data->player.hp == 3)
		return (color);
	factor = 1.0f - ((float)(data->player.hp - 1) / 2.0f);
	a = ((color >> 24) & 0xFF);
	r = ((color >> 16) & 0xFF);
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = (int)(r + (255 - r) * factor);
	if (r > 255)
		r = 255;
	g = (int)(g * (1.0f - 0.7f * factor));
	if (g < 0)
		g = 0;
	b = (int)(b * (1.0f - 0.7f * factor));
	if (b < 0)
		b = 0;
	return ((a << 24) | (r << 16) | (g << 8) | b);
}

// int	shaders(int color, float dist)
// {
// 	return (0);
// }
