/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:30:01 by lowatell          #+#    #+#             */
/*   Updated: 2025/05/28 17:27:41 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void    clear_nl(char ***map)
{
    size_t  i;
    size_t  j;

    if (!map || !*map || !**map)
        return ;
    i = 0;
    while ((*map)[i])
    {
        j = 0;
        while ((*map)[i][j])
        {
            if ((*map)[i][j] == '\n')
                (*map)[i][j] = '\0';
            j++;
        }
        i++;
    }
}

size_t  map_size(char *file)
{
    size_t  i;
    int     fd;
    char    *tmp;

    tmp = NULL;
    if (!file)
        return (0);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    i = 0;
    while (1)
    {
        tmp = get_next_line(fd);
        if (!tmp)
            break ;
        i++;
        free(tmp);
        tmp = NULL;
    }
    close(fd);
    return (i);
}

char    **get_map(char *file)
{
    char    **map;
    size_t  i;
    size_t  len;
    int     fd;

    map = NULL;
    if (!file)
        return (NULL);
    i = 0;
    len = map_size(file);
    map = (char **)malloc(sizeof(char *) * (len + 1));
    if (!map)
        return (NULL);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (ft_free_tab(map), NULL);
    while (i < len)
    {
        map[i] = get_next_line(fd);
        if (!map[i])
            return (ft_free_tab(map), close(fd), NULL);
        i++;
    }
    map[i] = NULL;
    return (clear_nl(&map), close(fd), map);
}
