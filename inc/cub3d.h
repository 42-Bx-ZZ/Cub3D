/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:15:33 by zaiicko           #+#    #+#             */
/*   Updated: 2025/07/01 10:26:18 by lowatell         ###   ########.fr       */
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
#  define SHIFT 65505
#  define E 101
#  define L_CLICK 1
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
#  define P 112
#  define SHIFT 65505
#  define E 101
#  define L_CLICK 1
#  define LINUX 0
# endif

# define WIDTH 1200
# define HEIGHT 860
# define CLOSEBTN 17
# define STEP 0.1
# define FOV 60
# define VIEW 0.05
# define RAYS WIDTH
# define HITBOX 0.15
# define QUALITY 100
# define ENNEMY_NBR 2

# if ENNEMY_NBR >= 2147483647 || ENNEMY_NBR <= 0
#  undef ENNEMY_NBR
#  define ENNEMY_NBR 1
#  define SPAWN 0
# else
#  define SPAWN 1
# endif

# include "../libft/inc/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <sys/time.h>

struct			s_data;

typedef struct s_ennemy
{
	int			alive;
	float		x;
	float		y;
	float		dir;
	int			number;
	float		dist;
	int			order[ENNEMY_NBR];
}	t_ennemy;

typedef struct s_dda
{
	int			x;
	int			y;
	float		ray_dir_x;
	float		ray_dir_y;
	float		delta_dist_x;
	float		delta_dist_y;
	int			step_x;
	int			step_y;
	float		side_dist_x;
	float		side_dist_y;
	int			side;
	int			hit_ennemy;
	float		zbuffer[1920];
}	t_dda;

typedef struct s_img
{
	int			*ptr;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			height;
	int			width;
	int			w_width;
	int			w_height;
}	t_img;

typedef struct s_player
{
	int			hp;
	int			money;
	int			earn;
	int			earn_frames;
	int			hit;
	t_img		gun;
}	t_player;

typedef struct s_game
{
	float		p_x;
	float   	p_y;
	float		dir;
	double		dir_x;
	double		dir_y;
	t_dda		dda;
	float		perp_wall;
	float		r_x_fy;
	float		r_y_fy;
	float		rays[2];
}   t_game;

typedef struct s_keys
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			f;
	int			l_arrow;
	int			r_arrow;
	int			shift;
	int			e;
	int			l_click;
}	t_keys;

typedef struct s_textures
{
	char		*north_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
	t_img		north;
	t_img		south;
	t_img		west;
	t_img		east;
	t_img		door;
	t_img		ennemy[2];
	int			floor_color[3];
	int			ceiling_color[3];
	int			frame;
}	t_textures;

typedef struct s_map
{
	char		**setup;
	t_textures	textures;
}	t_map;

typedef	struct	s_fps
{
	int			fps;
	double		start;
}	t_fps;

typedef struct s_data
{
    void    	*mlx;
    void    	*win;
	int			width;
	int			height;
	t_map		map;
	t_img		frame;
	t_game		game;
	t_keys		keys;
	char		**cub_file;
	t_fps		fps;
	t_player	player;
	t_ennemy	ennemies[7];
	float		rand;
}	t_data;

void			get_rand(t_data *data);
int				argb_colors(int a, int rgb[3]);
int				red_filter(int color, t_data *data);
int				ft_tablen(char **map);
void			draw_crosshair(t_data *data);
void			ennemy_moves(t_data *data);
void			draw_enemy(t_data *data, int i);
float			hit_check(t_data *data);
void			door_check(t_data *data);
void			dda(t_data *data, float ray_angle, char **map);
int				get_dda_step(float dir);
int				is_blocked(t_data *data, float x, float y, float hitbox);
void			print_infos(t_data *data);
double			elapsed_time(void);
int				get_frame(int y, int size[2], t_data *data, int r);
t_img			*wall_side(t_data *data);
void			put_pixel_img(t_img *img, int x, int y, int color);
int				update_move(t_data *data);
int				key_press(int key, t_data *data);
int				key_release(int key, t_data *data);
void			raycasting(t_data *data, size_t r);
float			get_dir(char c);
void			moves(int key, t_data *data);
void			view(int key, t_data *data);
void			update_frame(t_data *data, float fov_deg, int nb_rays, char **map);
void			draw_map(t_data *data);
int				load_sprites(t_data *data);
int	    		clean_exit(t_data *data);
char    		**get_map(char *file);
int     		setup_mlx(t_data *data);
int     		keys_hook(int key, t_data *data);
void			check_args(int ac, char **av);
void			extract_all_cub_data(t_data *data, char *file);
void			free_all_data(t_data *data);
void			free_all_and_print_exit(t_data *data, char *msg);
void			check_and_parse_cub_file(t_data *data);
void			check_and_parse_wall_path(t_data *data, char *line, char *type);
void			check_and_parse_fc_colors(t_data *data, char *line, char type);

#endif
