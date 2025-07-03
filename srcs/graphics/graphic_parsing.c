/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:44:10 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/03 09:48:53 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	put_pixel_img(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= img->w_width || y < 0 || y >= img->w_height)
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

void	update_frame(t_data *data, float fov_deg, int nb_rays, char **map)
{
	float	start_angle;
	float	angle_step;
	float	ray_angle;
	size_t	r;

	angle_step = ((fov_deg * M_PI / 180) / nb_rays);
	start_angle = data->game.dir - (fov_deg * M_PI / 180) / 2.0;
	r = 0;
	data->game.dda.zbuffer = (float *)malloc(sizeof(float) * data->width);
	if (!data->game.dda.zbuffer)
		clean_exit(data);
	while (r < (size_t)nb_rays)
	{
		ray_angle = start_angle + r * angle_step;
		dda(data, ray_angle, map);
		data->game.dda.zbuffer[r] = data->game.perp_wall;
		raycasting(data, r);
		r++;
	}
	draw_items(data);
	free(data->game.dda.zbuffer);
	ennemy_moves(data);
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
	if (c == 'Z' && data->gameplay.z_count < ENNEMY_NBR
		&& SPAWN == 1 && data->gameplay.z_count < data->map.z)
	{
		data->ennemies[data->gameplay.z_count].x_start = i;
		data->ennemies[data->gameplay.z_count].y_start = j;
		data->ennemies[data->gameplay.z_count].alive = check_around_z(data, i, j);
		data->ennemies[data->gameplay.z_count].x = i + 0.5;
		data->ennemies[data->gameplay.z_count].y = j + 0.5;
		data->ennemies[data->gameplay.z_count].hp = ENNEMY_HP;
		data->gameplay.z_count++;
	}
}

void	draw_map(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	map = data->map.setup;
	count_z(map, data);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			check_pos(data, map[i][j], j, i);
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'E'
				|| map[i][j] == 'S' || map[i][j] == 'N')
				map[i][j] = 'P';
		}
	}
}
