/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:43:31 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/01 14:39:44 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	put_pixel_map(t_img *img, float y, float x, int color)
{
	int	j;
	int	i;
	int	scale;

	scale = 5;
	i = 0;
	while (i < scale)
	{
		j = 0;
		while (j < scale)
		{
			if (x + j >= 0 && x + j < img->w_width
				&& y + i >= 0 && y + i < img->w_height)
				put_pixel_img(img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	map_on_frame(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = data->map.setup;
	while (map[i] && (20 + i * 5 + 5) < data->height / 4)
	{
		j = 0;
		while (map[i][j] && (20 + j * 5 + 5) < data->width / 4)
		{
			if (map[i][j] == '1')
				put_pixel_map(&data->frame, 20 + i * 5, 20 + j * 5, 0x000000);
			else if (map[i][j] == '0' || map[i][j] == 'Z')
				put_pixel_map(&data->frame, 20 + i * 5, 20 + j * 5, 0xFFFFFF);
			else if (map[i][j] == 'P')
				put_pixel_map(&data->frame, 20 + i * 5, 20 + j * 5, 0xFF0000);
			else if (map[i][j] == 'D')
				put_pixel_map(&data->frame, 20 + i * 5, 20 + j * 5, 0x0FF000);
			j++;
		}
		i++;
	}
}
