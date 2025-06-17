/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:23:18 by lowatell          #+#    #+#             */
/*   Updated: 2025/06/17 20:10:07 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	view(int key, t_data *data)
{
	if (key != R_ARROW && key != L_ARROW)
		return ;
	if (key == R_ARROW)
		data->game.dir += VIEW;
	if (key == L_ARROW)
		data->game.dir -= VIEW;
}
