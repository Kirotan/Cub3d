/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:57:05 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/16 13:43:07 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "MLX42.h"
# include <math.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>

# define PLAYER_ERR "Player error\n"
# define MALLOC_FAIL "Error: malloc failed.\n"
# define LIMIT 150
# define MAP_TOO_LARGE "Map too large\n"
# define BAD_ARG "Bad argument\n"
# define FILE_ERR "Bad map file extension\n"
# define FD_ERR "File descriptor error\n"
# define TEXTURE_ERR "Texture error\n"
# define EMPT_MAP "Empty map\n"
# define COLOR_ERR "Color error\n"
# define UNCLOSED_MAP "Unclosed map\n"
# define MAP_ERR "Map error\n"
# define ERR "Error\n"
# define S_W 1920
# define S_H 1080
# define TILE_SIZE 64
# define FOV 66
# define ROTATION_SPEED 3
# define GAMER_SPEED 110
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define BLUE 0x0000FFFF
# define YELLOW 0xFFFF00FF
# define CYAN 0x00FFFFFF
# define MAGENTA 0xFF00FFFF
# define GREY 0x808080FF
# define ORANGE 0xFFA500FF
# define BROWN 0xA52A2AFF
# define PINK 0xFFC0CBFF
# define PURPLE 0x800080FF

typedef struct s_gamer
{
	double		gmr_x;
	double		gmr_y;
	double		angle;
	float		fov_rd;
	int			rot;
	int			l_r;
	int			u_d;
}		t_gamer;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_ray
{
	int		index;
	double	ray_angle;
	double	distance;
	bool	inter_v_bigger;
	double	horiz_x;
	double	horiz_y;
	double	vert_x;
	double	vert_y;
	double	dist_prjc_plane;
	double	prjc_wall_hei;
}		t_ray;

typedef struct s_texture
{
	mlx_texture_t	*path_no;
	mlx_texture_t	*path_so;
	mlx_texture_t	*path_we;
	mlx_texture_t	*path_ea;
}		t_texture;

typedef struct s_data
{
	char		**map2d;
	int			p_x;
	int			p_y;
	int			w_map;
	int			h_map;
	t_texture	tex;
	int32_t		color_f;
	int32_t		color_c;
}		t_data;

typedef struct s_mlx
{
	mlx_image_t	*img;
	mlx_t		*mlx_p;
	t_ray		*ray;
	t_data		*dt;
	t_gamer		*gmr;
}		t_mlx;

int				calc_x1(t_mlx *mlx);
int				calc_y1(t_mlx *mlx);
int				calc_sx(t_mlx *mlx, int x0);
int				calc_sy(t_mlx *mlx, int y0);
int				stop(int x0, int y0, t_mlx *mlx);
void			bresenham(int x0, int y0, int e2, t_mlx *mlx);
t_point			next_0(char **tab);
void			fill(char **tab, t_point size, t_point cur, char to_fill);
bool			is_0_again(char **tab);
int				longest_line(char **map);
void			check_map(char **map, t_data *data);
void			flood_fill(char **tab, t_point size);
void			check_tile(char **map, int i);
void			check_text(t_data data);
int				wall_text(char *str);
double			minmap_w(int a);
double			minmap_h(int a);
void			refill_map(t_data *data);
void			display_min_map(t_mlx *mlx);
void			power_on(t_data *dt);
void			init_gamer(t_mlx *mlx);
void			game_loop(void *the_mlx);
void			movement(mlx_key_data_t mov, void *param);
void			display_background(t_mlx *mlx);
void			draw_wall_square(t_mlx *mlx, int x, int y, int color);
void			display_gamer(t_mlx *mlx);
void			draw_circle(t_mlx *mlx, int x0, int y0, int size);
void			display_map(t_mlx *mlx);
void			norm_angle(double *angle);
void			normalize_angle(t_mlx *mlx);
void			gamer_movement(t_mlx *mlx);
void			ft_free_all(t_mlx *mlx);
void			cast_rays(t_mlx *mlx);
double			inter_horiz(t_mlx *mlx);
double			inter_verti(t_mlx *mlx);
void			fill_map_param(t_data *data);
t_data			fill_data(char *filename);
t_data			parser(int ac, char **av);
int				ft_error(char *msg_err);
int				get_color(t_mlx *mlx, int flag);
int				open_map(char *filename);
t_data			init_data(void);
char			**fill_tab(char *str, int fdname);
void			check_gnl(char *str, int fdname);
void			check_filename(char *filename);
void			extract_data(char *str, t_data *data, int fd);
int32_t			convert_color(int *tab_color);
double			wall_or_not(t_mlx *mlx, double coord_x, double coord_y);
int				collision_management(t_mlx *mlx, double move_x, double move_y);
void			display_image(t_mlx *mlx, int i);
void			mlx_security(t_mlx *mlx, int x, int y, int32_t color);
double			wall_or_not(t_mlx *mlx, double coord_x, double coord_y);
int				inter_check(double angle, double *inter,
					double *dist, int horizon);
int				circle(double angle, char c);
mlx_texture_t	*cardinal_texture(t_mlx *mlx);
int				reverse_bytes(int byte);
double			get_horiz_tex(t_mlx *mlx, mlx_texture_t *texture);

#endif
