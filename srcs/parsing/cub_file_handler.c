/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:02:55 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/10 11:18:47 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	check_map_ending(t_data *data)
{
	if (data->cub_file[data->cub_len - 1]
		[ft_strlen(data->cub_file[data->cub_len - 1]) - 1] == '\n')
		free_all_and_print_exit(data,
			"Error\nThe map aren't last in cub_file\n");
}

static void	replace_line_breaks(t_data *data)
{
	int	i;

	i = 0;
	while (data->cub_file[i])
	{
		if (data->cub_file[i][ft_strlen(data->cub_file[i]) - 1] == '\n')
			data->cub_file[i][ft_strlen(data->cub_file[i]) - 1] = '\0';
		i++;
	}
}

void	extract_all_cub_data(t_data *data, char *file)
{
	int		fd;
	int		i;

	check_if_directory(data, file);
	data->cub_len = count_file_lines(file);
	data->cub_file = (char **)malloc(sizeof(char *)
			* (data->cub_len + 1));
	if (!data->cub_file)
		ft_print_exit("Error\nMalloc failed\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		free_all_and_print_exit(data, "Error\nCan't open .cub file\n");
	i = 0;
	data->cub_file[i] = get_next_line(fd);
	while (data->cub_file[i])
	{
		i++;
		data->cub_file[i] = get_next_line(fd);
	}
	data->cub_file[i] = NULL;
	check_if_empty(data, i);
	check_map_ending(data);
	replace_line_breaks(data);
	close(fd);
	check_and_parse_cub_file(data);
}

static int	check_texture(t_data *data, int *i)
{
	char	*id[17];
	int		j;

	init_texture_id(id);
	j = 0;
	while (id[j])
	{
		if (ft_strncmp(data->cub_file[*i], id[j], ft_strlen(id[j])) == 0)
		{
			check_and_parse_path(data, data->cub_file[*i], id[j]);
			return (1);
		}
		j++;
	}
	return (0);
}

void	check_and_parse_cub_file(t_data *data)
{
	int	i;

	i = 0;
	while (data->cub_file[i])
	{
		if (check_texture(data, &i))
			;
		else if (ft_strncmp(data->cub_file[i], "F ", 2) == 0)
			check_and_parse_fc_colors(data, data->cub_file[i], 'F');
		else if (ft_strncmp(data->cub_file[i], "C ", 2) == 0)
			check_and_parse_fc_colors(data, data->cub_file[i], 'C');
		else if (data->cub_file[i][0] == ' ' || data->cub_file[i][0] == '1')
			check_and_parse_map(data, &i);
		else if (data->cub_file[i][0] != '\0')
			free_all_and_print_exit(data, "Error\nWrong data in cub file\n");
		i++;
	}
	check_if_all_cub_data(data);
}
