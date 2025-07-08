/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:29:57 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/09 00:21:48 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	clean_guns(t_data *data)
{
	if (data->player.gun.idle.ptr)
		mlx_destroy_image(data->mlx, data->player.gun.idle.ptr);
	if (data->player.laser.idle.ptr)
		mlx_destroy_image(data->mlx, data->player.laser.idle.ptr);
	if (data->player.gun.moving.ptr)
		mlx_destroy_image(data->mlx, data->player.gun.moving.ptr);
	if (data->player.laser.moving.ptr)
		mlx_destroy_image(data->mlx, data->player.laser.moving.ptr);
	if (data->player.gun.firing.ptr)
		mlx_destroy_image(data->mlx, data->player.gun.firing.ptr);
	if (data->player.laser.moving.ptr)
		mlx_destroy_image(data->mlx, data->player.laser.firing.ptr);
}

void	destroy_imgs(t_data *data)
{
	if (!data)
		return ;
	if (data->frame.ptr)
		mlx_destroy_image(data->mlx, data->frame.ptr);
	if (data->map.textures.south.ptr)
		mlx_destroy_image(data->mlx, data->map.textures.south.ptr);
	if (data->map.textures.east.ptr)
		mlx_destroy_image(data->mlx, data->map.textures.east.ptr);
	if (data->map.textures.west.ptr)
		mlx_destroy_image(data->mlx, data->map.textures.west.ptr);
	if (data->map.textures.door.ptr)
		mlx_destroy_image(data->mlx, data->map.textures.door.ptr);
	if (data->map.textures.north.ptr)
		mlx_destroy_image(data->mlx, data->map.textures.north.ptr);
	if (data->map.textures.ennemy[0].ptr)
		mlx_destroy_image(data->mlx, data->map.textures.ennemy[0].ptr);
	if (data->map.textures.ennemy[1].ptr)
		mlx_destroy_image(data->mlx, data->map.textures.ennemy[1].ptr);
	if (data->map.textures.ennemy[2].ptr)
		mlx_destroy_image(data->mlx, data->map.textures.ennemy[2].ptr);
	if (data->frame.ptr)
		mlx_destroy_image(data->mlx, data->frame.ptr);
	clean_guns(data);
}

int	clean_exit(t_data *data)
{
	destroy_imgs(data);
	if (data && data->map.setup)
		ft_free_tab(data->map.setup);
	if (data && data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data && data->mlx)
		free(data->mlx);
	exit(1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || !av[1][0])
		return (2);
	ft_memset(&data, 0, sizeof(data));
	data.map.setup = get_map(av[1]);
	if (!data.map.setup)
		clean_exit(&data);
	data.player.money = MONEY + 100 * 100;
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
