/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clean_linux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 23:51:31 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/25 17:47:14 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	clean_walls(t_data *data)
{
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
}

static void	clean_zombies(t_data *data)
{
	if (data->map.textures.ennemy[0].ptr)
		mlx_destroy_image(data->mlx, data->map.textures.ennemy[0].ptr);
	if (data->map.textures.ennemy[1].ptr)
		mlx_destroy_image(data->mlx, data->map.textures.ennemy[1].ptr);
	if (data->map.textures.ennemy[2].ptr)
		mlx_destroy_image(data->mlx, data->map.textures.ennemy[2].ptr);
	if (data->map.textures.boss[0].ptr)
		mlx_destroy_image(data->mlx, data->map.textures.boss[0].ptr);
	if (data->map.textures.boss[1].ptr)
		mlx_destroy_image(data->mlx, data->map.textures.boss[1].ptr);
	if (data->map.textures.boss[2].ptr)
		mlx_destroy_image(data->mlx, data->map.textures.boss[2].ptr);
}

static void	clean_guns(t_data *data)
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

static void	destroy_imgs(t_data *data)
{
	if (data->frame.ptr)
		mlx_destroy_image(data->mlx, data->frame.ptr);
	if (data->map.textures.loading.ptr)
		mlx_destroy_image(data->mlx, data->map.textures.loading.ptr);
	clean_walls(data);
	clean_zombies(data);
	clean_guns(data);
}

int	clean_exit(t_data *data)
{
	mlx_mouse_show(data->mlx, data->win);
	free_all_data(data);
	destroy_imgs(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	if (data->infos.value && data->infos.value_f)
		free(data->infos.value);
	if (data->infos.tmp && data->infos.tmp_f)
		free(data->infos.tmp);
	free(data->mlx);
	exit(1);
}
