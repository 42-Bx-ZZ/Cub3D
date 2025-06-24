/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:23:18 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/24 18:47:36 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	view(int key, t_data *data)
{
	if (key != R_ARROW && key != L_ARROW)
		return ;
	if (key == R_ARROW)
		data->game.dir += VIEW;
	if (key == L_ARROW)
		data->game.dir -= VIEW;
}

int	update_move(t_data *data)
{
	if (data->keys.up)
		moves(UP, data);
	if (data->keys.down)
		moves(DOWN, data);
	if (data->keys.left)
		moves(LEFT, data);
	if (data->keys.right)
		moves(RIGHT, data);
	if (data->keys.l_arrow)
		view(L_ARROW, data);
	if (data->keys.r_arrow)
		view(R_ARROW, data);
	if (data->keys.e)
		door_check(data);
	data->frame.ptr = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->frame.data = (int *)mlx_get_data_addr(data->frame.ptr,
			&data->frame.bpp, &data->frame.size_line, &data->frame.endian);
	ray_size(data, FOV, RAYS, data->map.setup);
	mlx_put_image_to_window(data->mlx, data->win, data->frame.ptr, 0, 0);
	mlx_destroy_image(data->mlx, data->frame.ptr);
	data->frame.ptr = NULL;
	data->fps.fps++;
	print_infos(data);
	return (0);
}
