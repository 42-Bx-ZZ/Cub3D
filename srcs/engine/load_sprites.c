/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:45:18 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/09 00:29:45 by lowatell         ###   ########.fr       */
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
	if (load_xpm(&t->ennemy[0], "textures/zombie_move.xpm", data))
		return (1);
	if (load_xpm(&t->ennemy[1], "textures/zombie_move_2.xpm", data))
		return (1);
	if (load_xpm(&t->ennemy[2], "textures/zombie_hit.xpm", data))
		return (1);
	if (load_guns(data))
		return (1);
	return (0);
}

int	load_sprites(t_data *data)
{
	t_textures	*t;

	t = &data->map.textures;
	if (load_xpm(&t->north, "textures/wall_1.xpm", data))
		return (1);
	if (load_xpm(&t->south, "textures/wall_2.xpm", data))
		return (1);
	if (load_xpm(&t->east, "textures/wall_3.xpm", data))
		return (1);
	if (load_xpm(&t->west, "textures/wall_4.xpm", data))
		return (1);
	if (load_xpm(&t->door, "textures/door.xpm", data))
		return (1);
	if (load_items(data))
		return (1);
	data->map.textures.frame = 0;
	data->frame.w_height = data->height;
	data->frame.w_width = data->width;
	draw_map(data);
	return (0);
}
