/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_colors_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:05:51 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/10 11:37:43 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static char	*color_protect_substr(t_data *data, char *line, int i, int j)
{
	char	*value;

	value = ft_substr(line, i, j - i);
	if (!value)
		free_all_and_print_exit(data, "Error\nMalloc failed");
	else if (ft_strlen(value) > 3)
	{
		free(value);
		free_all_and_print_exit(data, "Error\nCub file data are not valid\n");
	}
	return (value);
}

static char	*verif_and_extract(t_data *data, int *i, char *line, int int_flag)
{
	int		j;
	char	*value;

	value = NULL;
	while (line[*i])
	{
		if ((line[*i] != ' ' && !ft_isdigit(line[*i]))
			|| (line[*i] == ' ' && int_flag > 0))
			free_all_and_print_exit(data,
				"Error\nCub file data are not valid\n");
		if (ft_isdigit(line[*i]))
			break ;
		(*i)++;
	}
	j = *i;
	while (ft_isdigit(line[j]))
		j++;
	if ((line[j] == ',' && line[j + 1]) || (int_flag == 2 && line[j] == '\0'))
		value = color_protect_substr(data, line, *i, j);
	else
		free_all_and_print_exit(data, "Error\nCub file data are not valid\n");
	if (int_flag != 2)
		j++;
	*i = j;
	return (value);
}

static void	verif_color_flag(t_data *data, char type)
{
	if (type == 'C')
	{
		if (data->map.textures.c_flag == 1)
			free_all_and_print_exit(data, "Error\nToo much colors infos\n");
		data->map.textures.c_flag = 1;
	}
	else if (type == 'F')
	{
		if (data->map.textures.f_flag == 1)
			free_all_and_print_exit(data, "Error\nToo much colors infos\n");
		data->map.textures.f_flag = 1;
	}
}

static void	safe_value_assign(t_data *data, char *value, char type, int *j)
{
	if (type == 'C')
	{
		data->map.textures.ceiling_color[*j] = ft_atoi(value);
		if (data->map.textures.ceiling_color[*j] < 0
			|| data->map.textures.ceiling_color[*j] > 255)
		{
			free(value);
			free_all_and_print_exit(data,
				"Error\nR,G,B colors need be in range [0,255]\n");
		}
	}
	else
	{
		data->map.textures.floor_color[*j] = ft_atoi(value);
		if (data->map.textures.floor_color[*j] < 0
			|| data->map.textures.floor_color[*j] > 255)
		{
			free(value);
			free_all_and_print_exit(data,
				"Error\nR,G,B colors need be in range [0,255]\n");
		}
	}
	(*j)++;
}

void	check_and_parse_fc_colors(t_data *data, char *line, char type)
{
	int		i;
	int		j;
	char	*value;

	j = 0;
	i = 2;
	verif_color_flag(data, type);
	while (line[i])
	{
		value = verif_and_extract(data, &i, line, j);
		if (value)
		{
			safe_value_assign(data, value, type, &j);
			free(value);
		}
	}
}
