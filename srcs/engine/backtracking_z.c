/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_z.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:33:38 by lowatell          #+#    #+#             */
/*   Updated: 2025/07/09 00:46:10 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	is_valid_char(char c)
{
	return (c == 'E' || c == 'S' || c == 'N'
		|| c == 'W' || c == 'Z' || c == '0' || c == 'P');
}

char	**map_copy(char **tab)
{
	char	**map;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		map[i] = ft_strdup(tab[i]);
		if (!map[i])
			return (ft_free_tab(map), NULL);
		i++;
	}
	map[i] = 0;
	return (map);
}

void	backtracking(char **map, int x, int y)
{
	map[x][y] = 'A';
	if (is_valid_char(map[x][y + 1]))
		backtracking(map, x, y + 1);
	if (y > 0)
		if (is_valid_char(map[x][y - 1]))
			backtracking(map, x, y - 1);
	if (is_valid_char(map[x + 1][y]))
		backtracking(map, x + 1, y);
	if (x > 0)
		if (is_valid_char(map[x - 1][y]))
			backtracking(map, x - 1, y);
}

int	check_way(char **map, int y, int x, t_data *data)
{
	char	**n_map;
	int		i;
	int		j;

	n_map = 0;
	n_map = map_copy(map);
	if (!n_map)
		return (clean_exit(data), 0);
	backtracking(n_map, y, x);
	i = 0;
	while (n_map[i])
	{
		j = -1;
		while (n_map[i][++j])
			if (n_map[i][j] == 'E' || n_map[i][j] == 'W'
				|| n_map[i][j] == 'S' || n_map[i][j] == 'N'
				|| n_map[i][j] == 'P')
				return (ft_free_tab(n_map), 0);
		i++;
	}
	ft_free_tab(n_map);
	return (1);
}
