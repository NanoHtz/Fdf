/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:46:30 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/04 18:06:14 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_W	2000 //1920 Altura Centro, 960 portatil
# define WIN_H	1000 //998 ANCHURA CENTRO, 499 portatil
# define WHITE 0xEAEAEA //Blanco
# define PURPLE 0x00FF0000
# define BLACK 0x020202 //Blanco
# define ISO	0.6154
# include "../../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "errors.h"

typedef struct s_limits
{
	int	l1;
	int	l2;
	int	l3;
	int	l4;
}	t_limits;

typedef struct s_mrot
{
	float_t		i1j1;
	float_t		i1j2;
	float_t		i1j3;
	float_t		i2j1;
	float_t		i2j2;
	float_t		i2j3;
	float_t		i3j1;
	float_t		i3j2;
	float_t		i3j3;
}			t_mrot;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_dimension
{
	int		x;
	int		y;
	int		total;
}			t_dim;

typedef struct s_coords
{
	float		x;
	float		y;
	float		z;
	int			color;
}			t_coord;

typedef struct s_map
{
	int		axis_y;
	int		axis_x;
	t_coord	i;
	t_coord	j;
	t_coord	k;
	t_coord	*arr;
	int		dist;
	int		max_z;
	int		min_z;
	int		y_max;
	int		y_min;
	int		x_max;
	int		x_min;

}			t_grid;

typedef struct s_core
{
	void	*mlx;
	void	*window;
	t_grid	*render_map;
	char	**parsed_map;
	int		ani_flag;
	t_img	canvas;
	t_grid	*map_backup;
	int		color_mode;
	int		palette_id;
}			t_core;

typedef struct s_context
{
	t_core		*content;
	t_grid		*map;
	t_coord		point;
	int			i;
}				t_context;

typedef struct s_palette
{
	int	c1;
	int	c2;
	int	c3;
	int	c4;
	int	c5;
	int	c6;
}	t_palette;

int			read_data(t_core	*content, char *filename);
char		*work_on_file(int fd, t_core *content);
int			read_lines(int fd, char **file, t_core *content);
int			process_line(char **line, char **file, t_core *content);
void		parse_line(char *str);
char		**ft_parse_and_split(char *str);
void		free_arr(char **arr);
int			columns(char *str);
int			lines_consistent(int c, t_core *content);
void		add_line(char **line, char **file);
t_grid		*make_map(t_core *content);
void		points_on_map(t_core *content, t_grid *map);
void		color_gradient(t_grid *map, int palette_id);
t_palette	get_palette(int id);
t_grid		*save_grid(t_core *content);
void		process_row(t_context *ctx);
void		process_point(t_coord *act, t_context *ctx, int index);
void		values(t_grid *map, t_core *content, t_coord *point);
void		z_range(t_grid *map, t_coord *act);
void		color_mode(t_core *content);
t_limits	calculate_limits(int min_z, int max_z);
void		setup_hooks(t_core *con);
int			get_color_by_z(t_coord act, int min_z, int max_z, t_palette p);
int			gradient(t_coord act, t_coord base, t_coord final);
void		init_canvas(t_img *canvas, void *mlx);
float_t		get_percentage(int base, int final, int act);
int			interpolate_color(int base, int final, float_t percent);
void		isometric(t_grid *map);
void		restart(t_core *content);
void		rot_y(float_t angle, t_grid *map);
void		transform(t_core *content);
void		rot_x(float_t angle, t_grid *map);
void		scale(t_grid *map);
float_t		compute_final_scale(t_grid *map);
float_t		compute_axis_scale(float_t min, float_t max, int window_size);
void		maxs_and_mins(t_grid *map);
void		zoom(t_grid *map, float_t factor);
int			start_mlx(t_core *cw);
int			loop_hook(t_core *content);
int			fdf_esc(t_core *content);
int			controls_1(int keysym, t_core *content);
void		fill_layer(t_img *img, int color);
void		fill_row(t_img *img, int y, int color);
void		draw_vertical_lines(t_img *img, t_grid *map, t_coord offset);
void		draw_horizontal_lines(t_img *img, t_grid *map, t_coord offset);
void		my_pixel_put(t_img *img, t_coord point);
float		ft_fabsf(float x);
float		add(float a, float b);
float		subtract(float a, float b);
t_coord		mult_vec(t_mrot matrix, t_coord point);
t_coord		sum_vec(t_coord pt1, t_coord pt2);
t_coord		diff_vec(t_coord pt1, t_coord pt2);
int			draw_bresenham(t_img *img, t_coord start, t_coord end);
int			draw_l(t_img *img, t_coord start, t_coord end);
int			draw_h(t_img *img, t_coord start, t_coord end);
int			make_color(t_coord act, t_coord base, t_coord final, t_coord gamma);
void		rotate_canonic(t_grid *grid, t_mrot rot);
t_grid		*change_map(t_mrot rot, t_grid *map);
void		scale_z(t_core *content, float_t factor);
void		display_menu(t_core *content, int color);
void		move(t_grid *map, t_coord offset);
void		color_mode(t_core *content);
int			controls_2(int keysym, t_core *content);
void		restore_map(t_core *content);
void		free_all(t_core *content);
int			init_mlx(t_core *con);
int			create_window(t_core *con);

#endif
