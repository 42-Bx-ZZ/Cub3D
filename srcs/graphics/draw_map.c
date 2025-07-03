/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:43:31 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/03 10:19:30 by lowatell         ###   ########.fr       */
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

static void	draw_square(t_img *img, int x, int y, int color)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	size = 5;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel_img(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

static int	minimap_color(char c)
{
	if (c == 'D')
		return (0x0FF000);
	if (c == 'P')
		return (0xFF0000);
	if (c == '1')
		return (0xFFFFFF);
	return (0);
}

void	print_line(t_data *data, int i, int x, int y)
{
	int		j;
	int		start;
	char	**map;

	map = data->map.setup;
	start = (int)data->game.p_x - 8;
	if (start < 0)
		start = 0;
	j = start;
	while (map[i][j] && j < start + 16)
	{
		if (map[i] && map[i][j] && map[i][j] != 'Z' && map[i][j] != '0')
			draw_square(&data->frame, x + (j - start) * 5,
				y, minimap_color(map[i][j]));
		j++;
	}
}

void	map_on_frame(t_data *data)
{
	char	**map;
	int		i;
	int		end;
	int		y;

	i = (int)data->game.p_y - 8;
	if (i < 0)
		i = 0;
	end = i + 16;
	y = 20;
	map = data->map.setup;
	while (map[i] && i < end)
	{
		print_line(data, i, 20, y);
		y += 5;
		i++;
	}
}
