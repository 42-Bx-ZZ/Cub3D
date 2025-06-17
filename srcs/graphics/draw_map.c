/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:44:10 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/17 20:24:34 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ray_size_check(float rays[2], char **map)
{            
	int mx;
    int my;
    
	mx = (int)rays[0];
	my = (int)rays[1];
	if (mx < 0 || my < 0 || !map[my] || !map[my][mx] || map[my][mx] == '1')
		return (1);
	return (0);
}

void	draw_view(t_data *data, float fov_deg, int nb_rays, char **map)
{
    float	start_angle;
    float	angle_step;
	float 	ray_angle;
	float 	rays[2];
	int		r;
	
	angle_step = (fov_deg * M_PI / 180) / nb_rays;
	start_angle = data->game.dir - (fov_deg * M_PI / 180) / 2.0;
	r = -1;
    while (++r < nb_rays)
    {
        ray_angle = start_angle + r * angle_step;
        rays[0] = data->game.p_x;
		rays[1] = data->game.p_y;
        while (!ray_size_check(rays, map))
        {
            rays[0] += 0.01 * cos(ray_angle);
            rays[1] += 0.01 * sin(ray_angle);
        }
		raycasting(data, ray_angle, rays, r);
    }
}

void	put_pixel(t_data *data, char c, int i, int j)
{
	// if (c == '1')
	// 	mlx_put_image_to_window(data->mlx, data->win,
	// 		data->map.textures.m_wall.ptr,
	// 		i * data->map.textures.m_wall.width,
	// 		j * data->map.textures.m_wall.height);
	// if (c == '0')
	// 	mlx_put_image_to_window(data->mlx, data->win,
	// 		data->map.textures.m_floor.ptr,
	// 		i * data->map.textures.m_floor.width,
	// 		j * data->map.textures.m_floor.height);
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
	{
		data->game.p_x = i;
		data->game.p_y = j;
		data->game.dir = get_dir(c);
		// mlx_put_image_to_window(data->mlx, data->win,
		// 	data->map.textures.m_floor.ptr,
		// 	i * data->map.textures.m_floor.width,
		// 	j * data->map.textures.m_floor.height);
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
