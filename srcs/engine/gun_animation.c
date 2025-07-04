/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:28:08 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/04 13:10:36 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	swap_imgs(t_img *a, t_img *b)
{
	t_img	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_gun_stance(t_data *data)
{
	if (data->keys.mouse.fire_frames > 0 && data->player.gun.stance == 0)
	{
			swap_imgs(&data->player.gun.idle, &data->player.gun.firing);
			data->keys.mouse.fire_frames = 20;
			data->player.gun.stance = 2;
			printf("swap to stance 2\n");
	}
	if (data->keys.mouse.fire_frames <= 0 && data->player.gun.stance == 2)
	{
			swap_imgs(&data->player.gun.idle, &data->player.gun.firing);
			swap_imgs(&data->player.gun.idle, &data->player.gun.moving);
			data->keys.mouse.fire_frames = 20;
			data->player.gun.stance = 1;
			printf("swap to stance 1\n");
	}
	if (data->keys.mouse.fire_frames <= 0 && data->player.gun.stance == 1)
	{
			swap_imgs(&data->player.gun.idle, &data->player.gun.moving);
			printf("swap to stance 0\n");
			data->player.gun.stance = 0;
	}
}

void	swap_gun(t_data *data)
{
	t_gun	tmp;

	tmp = data->player.gun;
	data->player.gun = data->player.laser;
	data->player.laser = tmp;
}

