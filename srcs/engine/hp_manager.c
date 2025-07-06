/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hp_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:23:03 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/06 13:49:43 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	update_hp(t_data *data)
{
	double	tmp;

	if (data->player.hp >= 100)
		return ;
	tmp = elapsed_time();
	if (tmp - data->player.last_regen >= 2.5)
	{
		if (data->player.hp <= 97)
			data->player.hp += 3;
		else if (data->player.hp <= 98)
			data->player.hp += 2;
		else
			data->player.hp++;
		data->player.last_regen = tmp;
	}
}
