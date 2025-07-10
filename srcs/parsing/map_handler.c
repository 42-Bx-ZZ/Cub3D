/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 01:23:10 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/10 10:03:18 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	extract_map(t_data *data, int *i)
{
	int	j;

	j = 0;
	data->map.len = count_map_lenght(data, *i);
	data->map.setup = (char **)malloc(sizeof(char *) * (data->map.len + 1));
	if (!data->map.setup)
		free_all_and_print_exit(data, "Error\nMalloc failed\n");
	while (j < data->map.len)
	{
		data->map.setup[j] = ft_strdup(data->cub_file[*i]);
		if (!data->map.setup[j])
			free_all_and_print_exit(data, "Error\nMalloc failed\n");
		j++;
		(*i)++;
	}
	data->map.setup[j] = NULL;
	(*i)--;
}

static void	verif_if_valid_char(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.setup[i])
	{
		j = 0;
		while (data->map.setup[i][j])
		{
			ft_printf("%c\n", data->map.setup[i][j]);
			if (!ft_strchr(VALID_CHARS, data->map.setup[i][j]))
				free_all_and_print_exit(data, "Error\nWrong char in map\n");
			j++;
		}
		i++;
	}
}

char	*check_chars_in_string(char *chars, char *line)
{
	int		i;
	char	*first_char;

	i = 0;
	while (line[i])
	{
		first_char = ft_strchr(chars, line[i]);
		if (first_char)
			return (line + i);
		i++;
	}
	return (NULL);
}

static void	check_player(t_data *data)
{
	int		i;
	char	*player;
	char	*tmp;

	i = 0;
	while (data->map.setup[i])
	{
		player = check_chars_in_string(PLAYER_CHARS, data->map.setup[i]);
		if (player && data->map.player)
			free_all_and_print_exit(data, "Error\nToo much players\n");
		if (player)
		{
			tmp = check_chars_in_string(PLAYER_CHARS, player + 1);
			if (tmp)
				free_all_and_print_exit(data, "Error\nToo much players\n");
			data->map.player = *player;
			data->map.y_player = i;
			data->map.x_player = player - data->map.setup[i];
		}
		i++;
	}
	if (!data->map.player)
		free_all_and_print_exit(data, "Error\nNeed a player\n");
}

void	check_and_parse_map(t_data *data, int *i)
{
	extract_map(data, i);
	verif_if_valid_char(data);
	check_player(data);
	copy_without_space(data);
	check_if_finishable(data);
}
