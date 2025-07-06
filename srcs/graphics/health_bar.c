/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:51:22 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/06 14:19:19 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	bar_color(int hp)
{
	if (hp > 60)
		return (0x00FF00);
	else if (hp > 30)
		return (0xFFFF00);
	else
		return (0xFF0000);
}

int	calculate_health_width(int hp)
{
	int	bar_width;
	int	border_thickness;

	bar_width = 200;
	border_thickness = 2;
	if (hp > 100)
		return (bar_width - 2 * border_thickness);
	else if (hp <= 0)
		return (0);
	else
		return ((hp * (bar_width - 2 * border_thickness)) / 100);
}

void	draw_health_bar(t_data *data)
{
	int		health_width;
	int		x;
	int		y;
	int		bar_x;
	int		bar_y;

	health_width = calculate_health_width(data->player.hp);
	bar_x = data->width / 2 - 110;
	bar_y = data->height - 40;
	y = bar_y;
	while (y < bar_y + 20)
	{
		x = bar_x;
		while (x < bar_x + 200)
		{
			if (x < bar_x + 2 || x >= bar_x + 198
				|| y < bar_y + 2 || y >= bar_y + 18)
				put_pixel_img(&data->frame, x, y, 0xFFFFFF);
			else if (x < bar_x + 2 + health_width)
				put_pixel_img(&data->frame, x, y, bar_color(data->player.hp));
			x++;
		}
		y++;
	}
}
