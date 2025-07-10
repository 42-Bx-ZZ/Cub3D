/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student->s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:48:03 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/10 18:13:53 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	print_fps(t_data *data)
{
	t_infos	*t;

	t = &data->infos;
	if (elapsed_time() - data->fps.start < 1)
		t->value = ft_strdup("...");
	else
		t->value = ft_itoa(data->fps.fps / (elapsed_time() - data->fps.start));
	if (!t->value)
		clean_exit(data);
	t->value_f = 1;
	t->tmp = ft_strjoin(t->value, " FPS");
	data->infos.tmp_f = 1;
	free(t->value);
	t->value_f = 0;
	if (!t->tmp)
		clean_exit(data);
	mlx_string_put(data->mlx, data->win, data->width - 40, 10, 0xFFFF00, t->tmp);
	free(t->tmp);
	data->infos.tmp_f = 0;
	data->infos.tmp = NULL;
	data->infos.value = NULL;
}

void	print_earn(t_data *data, int earn)
{
	t_infos	*t;

	t = &data->infos;
	t->value = ft_itoa(earn);
	if (!t->value)
		clean_exit(data);
	t->value_f = 1;
	t->tmp = ft_strjoin(t->value, " $");
	data->infos.tmp_f = 1;
	free(t->value);
	t->value_f = 0;
	if (!t->tmp)
		clean_exit(data);
	if (data->player.earn_frames-- >= 0)
		mlx_string_put(data->mlx, data->win, (data->width / 2)
			+ 40, (data->height / 2) - (data->height / 10)
			+ data->player.earn_frames, 0xFFFF00, t->tmp);
	free(t->tmp);
	data->infos.tmp_f = 0;
	data->infos.tmp = NULL;
	data->infos.value = NULL;
}

void	print_money(t_data *data)
{
	t_infos	*t;

	t = &data->infos;
	t->value = ft_itoa(data->player.money);
	if (!t->value)
		clean_exit(data);
	t->value_f = 1;
	t->tmp = ft_strjoin(t->value, " $");
	data->infos.tmp_f = 1;
	free(t->value);
	t->value_f = 0;
	if (!t->tmp)
		clean_exit(data);
	mlx_string_put(data->mlx, data->win, data->width - 40,
		20, 0xFFFF00, t->tmp);
	free(t->tmp);
	data->infos.tmp_f = 0;
	data->infos.tmp = NULL;
	data->infos.value = NULL;
}

void	print_round(t_data *data)
{
	t_infos	*t;

	t = &data->infos;
	t->value = ft_itoa(data->gameplay.round + 1);
	if (!t->value)
		clean_exit(data);
	t->value_f = 1;
	t->tmp = ft_strjoin("Round ", t->value);
	data->infos.tmp_f = 1;
	free(t->value);
	t->value_f = 0;
	if (!t->tmp)
		clean_exit(data);
	mlx_string_put(data->mlx, data->win, 15, data->height - 10, 0xFFFFFF, t->tmp);
	free(t->tmp);
	data->infos.tmp_f = 0;
	data->infos.tmp = NULL;
	data->infos.value = NULL;
}

void	print_infos(t_data *data)
{
	draw_health_bar(data);
	if ((int)(elapsed_time() - data->fps.start) % 10 == 0 && SPAWN == 1)
		revive_ennemies(data);
	if (data->keys.mouse.fire_frames >= 0)
		data->keys.mouse.fire_frames--;
	print_money(data);
	print_fps(data);
	if (data->player.earn_frames > 0)
		print_earn(data, data->gameplay.last_earn);
	print_round(data);
	data->fps.fps++;
	update_hp(data);
}
