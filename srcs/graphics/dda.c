/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:26:21 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/25 02:35:34 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_dda(t_data *data, float ray_angle, t_dda *dda)
{
	dda->ray_dir_x = cosf(ray_angle);
	dda->ray_dir_y = sinf(ray_angle);
	dda->x = (int)data->game.p_x;
	dda->y = (int)data->game.p_y;
	dda->delta_dist_x = fabs(1.0f / dda->ray_dir_x);
	dda->delta_dist_y = fabs(1.0f / dda->ray_dir_y);
	dda->step_x = get_dda_step(dda->ray_dir_x);
	dda->step_y = get_dda_step(dda->ray_dir_y);
	if (dda->ray_dir_x < 0)
		dda->side_dist_x = (data->game.p_x - dda->x) * dda->delta_dist_x;
	else
		dda->side_dist_x = (dda->x + 1.0f - data->game.p_x) * dda->delta_dist_x;
	if (dda->ray_dir_y < 0)
		dda->side_dist_y = (data->game.p_y - dda->y) * dda->delta_dist_y;
	else
		dda->side_dist_y = (dda->y + 1.0f - data->game.p_y) * dda->delta_dist_y;
}

void	dda_step(t_dda *dda)
{
	if (dda->side_dist_x < dda->side_dist_y)
	{
		dda->side_dist_x += dda->delta_dist_x;
		dda->x += dda->step_x;
		dda->side = 0;
	}
	else
	{
		dda->side_dist_y += dda->delta_dist_y;
		dda->y += dda->step_y;
		dda->side = 1;
	}
}

int	hit_wall(char **map, t_dda *dda)
{
	if (map[dda->y] && map[dda->y][dda->x] == 'E')
		dda->hit_ennemy = 1;
	return (map[dda->y] && map[dda->y][dda->x] && (map[dda->y][dda->x] == '1'
		|| map[dda->y][dda->x] == 'D'));
}

void	set_hit(t_data *data, t_dda *dda, float ray_angle)
{
	float	perp_wall;
	float	angle;

	if (dda->side == 0)
		perp_wall = (dda->x - data->game.p_x
				+ (1 - dda->step_x) / 2) / dda->ray_dir_x;
	else
		perp_wall = (dda->y - data->game.p_y
				+ (1 - dda->step_y) / 2) / dda->ray_dir_y;
	data->game.rays[0] = data->game.p_x + perp_wall * dda->ray_dir_x;
	data->game.rays[1] = data->game.p_y + perp_wall * dda->ray_dir_y;
	angle = ray_angle - data->game.dir;
	perp_wall = perp_wall * cosf(angle);
	data->game.r_x_fy = data->game.p_x + perp_wall * dda->ray_dir_x;
	data->game.r_y_fy = data->game.p_y + perp_wall * dda->ray_dir_y;
	data->game.perp_wall = perp_wall;
}

void	dda(t_data *data, float ray_angle, char **map)
{
	init_dda(data, ray_angle, &data->game.dda);
	while (!hit_wall(map, &data->game.dda))
		dda_step(&data->game.dda);
	set_hit(data, &data->game.dda, ray_angle);
}
