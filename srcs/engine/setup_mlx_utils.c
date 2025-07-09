/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:05:00 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/07 17:57:58 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	unified_loop_hook(t_data *data)
{
	if (data->game_state == STATE_LOADING)
		loading_loop_hook(data);
	else if (data->game_state == STATE_OPENING)
		opening_loop_hook(data);
	else if (data->game_state == STATE_GAME)
		update_move(data);
	return (0);
}
