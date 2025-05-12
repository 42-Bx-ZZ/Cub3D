/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:29:57 by zaiicko           #+#    #+#             */
/*   Updated: 2025/05/12 23:28:38 by zaiicko          ###   ########.fr       */
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
	t_data	data;

	(void)ac;
	(void)av;
	ft_memset(&data, 0, sizeof(t_data));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 200, 200, "test");
	if (!win)
		printf("LOL");
	mlx_hook(win, CLOSEBTN, 0, (void *)clean_exit, NULL);
	mlx_loop(mlx);
}
