/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:09:13 by lowatell          #+#    #+#             */
/*   Updated: 2025/05/28 17:40:19 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int moves(int key, t_data *data)
{
    if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
    {
        printf("move\n");
    }
    else if (key == L_ARROW || key == R_ARROW)
    {
        printf("view\n");
    }
    if (key == ESC)
        clean_exit(data);
    return (0);
}
