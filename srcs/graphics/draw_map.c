/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:44:10 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/23 11:50:41 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	put_pixel_img(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	img->data[y * (img->size_line / 4) + x] = color;
}

int	ray_size_check(t_data *data, char **map)
{
	int	mx;
	int	my;

	mx = (int)data->game.rays[0];
	my = (int)data->game.rays[1];
	if (mx < 0 || my < 0 || !map[my] || !map[my][mx] || map[my][mx] == '1')
		return (1);
	return (0);
}

void	draw_view(t_data *data, float fov_deg, int nb_rays, char **map)
{
	float	start_angle;
	float	angle_step;
	float	ray_angle;
	size_t	r;

	angle_step = ((fov_deg * M_PI / 180) / nb_rays);
	start_angle = data->game.dir - (fov_deg * M_PI / 180) / 2.0;
	r = 0;
	while (r < (size_t)nb_rays)
	{
		ray_angle = start_angle + r * angle_step;
		data->game.rays[0] = data->game.p_x;
		data->game.rays[1] = data->game.p_y;
		while (!ray_size_check(data, map))
		{
			data->game.rays[2] = data->game.rays[0];
			data->game.rays[3] = data->game.rays[1];
			data->game.rays[0] += data->quality * cosf(ray_angle);
			data->game.rays[1] += data->quality * sinf(ray_angle);
		}
		raycasting(data, ray_angle, r);
		r++;
	}
}

void	check_pos(t_data *data, char c, int i, int j)
{
	if ((c == 'W' || c == 'N' || c == 'E' || c == 'S')
		&& data->game.p_x == 0 && data->game.p_y == 0)
	{
		data->game.p_x = i + 0.5;
		data->game.p_y = j + 0.5;
		data->game.dir = get_dir(c);
	}
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
		{
			check_pos(data, map[i][j], j, i);
		}
	}
}
