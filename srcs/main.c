/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:29:57 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/01 11:49:02 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	destroy_imgs(t_data *data)
{
	if (data->frame.ptr)
		mlx_destroy_image(data->mlx, data->frame.ptr);
	if (data->map.textures.south.ptr)
		mlx_destroy_image(data->mlx, data->map.textures.south.ptr);
	if (data->map.textures.east.ptr)
		mlx_destroy_image(data->mlx, data->map.textures.east.ptr);
	if (data->map.textures.west.ptr)
		mlx_destroy_image(data->mlx, data->map.textures.west.ptr);
	if (data->map.textures.north.ptr)
		mlx_destroy_image(data->mlx, data->map.textures.north.ptr);
}

int	clean_exit(t_data *data)
{
	if (data && data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	destroy_imgs(data);
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
	data.player.money = 2000;
	data.player.hp = 100;
	data.player.last_hit = elapsed_time();
	setup_mlx(&data);
}
