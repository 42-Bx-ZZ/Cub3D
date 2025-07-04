/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:28:08 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/04 09:29:50 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	swap_gun(t_data *data)
{
	t_gun	tmp;

	tmp = data->player.gun;
	data->player.gun = data->player.laser;
	data->player.laser = tmp;
}
