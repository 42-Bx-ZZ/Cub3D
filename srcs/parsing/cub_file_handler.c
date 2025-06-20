/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:02:55 by zaiicko           #+#    #+#             */
/*   Updated: 2025/06/20 13:18:44 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	count_file_lines(char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_print_exit("Error\nCan't open .cub file");
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	extract_all_cub_data(t_data *data, char *file)
{
	int		fd;
	int		i;

	data->cub_file = (char **)malloc(sizeof(char *)
			* (count_file_lines(file) + 1));
	if (!data->cub_file)
		ft_print_exit("Error\nMalloc failed\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		free_all_and_print_exit(data, "Error\nCan't open .cub file");
	i = 0;
	data->cub_file[i] = get_next_line(fd);
	while (data->cub_file[i])
	{
		if (data->cub_file[i][ft_strlen(data->cub_file[i]) - 1] == '\n')
			data->cub_file[i][ft_strlen(data->cub_file[i]) - 1] = '\0';
		i++;
		data->cub_file[i] = get_next_line(fd);
	}
	data->cub_file[i] = NULL;
	close(fd);
}

void	check_and_parse_cub_file(t_data *data)
{
	int	i;

	i = 0;
	while (data->cub_file[i])
	{
		if (ft_strncmp(data->cub_file[i], "NO ", 3) == 0)
			check_and_parse_wall_path(data, data->cub_file[i], "NO");
		else if (ft_strncmp(data->cub_file[i], "SO ", 3) == 0)
			check_and_parse_wall_path(data, data->cub_file[i], "SO");
		else if (ft_strncmp(data->cub_file[i], "WE ", 3) == 0)
			check_and_parse_wall_path(data, data->cub_file[i], "WE");
		else if (ft_strncmp(data->cub_file[i], "EA ", 3) == 0)
			check_and_parse_wall_path(data, data->cub_file[i], "EA");
		else if (ft_strncmp(data->cub_file[i], "F ", 2) == 0)
			check_and_parse_fc_colors(data, data->cub_file[i], 'F');
		else if (ft_strncmp(data->cub_file[i], "C ", 2) == 0)
			check_and_parse_fc_colors(data, data->cub_file[i], 'C');
		else if (data->cub_file[i][0] == ' ' || data->cub_file[i][0] == '1')
			check_and_parse_map(data, &i);
		else if (data->cub_file[i][0] != '\0')
			free_all_and_print_exit(data, "Error\nWrong data in cub file");
		i++;
	}
}
