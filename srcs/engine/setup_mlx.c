/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:55:07 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/01 15:13:49 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	mouse_move(int x, int y, t_data *data)
{
	static int	last_x = -1;
	int			delta_x;

	(void)y;
	if (last_x == -1)
		return (last_x = x, 0);
	delta_x = x - last_x;
	printf("Mouse move: x=%d, y=%d, delta_x=%d\n", x, y, delta_x);
	if (abs(delta_x) > 1)
	{
		data->game.dir += delta_x * MOUSE_SENSI;
		while (data->game.dir >= 2 * M_PI)
			data->game.dir -= 2 * M_PI;
		while (data->game.dir < 0)
			data->game.dir += 2 * M_PI;
	}
	last_x = x;
	return (0);
}

int	keys_hook(int key, t_data *data)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		moves(key, data);
	else if (key == L_ARROW || key == R_ARROW)
		view(key, data);
	return (0);
}

int	setup_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	if ((!HEIGHT || !WIDTH)
		&& mlx_get_screen_size(data->mlx, &data->width, &data->height))
		return (1);
	if (HEIGHT > 0 && WIDTH > 0)
	{
		data->width = WIDTH;
		data->height = HEIGHT;
	}
	data->win = mlx_new_window(data->mlx, data->width, data->height, "cub3D");
	if (!data->win || load_sprites(data))
		return (1);
	data->fps.start = elapsed_time();
	mlx_hook(data->win, 2, 1L << 0, &key_press, data);
	mlx_hook(data->win, 3, 1L << 1, &key_release, data);
	mlx_loop_hook(data->mlx, update_move, data);
	mlx_hook(data->win, CLOSEBTN, 0, clean_exit, data);
	mlx_loop(data->mlx);
	return (0);
}
