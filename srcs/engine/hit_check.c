/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:03:12 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/25 00:36:33 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	hit_check(t_data *data)
{
	if (data->keys.e && data->player.earn_frames == 0)
	{
		data->player.hit = 1;
		return (data->player.earn_frames = 100, 1);
	}
	return (0);
}
