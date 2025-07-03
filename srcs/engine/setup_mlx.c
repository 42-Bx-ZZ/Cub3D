/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:55:07 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/03 09:53:10 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_view(t_data *data, int delta)
{
	data->game.dir += delta * MOUSE_SENSI;
	while (data->game.dir >= 2 * M_PI)
		data->game.dir -= 2 * M_PI;
	while (data->game.dir < 0)
		data->game.dir += 2 * M_PI;
}

int	move_mouse(int x, int y, t_data *data)
{
	int	delta;

	(void)y;
	if (data->keys.replace_cursor)
	{
		data->keys.replace_cursor = 0;
		return (0);
	}
	delta = x - data->width / 2;
	if (abs(delta) < data->width / 4 && delta != 0)
		move_view(data, delta);
	data->keys.replace_cursor = 1;
	mlx_mouse_move(data->mlx, data->win, data->width / 2, data->height / 2);
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
	data->win = mlx_new_window(data->mlx, data->width, data->height, "cub3D");
	if (!data->win)
		return (1);
	if (load_sprites(data))
		return (1);
	data->fps.start = elapsed_time();
	mlx_mouse_hide(data->mlx, data->win);
	mlx_hook(data->win, 6, 1L << 6, &move_mouse, data);
	mlx_hook(data->win, 2, 1L << 0, &key_press, data);
	mlx_hook(data->win, 3, 1L << 1, &key_release, data);
	mlx_mouse_hook(data->win, &mouse_click, data);
	mlx_loop_hook(data->mlx, update_move, data);
	mlx_hook(data->win, CLOSEBTN, 0, clean_exit, data);
	mlx_loop(data->mlx);
	return (0);
}
