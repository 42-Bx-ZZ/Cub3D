/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:43:31 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/04 09:18:53 by lowatell         ###   ########.fr       */
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

void	draw_minimap_border(t_data *data)
{
	int	x;
	int	y;
	int	size;

	size = 16 * 5;
	x = 20;
	y = 20;
	while (x < 20 + size)
	{
		put_pixel_img(&data->frame, x, y - 1, 0xFF0000);
		put_pixel_img(&data->frame, x, y + size, 0xFF0000);
		x++;
	}
	x = 20;
	while (y < 20 + size)
	{
		put_pixel_img(&data->frame, x - 1, y, 0xFF0000);
		put_pixel_img(&data->frame, x + size, y, 0xFF0000);
		y++;
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
	draw_minimap_border(data);
}
