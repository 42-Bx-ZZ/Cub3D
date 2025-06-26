/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <meskrabe@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:15:33 by zaiicko           #+#    #+#             */
/*   Updated: 2025/06/26 19:24:56 by zaiicko          ###   ########.fr       */
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
# define VALID_CHARS "0 1NSEWD"
# define PLAYER_CHARS "NSEW"

# include "../libft/inc/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct s_textures
{
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	char	*door_path;
	char	*zfront_path;
	char	*zback_path;
	int		floor_color[3];
	int		ceiling_color[3];
	int		c_flag;
	int		f_flag;
}	t_textures;

typedef struct s_map
{
	char		**setup;
	char		player;
	t_textures	textures;
	int			len;
	char		**setup_without_sp;
}	t_map;

typedef struct s_data
{
	t_map	map;
	char	**cub_file;
	int		cub_len;
}	t_data;

void	check_args(int ac, char **av);
void	extract_all_cub_data(t_data *data, char *file);
void	free_all_data(t_data *data);
void	free_all_and_print_exit(t_data *data, char *msg);
void	check_and_parse_cub_file(t_data *data);
void	check_and_parse_wall_path(t_data *data, char *line, char *type);
void	check_and_parse_fc_colors(t_data *data, char *line, char type);
void	check_and_parse_map(t_data *data, int *i);
int		count_map_lenght(t_data *data, int i);
void	check_if_all_cub_data(t_data *data);
char	*check_chars_in_string(char *chars, char *line);
int		count_file_lines(char *file);
void	init_texture_id(char **id);
void	copy_without_space(t_data *data);


#endif
