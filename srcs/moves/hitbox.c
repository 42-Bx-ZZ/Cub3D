/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:03:35 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/01 14:40:29 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	move_overflow(t_data *data, float x, float y, float hitbox)
{
	int	p_x_y[2];
	int	m_x_y[2];
	int	max_y;

	p_x_y[0] = (int)(x + hitbox);
	p_x_y[1] = (int)(y + hitbox);
	m_x_y[0] = (int)(x - hitbox);
	m_x_y[1] = (int)(y - hitbox);
	max_y = ft_tablen(data->map.setup);
	if (p_x_y[1] < 0 || p_x_y[1] >= max_y || m_x_y[1] < 0 || m_x_y[1] >= max_y)
		return (1);
	if (p_x_y[0] < 0 || p_x_y[0] >= (int)ft_strlen(data->map.setup[p_x_y[1]])
		|| m_x_y[0] < 0
		|| m_x_y[0] >= (int)ft_strlen(data->map.setup[p_x_y[1]]))
		return (1);
	if (p_x_y[0] < 0 || p_x_y[0] >= (int)ft_strlen(data->map.setup[m_x_y[1]])
		|| m_x_y[0] < 0
		|| m_x_y[0] >= (int)ft_strlen(data->map.setup[m_x_y[1]]))
		return (1);
	return (0);
}

int	check_last_hit(t_data *data)
{
	double	tmp;

	tmp = elapsed_time();
	if (tmp - data->player.last_hit >= (INVU_TIME))
	{
		data->player.last_hit = tmp;
		return (0);
	}
	return (1);
}

int	is_player(t_data *data, float x, float y, float hitbox)
{
	int	p_x;
	int	m_x;
	int	p_y;
	int	m_y;

	if (move_overflow(data, x, y, hitbox))
		return (1);
	p_x = (int)(x + hitbox);
	p_y = (int)(y + hitbox);
	m_x = (int)(x - hitbox);
	m_y = (int)(y - hitbox);
	if (data->map.setup[p_y][p_x] == 'P' || data->map.setup[p_y][m_x] == 'P'
		|| data->map.setup[m_y][p_x] == 'P' || data->map.setup[m_y][m_x] == 'P')
	{
		if (check_last_hit(data))
			return (1);
		data->player.hp -= 25;
		if (data->player.hp <= 0)
		{
			ft_putstr_fd("Game Over\n", 1);
			clean_exit(data);
		}
		return (1);
	}
	return (0);
}

int	is_blocked(t_data *data, float x, float y, float hitbox)
{
	int	p_x;
	int	m_x;
	int	p_y;
	int	m_y;

	if (move_overflow(data, x, y, HITBOX * 2))
		return (1);
	p_x = (int)(x + hitbox);
	p_y = (int)(y + hitbox);
	m_x = (int)(x - hitbox);
	m_y = (int)(y - hitbox);
	if (data->map.setup[p_y][p_x] == '1' || data->map.setup[p_y][m_x] == '1'
		|| data->map.setup[m_y][p_x] == '1' || data->map.setup[m_y][m_x] == '1')
		return (1);
	if (data->map.setup[p_y][p_x] == 'D' || data->map.setup[p_y][m_x] == 'D'
		|| data->map.setup[m_y][p_x] == 'D' || data->map.setup[m_y][m_x] == 'D')
		return (1);
	if (is_player(data, x, y, hitbox))
		return (1);
	return (0);
}
