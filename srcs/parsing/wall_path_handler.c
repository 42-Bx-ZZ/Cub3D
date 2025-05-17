/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_path_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 01:31:02 by zaiicko           #+#    #+#             */
/*   Updated: 2025/05/18 01:33:10 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	parse_wall_path(t_data *data, char *path, char *type)
{
	if (ft_strncmp(type, "NO", 2) == 0)
		data->map.textures.north_path = path;
	else if (ft_strncmp(type, "SO", 2) == 0)
		data->map.textures.south_path = path;
	else if (ft_strncmp(type, "WE", 2) == 0)
		data->map.textures.west_path = path;
	else if (ft_strncmp(type, "EA", 2) == 0)
		data->map.textures.east_path = path;
}

static char	*verif_and_extract(t_data *data, int i, char *line)
{
	char	*wall_path;
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
	wall_path = ft_substr(line, i, j - i);
	if (!wall_path)
		free_all_and_print_exit(data, "Error\nMalloc failed");
	return (wall_path);
}

void	check_and_parse_wall_path(t_data *data, char *line, char *type)
{
	int		fd;
	char	*wall_path;
	int		i;

	i = 3;
	wall_path = verif_and_extract(data, i, line);
	fd = open(wall_path, O_RDONLY);
	if (fd < 0)
		free_all_and_print_exit(data, "Error\nCan't open wall file");
	parse_wall_path(data, wall_path, type);
	close(fd);
}
