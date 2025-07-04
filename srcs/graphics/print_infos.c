/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:48:03 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/04 09:17:44 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	print_fps(t_data *data)
{
	char	*fps;
	char	*temp;

	if (elapsed_time() - data->fps.start < 1)
		fps = ft_strdup("...");
	else
		fps = ft_itoa(data->fps.fps / (elapsed_time() - data->fps.start));
	if (!fps)
		clean_exit(data);
	temp = ft_strjoin(fps, " FPS");
	free(fps);
	if (!temp)
		clean_exit(data);
	mlx_string_put(data->mlx, data->win, data->width - 40, 10, 0xFFFF00, temp);
	free(temp);
}

void	print_earn(t_data *data, int earn)
{
	char	*money;
	char	*temp;

	money = ft_itoa(earn);
	if (!money)
		clean_exit(data);
	temp = ft_strjoin(money, " $");
	free(money);
	if (!temp)
		clean_exit(data);
	if (data->player.earn_frames-- >= 0)
		mlx_string_put(data->mlx, data->win, (data->width / 2)
			+ 40, (data->height / 2) - (data->height / 10)
			+ data->player.earn_frames, 0xFFFF00, temp);
	free(temp);
}

void	print_money(t_data *data)
{
	char	*money;
	char	*temp;

	money = ft_itoa(data->player.money);
	if (!money)
		clean_exit(data);
	temp = ft_strjoin(money, " $");
	free(money);
	if (!temp)
		clean_exit(data);
	mlx_string_put(data->mlx, data->win, data->width - 40, 20, 0xFFFF00, temp);
	free(temp);
}

void	print_round(t_data *data)
{
	char	*round;
	char	*temp;

	round = ft_itoa(data->gameplay.round + 1);
	if (!round)
		clean_exit(data);
	temp = ft_strjoin("Round ", round);
	free(round);
	if (!temp)
		clean_exit(data);
	mlx_string_put(data->mlx, data->win, 15, data->height - 10, 0xFFFFFF, temp);
	free(temp);
}

void	print_infos(t_data *data)
{
	if ((int)(elapsed_time() - data->fps.start) % 10 == 0 && SPAWN == 1)
		revive_ennemies(data);
	print_money(data);
	print_fps(data);
	print_earn(data, data->gameplay.last_earn);
	print_round(data);
}
