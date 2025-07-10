/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:29:57 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/10 19:17:33 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	check_args(ac, av);
	ft_memset(&data, 0, sizeof(data));
	extract_all_cub_data(&data, av[1]);
	init_game_data(&data);
	if (setup_mlx(&data))
		clean_exit(&data);
	return (0);
}
