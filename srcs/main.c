/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:29:57 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/09 23:51:11 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || !av[1][0])
		return (2);
	ft_memset(&data, 0, sizeof(data));
	data.map.setup = get_map(av[1]);
	if (!data.map.setup)
		clean_exit(&data);
	data.player.money = MONEY;
	data.gameplay.ennemy_hp = ENNEMY_HP;
	data.player.hp = 100;
	if (HEIGHT > 0 && WIDTH > 0)
	{
		data.width = WIDTH;
		data.height = HEIGHT;
	}
	data.map.textures.floor_color[0] = 33;
	data.map.textures.floor_color[1] = 33;
	data.map.textures.floor_color[2] = 33;
	data.map.textures.ceiling_color[0] = 0;
	data.map.textures.ceiling_color[1] = 0;
	data.map.textures.ceiling_color[2] = 100;
	data.player.last_hit = elapsed_time();
	if (setup_mlx(&data))
		clean_exit(&data);
	return (0);
}
