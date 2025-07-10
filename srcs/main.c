/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:29:57 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/10 10:00:02 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || !av[1][0])
		return (2);
	ft_memset(&data, 0, sizeof(data));
	data.player.money = MONEY;
	data.gameplay.ennemy_hp = ENNEMY_HP;
	data.player.hp = 100;
	extract_all_cub_data(&data, av[1]);
	if (HEIGHT > 0 && WIDTH > 0)
	{
		data.width = WIDTH;
		data.height = HEIGHT;
	}
	data.player.last_hit = elapsed_time();
	if (setup_mlx(&data))
		clean_exit(&data);
	return (0);
}
