/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:55:07 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/02 16:54:40 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int setup_mlx(t_data *data)
{
    data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	if (!data->win || load_sprites(data))
		return (1);
	mlx_hook(data->win, 2, 1L<<0, &keys_hook, data);
    mlx_hook(data->win, CLOSEBTN, 0, clean_exit, data);
	mlx_loop(data->mlx);
    return (0);
}
