/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_screen_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:10:00 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/10 17:53:52 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	init_opening_frame(t_data *data, int *initialized, int *step)
{
	if (!*initialized)
	{
		update_frame(data, FOV, RAYS, data->map.setup);
		*initialized = 1;
		*step = 0;
	}
}

int	opening_loop_hook(t_data *data)
{
	static int	step = 0;
	static int	initialized = 0;
	int			mask_height;

	if (data->game_state != STATE_OPENING)
		return (0);
	init_opening_frame(data, &initialized, &step);
	update_frame(data, FOV, RAYS, data->map.setup);
	mask_height = (data->height / 2) * (OPENING_ANIMATION_STEPS - step)
		/ OPENING_ANIMATION_STEPS;
	draw_opening_mask(data, mask_height);
	mlx_put_image_to_window(data->mlx, data->win, data->frame.ptr, 0, 0);
	step++;
	if (step >= OPENING_ANIMATION_STEPS)
	{
		data->game_state = STATE_GAME;
		initialized = 0;
		step = 0;
	}
	return (0);
}

void	opening_animation(t_data *data)
{
	data->game_state = STATE_OPENING;
}
