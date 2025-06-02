/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:29:57 by zaiicko           #+#    #+#             */
/*   Updated: 2025/05/31 23:55:56 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	clean_exit(t_data *data)
{
	// if (data && data->mlx && data->win && LINUX)
	// 	mlx_destroy_display(data->mlx);
	if (data && data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data && data->map.setup)
		ft_free_tab(data->map.setup);
	exit(1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || !av[1][0])
		return (0);
	ft_memset(&data, 0, sizeof(data));
	data.map.setup = get_map(av[1]);
	if (!data.map.setup)
		clean_exit(&data);
	setup_mlx(&data);
}
