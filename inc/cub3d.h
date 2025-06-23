/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:15:33 by zaiicko           #+#    #+#             */
/*   Updated: 2025/06/23 08:08:55 by lowatell         ###   ########.fr       */
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
#  define L_ARROW 65361
#  define R_ARROW 65363
#  define P 112
#  define LINUX 1
# else
#  include "../minilibx_opengl_20191021/mlx.h"
#  define UP 13
#  define LEFT 0
#  define RIGHT 2
#  define DOWN 1
#  define ESC 53
#  define L_ARROW 123
#  define R_ARROW 124
#  define LINUX 0
# endif

# define CLOSEBTN 17
# define WIDTH 1280
# define HEIGHT 720
# define STEP 0.1
# define FOV 60
# define VIEW 0.1
# define RAYS WIDTH
# define HITBOX 0.15

# include "../libft/inc/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

typedef struct s_img
{
	int		*ptr;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_game
{
    float   p_x;
    float   p_y;
	float	dir;
	double	dir_x;
	double	dir_y;
	float	rays[4];
}   t_game;

typedef struct s_keys
{
	int		up;
	int		down;
	int		left;
	int		right;
	int		f;
	int		l_arrow;
	int		r_arrow;
}	t_keys;

typedef struct s_textures
{
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
	t_img	m_wall;
	t_img	m_player;
	t_img	m_floor;
	int		floor_color[3];
	int		ceiling_color[3];
}	t_textures;

typedef struct s_map
{
	char		**setup;
	t_textures	textures;
}	t_map;

typedef	struct	s_fps
{
	int		fps;
	double	last;
	double	now;
}	t_fps;

typedef struct s_data
{
    void    *mlx;
    void    *win;
	t_map	map;
	t_img	frame;
	t_game	game;
	t_keys	keys;
	char	**cub_file;
	t_fps	fps;
}	t_data;

int		is_blocked(t_data *data, float x, float y);
void	print_fps(t_data *data);
double	elapsed_time(void);
int		get_frame(int y, int size[2], t_data *data, int r);
t_img	*wall_side(t_data *data);
void	put_pixel_img(t_img *img, int x, int y, int color);
int		update_move(t_data *data);
int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);
void	raycasting(t_data *data, float ray_angle, int r);
float	get_dir(char c);
void	moves(int key, t_data *data);
void	view(int key, t_data *data);
void	draw_view(t_data *data, float fov_deg, int nb_rays, char **map);
void	draw_map(t_data *data);
int		load_sprites(t_data *data);
int	    clean_exit(t_data *data);
char    **get_map(char *file);
int     setup_mlx(t_data *data);
int     keys_hook(int key, t_data *data);
void	check_args(int ac, char **av);
void	extract_all_cub_data(t_data *data, char *file);
void	free_all_data(t_data *data);
void	free_all_and_print_exit(t_data *data, char *msg);
void	check_and_parse_cub_file(t_data *data);
void	check_and_parse_wall_path(t_data *data, char *line, char *type);
void	check_and_parse_fc_colors(t_data *data, char *line, char type);

#endif
