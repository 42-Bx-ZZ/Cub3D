/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file_handler_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:30:06 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/10 10:21:47 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	count_file_lines(char *file)
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

void	init_texture_id(char **id)
{
	id[0] = "NO ";
	id[1] = "SO ";
	id[2] = "WE ";
	id[3] = "EA ";
	id[4] = "DO ";
	id[5] = "ZI ";
	id[6] = "ZM ";
	id[7] = "ZH ";
	id[8] = "BI ";
	id[9] = "BM ";
	id[10] = NULL;
}

void	check_if_directory(t_data *data, char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		free_all_and_print_exit(data,
			"Error\n.Cub need to be file not directory\n");
	}
}

void	check_if_empty(t_data *data, int i)
{
	if (i == 0)
		free_all_and_print_exit(data, "Error\nFile is empty\n");
}
