/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:02:55 by zaiicko           #+#    #+#             */
/*   Updated: 2025/05/17 13:50:47 by zaiicko          ###   ########.fr       */
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

void	extract_cub_data(t_data *data, char *file)
{
	int		fd;
	int		i;

	data->cub_file = (char **)malloc(sizeof(char *)
			* (count_file_lines(file)));
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
	close(fd);
}
