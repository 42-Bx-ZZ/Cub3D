/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 01:31:02 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/15 11:06:05 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	parse_and_verif(t_data *data, char **path, char *new_path)
{
	if (*path)
	{
		free(new_path);
		free_all_and_print_exit(data, "Error\nToo much texture path\n");
	}
	*path = new_path;
}

static void	parse_path_guns(t_data *data, char *path, char *type)
{
	if (ft_strncmp(type, "LI", 2) == 0)
		parse_and_verif(data, &data->map.textures.laser_idle, path);
	else if (ft_strncmp(type, "LM", 2) == 0)
		parse_and_verif(data, &data->map.textures.laser_move, path);
	else if (ft_strncmp(type, "LS", 2) == 0)
		parse_and_verif(data, &data->map.textures.laser_shot, path);
	else if (ft_strncmp(type, "GI", 2) == 0)
		parse_and_verif(data, &data->map.textures.gun_idle, path);
	else if (ft_strncmp(type, "GM", 2) == 0)
		parse_and_verif(data, &data->map.textures.gun_move, path);
	else if (ft_strncmp(type, "GS", 2) == 0)
		parse_and_verif(data, &data->map.textures.gun_shot, path);
}

static void	parse_path(t_data *data, char *path, char *type)
{
	if (ft_strncmp(type, "NO", 2) == 0)
		parse_and_verif(data, &data->map.textures.north_path, path);
	else if (ft_strncmp(type, "SO", 2) == 0)
		parse_and_verif(data, &data->map.textures.south_path, path);
	else if (ft_strncmp(type, "WE", 2) == 0)
		parse_and_verif(data, &data->map.textures.west_path, path);
	else if (ft_strncmp(type, "EA", 2) == 0)
		parse_and_verif(data, &data->map.textures.east_path, path);
	else if (ft_strncmp(type, "DO", 2) == 0)
		parse_and_verif(data, &data->map.textures.door_path, path);
	else if (ft_strncmp(type, "ZI", 2) == 0)
		parse_and_verif(data, &data->map.textures.z_idle, path);
	else if (ft_strncmp(type, "ZM", 2) == 0)
		parse_and_verif(data, &data->map.textures.z_move, path);
	else if (ft_strncmp(type, "ZH", 2) == 0)
		parse_and_verif(data, &data->map.textures.z_hit, path);
	else if (ft_strncmp(type, "BM", 2) == 0)
		parse_and_verif(data, &data->map.textures.boss_move, path);
	else if (ft_strncmp(type, "BI", 2) == 0)
		parse_and_verif(data, &data->map.textures.boss_idle, path);
	else
		parse_path_guns(data, path, type);
}

static char	*verif_and_extract(t_data *data, int i, char *line)
{
	char	*path;
	int		j;

	j = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '.')
			free_all_and_print_exit(data,
				"Error\nCub file data are not valid\n");
		if (line[i] == '.')
			break ;
		i++;
	}
	j = i;
	while (line[j])
		j++;
	path = ft_substr(line, i, j - i);
	if (!path)
		free_all_and_print_exit(data, "Error\nMalloc failed\n");
	return (path);
}

void	check_and_parse_path(t_data *data, char *line, char *type)
{
	int		fd;
	char	*path;
	int		i;

	i = ft_strlen(type);
	path = verif_and_extract(data, i, line);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(path);
		ft_putstr_fd("Error\nCan't open: ", 2);
		ft_putstr_fd(type, 2);
		free_all_and_print_exit(data, " texture.\n");
	}
	parse_path(data, path, type);
	close(fd);
}
