/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:09:13 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/01 16:53:17 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	move_left(t_data *data, float t_step)
{
	float	new_x;
	float	new_y;
	char	**map;

	map = data->map.setup;
	new_x = data->game.p_x - cosf(data->game.dir + M_PI_2) * t_step;
	new_y = data->game.p_y - sinf(data->game.dir + M_PI_2) * t_step;
	if (is_blocked(data, new_x, new_y, HITBOX))
		return ;
	if (map[(int)(data->game.p_y)]
			[(int)(new_x - cosf(data->game.dir + M_PI_2) * HITBOX)] != '1'
			&& map[(int)(data->game.p_y)]
			[(int)(new_x - cosf(data->game.dir + M_PI_2) * HITBOX)] != 'D')
	{
		if (map[(int)(new_y - sinf(data->game.dir + M_PI_2) * HITBOX)]
			[(int)(new_x)] != '1'
			&& map[(int)(new_y - sinf(data->game.dir + M_PI_2) * HITBOX)]
			[(int)(new_x)] != 'D')
		{
			data->game.p_x = new_x;
			data->game.p_y = new_y;
		}
	}
}

static void	move_right(t_data *data, float t_step)
{
	float	new_x;
	float	new_y;
	char	**map;

	map = data->map.setup;
	new_x = data->game.p_x + cosf(data->game.dir + M_PI_2) * t_step;
	new_y = data->game.p_y + sinf(data->game.dir + M_PI_2) * t_step;
	if (is_blocked(data, new_x, new_y, HITBOX))
		return ;
	if (map[(int)(data->game.p_y)]
			[(int)(new_x + cosf(data->game.dir + M_PI_2) * HITBOX)] != '1'
			&& map[(int)(data->game.p_y)]
			[(int)(new_x + cosf(data->game.dir + M_PI_2) * HITBOX)] != 'D')
	{
		if (map[(int)(new_y + sinf(data->game.dir + M_PI_2) * HITBOX)]
				[(int)(new_x)] != '1'
				&& map[(int)(new_y + sinf(data->game.dir + M_PI_2) * HITBOX)]
				[(int)(new_x)] != 'D')
		{
			data->game.p_x = new_x;
			data->game.p_y = new_y;
		}
	}
}

static void	move_up(t_data *data, float t_step)
{
	float	new_x;
	float	new_y;
	char	**map;

	map = data->map.setup;
	if (data->keys.shift)
		t_step *= 2;
	new_x = data->game.p_x + cosf(data->game.dir) * t_step;
	new_y = data->game.p_y + sinf(data->game.dir) * t_step;
	if (is_blocked(data, new_x, new_y, HITBOX))
		return ;
	if (map[(int)(data->game.p_y)]
		[(int)(new_x + cosf(data->game.dir) * HITBOX)] != '1'
		&& map[(int)(data->game.p_y)]
		[(int)(new_x + cosf(data->game.dir) * HITBOX)] != 'D')
	{
		if (map[(int)(new_y + sinf(data->game.dir) * HITBOX)]
				[(int)(new_x)] != '1'
				&& map[(int)(new_y + sinf(data->game.dir) * HITBOX)]
				[(int)(new_x)] != 'D')
		{
			data->game.p_x = new_x;
			data->game.p_y = new_y;
		}
	}
}

static void	move_down(t_data *data, float t_step)
{
	float	new_x;
	float	new_y;
	char	**map;

	map = data->map.setup;
	new_x = data->game.p_x - cosf(data->game.dir) * t_step;
	new_y = data->game.p_y - sinf(data->game.dir) * t_step;
	if (is_blocked(data, new_x, new_y, HITBOX))
		return ;
	if (map[(int)(data->game.p_y)]
			[(int)(new_x - cosf(data->game.dir) * HITBOX)] != '1'
			&& map[(int)(data->game.p_y)]
			[(int)(new_x - cosf(data->game.dir) * HITBOX)] != 'D')
	{
		if (map[(int)(new_y - sinf(data->game.dir) * HITBOX)]
			[(int)(data->game.p_x)] != '1'
			&& map[(int)(new_y - sinf(data->game.dir) * HITBOX)]
			[(int)(data->game.p_x)] != 'D')
		{
			data->game.p_x = new_x;
			data->game.p_y = new_y;
		}
	}
}

void	moves(int key, t_data *data)
{
	float	t_step;

	t_step = STEP;
	data->map.setup[(int)data->game.p_y][(int)data->game.p_x] = '0';
	if ((data->keys.up && (data->keys.right || data->keys.left))
		|| (data->keys.down && (data->keys.right || data->keys.left)))
		t_step = STEP * 0.5;
	else if (data->keys.l_arrow || data->keys.r_arrow)
		t_step = STEP * 0.5;
	if (data->game.p_x > 0 && data->game.p_y > 0
		&& data->map.setup[(int)data->game.p_y][(int)data->game.p_x])
	{
		if (key == UP)
			move_up(data, t_step);
		if (key == DOWN)
			move_down(data, t_step);
		if (key == LEFT)
			move_left(data, t_step);
		if (key == RIGHT)
			move_right(data, t_step);
	}
	data->map.setup[(int)data->game.p_y][(int)data->game.p_x] = 'P';
}
