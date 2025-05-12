/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:29:57 by zaiicko           #+#    #+#             */
/*   Updated: 2025/05/12 01:57:33 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	*clean_exit(void)
{
	exit(2);
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;

	(void)ac;
	(void)av;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 200, 200, "test");
	if (!win)
		printf("LOL");
	mlx_hook(win, CLOSEBTN, 0, (void *)clean_exit, NULL);
	mlx_loop(mlx);
}
