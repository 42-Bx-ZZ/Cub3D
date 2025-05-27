/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:15:33 by zaiicko           #+#    #+#             */
/*   Updated: 2025/05/27 19:10:05 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
#  define UP 119
#  define LEFT 97
#  define DOWN 115
#  define RIGHT 100
#  define ESC 65307
#  define LINUX 1
# else
#  include "../minilibx_opengl_20191021/mlx.h"
#  define UP 13
#  define LEFT 0
#  define RIGHT 2
#  define DOWN 1
#  define ESC 53
#  define LINUX 0
# endif

# define CLOSEBTN 17
# define WIDTH 848
# define HEIGHT 480

# include "../libft/inc/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct s_game
{
    float   p_x;
    float   p_y;
}   t_game;


typedef struct s_textures
{
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	int		floor_color[3];
	int		ceiling_color[3];
}	t_textures;

typedef struct s_map
{
	char		**setup;
	t_textures	textures;
}	t_map;

typedef struct s_data
{
    void    *mlx;
    void    *win;
	t_map	map;
	char	**cub_file;
}	t_data;

int	    clean_exit(t_data *data);
int     setup_mlx(t_data *data);
int     moves(int key, t_data *data);
void	check_args(int ac, char **av);
void	extract_all_cub_data(t_data *data, char *file);
void	free_all_data(t_data *data);
void	free_all_and_print_exit(t_data *data, char *msg);
void	check_and_parse_cub_file(t_data *data);
void	check_and_parse_wall_path(t_data *data, char *line, char *type);
void	check_and_parse_fc_colors(t_data *data, char *line, char type);

#endif
