/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:13:51 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/06 13:24:12 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	show_loading_screen(t_data *data)
{
	void	*loading_img;
	int		img_width;
	int		img_height;
	int		progress;

	loading_img = mlx_xpm_file_to_image(data->mlx,
			"textures/loading_screen.xpm", &img_width, &img_height);
	if (!loading_img)
	{
		printf("ERROR: Failed to load loading_screen.xpm!\n");
		return ;
	}
	progress = 0;
	while (progress <= LOADING_STEPS)
	{
		copy_scaled_image(data, loading_img, img_width, img_height);
		draw_loading_bar_on_buffer(data, progress);
		mlx_put_image_to_window(data->mlx, data->win, data->frame.ptr, 0, 0);
		mlx_do_sync(data->mlx);
		usleep(50000);
		progress += 1;
	}
	mlx_destroy_image(data->mlx, loading_img);
}
