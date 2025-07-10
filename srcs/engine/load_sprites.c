/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:45:18 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/10 10:30:20 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	load_xpm(t_img *img, char *file, t_data *data)
{
	if (!file)
		return (1);
	img->ptr = mlx_xpm_file_to_image(data->mlx, file,
			&img->width, &img->height);
	if (!img->ptr)
		return (1);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bpp,
			&img->size_line, &img->endian);
	if (!img->data)
		return (1);
	img->w_width = data->width;
	img->w_height = data->height;
	return (0);
}

int	load_guns(t_data *data)
{
	if (load_xpm(&data->player.laser.idle, "textures/laser_idle.xpm", data))
		return (1);
	if (load_xpm(&data->player.gun.idle, "textures/gun_idle.xpm", data))
		return (1);
	if (load_xpm(&data->player.gun.firing, "textures/gun_shot.xpm", data))
		return (1);
	if (load_xpm(&data->player.laser.firing, "textures/laser_shot.xpm", data))
		return (1);
	if (load_xpm(&data->player.gun.moving, "textures/gun_move.xpm", data))
		return (1);
	if (load_xpm(&data->player.laser.moving, "textures/laser_move.xpm", data))
		return (1);
	data->player.gun.power = 1;
	data->player.laser.power = 2;
	return (0);
}

int	load_items(t_data *data)
{
	t_textures	*t;

	t = &data->map.textures;
	if (load_xpm(&t->ennemy[0], data->map.textures.z_idle, data))
		return (1);
	if (load_xpm(&t->ennemy[1], data->map.textures.z_move, data))
		return (1);
	if (load_xpm(&t->ennemy[2], data->map.textures.z_hit, data))
		return (1);
	if (load_xpm(&t->boss[0], data->map.textures.boss_idle, data))
		return (1);
	if (load_xpm(&t->boss[1], data->map.textures.boss_move, data))
		return (1);
	if (load_xpm(&t->boss[2], data->map.textures.boss_idle, data))
		return (1);
	if (load_guns(data))
		return (1);
	return (0);
}

int	load_sprites(t_data *data)
{
	t_textures	*t;

	t = &data->map.textures;
	if (load_xpm(&t->north, data->map.textures.north_path, data))
		return (ft_printf("%s\n", data->map.textures.north_path), 1);
	if (load_xpm(&t->south, data->map.textures.south_path, data))
		return (ft_printf("%s\n", data->map.textures.south_path), 1);
	if (load_xpm(&t->east, data->map.textures.east_path, data))
		return (ft_printf("%s\n", data->map.textures.east_path), 1);
	if (load_xpm(&t->west, data->map.textures.west_path, data))
		return (ft_printf("%s\n", data->map.textures.west_path), 1);
	if (load_xpm(&t->door, data->map.textures.door_path, data))
		return (ft_printf("%s\n", data->map.textures.door_path), 1);
	if (load_items(data))
		return (1);
	data->map.textures.frame = 0;
	data->frame.w_height = data->height;
	data->frame.w_width = data->width;
	draw_map(data);
	return (0);
}
