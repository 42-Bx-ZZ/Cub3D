/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:48:03 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/25 09:34:41 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	print_fps(t_data *data)
{
	char	*fps;
	char	*temp;

	fps = ft_itoa(data->fps.fps / (elapsed_time() - data->fps.start));
	if (!fps)
		clean_exit(data);
	temp = ft_strjoin(fps, " FPS");
	free(fps);
	if (!temp)
		clean_exit(data);
	mlx_string_put(data->mlx, data->win, data->width - 40, 10, 0x000000, temp);
	free(temp);
}

void	print_earn(t_data *data)
{
	char	*money;
	char	*temp;
	int		base;

	base = 100;
	money = ft_itoa(base);
	if (!money)
		clean_exit(data);
	temp = ft_strjoin(money, " $");
	free(money);
	if (!temp)
		clean_exit(data);
	if (data->player.earn_frames-- >= 0)
		mlx_string_put(data->mlx, data->win, (data->width / 2)
			+ 40, (data->height / 2)
			- data->player.earn_frames, 0xFFFF00, temp);
	free(temp);
	data->player.money += base;
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
	mlx_string_put(data->mlx, data->win, data->width - 40, 20, 0x000000, temp);
	free(temp);
}

void	print_infos(t_data *data)
{
	print_money(data);
	print_fps(data);
}
