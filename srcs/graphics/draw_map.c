/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:44:10 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/16 22:43:06 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

float	get_dir(char c)
{
	if (c == 'N')
		return (4.71);
	if (c == 'S')
		return (1.57);
	if (c == 'W')
		return (3.14);
	return (0);
}

void	draw_fov_view(t_data *data, float fov_deg, int nb_rays, int i)
{
    float	px = data->game.p_x;
    float	py = data->game.p_y;
    char	**map = data->map.setup;
    float	fov = fov_deg * M_PI / 180;
    float	start_angle = data->game.dir - fov / 2.0;
    float	angle_step = fov / nb_rays;

    for (int r = 0; r < nb_rays; r++)
    {
        float ray_angle = start_angle + r * angle_step;
        float ray_x = px, ray_y = py;
        while (1)
        {
            int mx = (int)ray_x;
            int my = (int)ray_y;
            if (mx < 0 || my < 0 || !map[my] || !map[my][mx] || map[my][mx] == '1')
                break;
			if (i == 1)
				mlx_pixel_put(data->mlx, data->win,
					ray_x * data->map.textures.m_wall.width,
					ray_y * data->map.textures.m_wall.height,
					0xFFFF00);
			else
				mlx_pixel_put(data->mlx, data->win,
					ray_x * data->map.textures.m_wall.width,
					ray_y * data->map.textures.m_wall.height,
					0x000000);
            ray_x += 0.05 * cos(ray_angle);
            ray_y += 0.05 * sin(ray_angle);
        }
    }
}

void	draw_view(t_data *data, int i)
{
	draw_fov_view(data, 60, 120, i);
}

void	put_pixel(t_data *data, char c, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->map.textures.m_wall.ptr, i * data->map.textures.m_wall.width,
			j * data->map.textures.m_wall.height);
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->map.textures.m_floor.ptr, i * data->map.textures.m_floor.width,
			j * data->map.textures.m_floor.height);
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
	{
		data->game.p_x = i;
		data->game.p_y = j;
		data->game.dir = get_dir(c);
		mlx_put_image_to_window(data->mlx, data->win,
			data->map.textures.m_floor.ptr, i * data->map.textures.m_floor.width,
			j * data->map.textures.m_floor.height);
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
			put_pixel(data, map[i][j], j, i);
	}
}
