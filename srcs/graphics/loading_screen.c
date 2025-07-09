/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:13:51 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/09 00:50:10 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	*init_loading_image(t_data *data, int *img_width, int *img_height)
{
	void	*loading_img;

	loading_img = mlx_xpm_file_to_image(data->mlx,
			"textures/loading_screen.xpm", img_width, img_height);
	if (!loading_img)
	{
		printf("ERROR: Failed to load loading_screen.xpm!\n");
		data->game_state = STATE_GAME;
	}
	return (loading_img);
}

int	loading_loop_hook(t_data *data)
{
	static void		*loading_img;
	static int		img_width;
	static int		img_height;

	if (data->game_state != STATE_LOADING)
		return (0);
	if (!loading_img)
		loading_img = init_loading_image(data, &img_width, &img_height);
	if (!loading_img)
		return (0);
	data->map.textures.loading.ptr = loading_img;
	copy_scaled_image(data, loading_img, img_width, img_height);
	draw_loading_bar_on_buffer(data, data->loading_progress);
	mlx_put_image_to_window(data->mlx, data->win, data->frame.ptr, 0, 0);
	data->loading_progress++;
	if (data->loading_progress > LOADING_STEPS)
	{
		mlx_destroy_image(data->mlx, loading_img);
		data->map.textures.loading.ptr = NULL;
		data->game_state = STATE_OPENING;
		data->loading_progress = 0;
	}
	return (0);
}

void	show_loading_screen(t_data *data)
{
	data->game_state = STATE_LOADING;
	data->loading_progress = 0;
}
