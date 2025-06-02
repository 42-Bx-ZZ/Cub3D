/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:09:13 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/02 16:55:22 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	moves(int key, t_data *data)
{
	(void)key;
	(void)data;
	return ;
}

void	view(int key, t_data *data)
{
	(void)key;
	(void)data;
	return ;
}

int keys_hook(int key, t_data *data)
{
    if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		moves(key, data);
    else if (key == L_ARROW || key == R_ARROW)
        view(key, data);
    if (key == ESC)
        clean_exit(data);
    return (0);
}
