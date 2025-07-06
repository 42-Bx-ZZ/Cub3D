/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:28:08 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/06 14:31:26 by lowatell         ###   ########.fr       */
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
	data->player.targeting = 0;
	if (data->keys.mouse.fire_frames > 0 && data->player.gun.stance == 0)
	{
		swap_imgs(&data->player.gun.idle, &data->player.gun.firing);
		data->player.gun.stance = 2;
		printf("swap to stance 2\n");
	}
	else if (data->keys.mouse.fire_frames <= 0 && data->player.gun.stance == 2)
	{
		swap_imgs(&data->player.gun.idle, &data->player.gun.firing);
		swap_imgs(&data->player.gun.idle, &data->player.gun.moving);
		data->player.gun.stance = 1;
		data->keys.mouse.fire_frames = 20;
		printf("swap to stance 1\n");
	}
	else if (data->keys.mouse.fire_frames <= 0 && data->player.gun.stance == 1)
	{
		swap_imgs(&data->player.gun.idle, &data->player.gun.moving);
		data->player.gun.stance = 0;
		printf("swap to stance 0 (idle)\n");
	}
	if (data->keys.mouse.fire_frames > 0)
		data->keys.mouse.fire_frames--;
}

void	swap_gun(t_data *data)
{
	t_gun	tmp;

	tmp = data->player.gun;
	data->player.gun = data->player.laser;
	data->player.laser = tmp;
}
