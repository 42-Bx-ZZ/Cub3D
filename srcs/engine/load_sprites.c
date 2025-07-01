/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:45:18 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/01 17:20:17 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	check_dist(t_data *data, int i)
{
	while (i < ENNEMY_NBR)
	{
		if (data->ennemies[i].alive)
		{
			data->ennemies[i].dist = sqrtf(powf(data->ennemies[i].x
						- data->game.p_x, 2)
					+ powf(data->ennemies[i].y - data->game.p_y, 2));
		}
		else
			data->ennemies[i].dist = 999999.0f;
		i++;
	}
}

void	sort_ennemies(t_data *data)
{
	int			i;
	t_ennemy	tmp;
	t_ennemy	tmp_t;

	i = 0;
	if (data->ennemies_number == 0 || data->ennemies_number == 1)
		return ;
	check_dist(data, i);
	while (i < ENNEMY_NBR - 1)
	{
		if (data->ennemies[i].dist < data->ennemies[i + 1].dist)
		{
			tmp = data->ennemies[i];
			tmp_t = data->ennemies[i + 1];
			data->ennemies[i] = tmp_t;
			data->ennemies[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
}

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

// int	load_png(t_img *img, char *file, t_data *data)
// {
// 	if (!file)
// 		return (1);
// 	img->ptr = mlx_png_file_to_image(data->mlx,
// 		file, &img->width, &img->height);
// 	if (!img->ptr)
// 		return (1);
// 	img->data = (int *)mlx_get_data_addr(img->ptr,
// 		&img->bpp, &img->size_line, &img->endian);
// 	if (!img->data)
// 		return (1);
// 	return (0);
// }

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
	if (load_xpm(&t->ennemy[0], "textures/goomba.xpm", data))
		return (1);
	if (load_xpm(&t->ennemy[1], "textures/goomba_2.xpm", data))
		return (1);
	data->map.textures.frame = 0;
	data->frame.w_height = data->height;
	data->frame.w_width = data->width;
	draw_map(data);
	return (0);
}
