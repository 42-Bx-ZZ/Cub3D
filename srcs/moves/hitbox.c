/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:03:35 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/23 08:36:58 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	is_blocked(t_data *data, float x, float y)
{
	int	p_x;
	int	m_x;
	int	p_y;
	int	m_y;

	p_x = (int)(x + HITBOX);
	p_y = (int)(y + HITBOX);
	m_x = (int)(x - HITBOX);
	m_y = (int)(y - HITBOX);
	if (!data->map.setup[p_y][p_x] || !data->map.setup[p_y][m_x]
		|| !data->map.setup[m_y][p_x] || !data->map.setup[m_y][m_x])
		return (1);
	if (data->map.setup[p_y][p_x] == '1' || data->map.setup[p_y][m_x] == '1'
		|| data->map.setup[m_y][p_x] == '1' || data->map.setup[m_y][m_x] == '1')
		return (1);
	return (0);
}
