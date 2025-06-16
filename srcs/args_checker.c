/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 02:27:07 by zaiicko           #+#    #+#             */
/*   Updated: 2025/06/16 09:52:49 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_args(int ac, char **av)
{
	if (ac == 2 && ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4) == 0)
		return ;
	else
		ft_print_exit("Error\nWrong arguments : ./cub3d <maps/map1.cub>");
}
