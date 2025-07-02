/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 01:31:02 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/01 10:43:04 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	parse_and_verif(t_data *data, char **path, char *new_path)
{
	if (*path)
	{
		free(new_path);
		free_all_and_print_exit(data, "Error\nToo much wall path\n");
	}
	*path = new_path;
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
	else if (ft_strncmp(type, "ZF", 2) == 0)
		parse_and_verif(data, &data->map.textures.zfront_path, path);
	else if (ft_strncmp(type, "ZB", 2) == 0)
		parse_and_verif(data, &data->map.textures.zback_path, path);
}

static char	*verif_and_extract(t_data *data, int i, char *line)
{
	char	*path;
	int		j;

	j = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '.')
			free_all_and_print_exit(data, "Error\nCub file data are not valid");
		if (line[i] == '.')
			break ;
		i++;
	}
	j = i;
	while (line[j])
		j++;
	path = ft_substr(line, i, j - i);
	if (!path)
		free_all_and_print_exit(data, "Error\nMalloc failed");
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
		free_all_and_print_exit(data, "Error\nCan't open wall file");
	}
	parse_path(data, path, type);
	close(fd);
}
