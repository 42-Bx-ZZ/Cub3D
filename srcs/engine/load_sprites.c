/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:45:18 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/23 13:58:10 by lowatell         ###   ########.fr       */
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
	draw_map(data);
	return (0);
}
