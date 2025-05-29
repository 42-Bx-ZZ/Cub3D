/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_colors_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:05:51 by zaiicko           #+#    #+#             */
/*   Updated: 2025/05/29 01:59:48 by zaiicko          ###   ########.fr       */
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
		free_all_and_print_exit(data, "Error\nCub file data are not valid");
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
			free_all_and_print_exit(data, "Error\nCub file data are not valid");
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
		free_all_and_print_exit(data, "Error\nCub file data are not valid");
	if (int_flag != 2)
		j++;
	*i = j;
	return (value);
}

void	check_and_parse_fc_colors(t_data *data, char *line, char type)
{
	int		i;
	int		j;
	char	*value;

	j = 0;
	i = 2;
	while (line[i])
	{
		value = verif_and_extract(data, &i, line, j);
		if (value)
		{
			if (type == 'C')
			{
				data->map.textures.ceiling_color[j] = ft_atoi(value);
				j++;
			}
			else
			{
				data->map.textures.floor_color[j] = ft_atoi(value);
				j++;
			}
			free(value);
		}
	}
}
