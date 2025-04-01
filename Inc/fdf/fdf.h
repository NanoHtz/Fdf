/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:46:30 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/01 19:58:55 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define HEIGHT 988 //1995 Altura 988 portatil
# define WIDTH 1905 //3840 Anchura 1905 POrtatil
# define W_MENU 300 //300 Anchura Menu
# define HCENTER 449 //998 ANCHURA CENTRO, 499 portatil
# define WCENTER 960 //1920 Altura Centro, 960 portatil
# define WIN_W	1280
# define WIN_H	720
# define WHITE 0xEAEAEA //Blanco
# define GREEN 0x58D68D //Verde
# define RED 0xff0000 //Rojo
# define PURPLE 0x00FF0000
# define LOW_PURPLE 0x00000066
# define HIGH_PURPLE 0x00B491C8
# define BLACK 0x020202 //Blanco
# define ISO	0.6154
# define COLOR_1  0x000080
# define COLOR_2  0x00BFFF
# define COLOR_3  0x228B22
# define COLOR_4  0xCD853F
# define COLOR_5  0xFFFFFF
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
}			t_core;

typedef struct s_context
{
	t_core		*content;
	t_grid		*map;
	t_coord		point;
	int			i;
}				t_context;


//read_data
int		read_data(t_core	*content, char *filename);
char	*work_on_file(int fd, t_core *content);
void	parse_line(char *str);
char	**ft_parse_and_split(char *str);
void	free_arr(char **arr);

//work_on_file
int		columns(char *str);
int		lines_consistent(int c, t_core *content);
void	add_line(char **line, char **file);

//make_map
t_grid	*make_map(t_core *content);
void	points_on_map(t_core *content, t_grid *map);
void	color_gradient(t_grid *map);
t_grid	*save_original_map(t_core *content);

//points_on_map
void	process_row(t_context *ctx);
void	process_point(t_coord *act, t_context *ctx, int index);
void	values(t_grid *map, t_core *content, t_coord *point);
void	z_range(t_grid *map, t_coord *act);

//color_gradient
t_limits	calculate_limits(int min_z, int max_z);
int	get_color_by_z(t_coord act, int min_z, int max_z, t_limits l);
int		gradient(t_coord act, t_coord base, t_coord final);

//color_utils
float_t	percent(int base, int final, int act);
int		calc_color(int base, int final, float_t percent);

//isometric
void	isometric(t_grid *map);
void	rot_y(float_t angle, t_grid *map);
void	rot_x(float_t angle, t_grid *map);

//scale
void	scale(t_grid *map);
void	maxs_and_mins(t_grid *map);
void	zoom(t_grid *map, float_t factor);
//mlx
int		start_mlx(t_core *cw);
int		loop_hook(t_core *content);
int		close_app(t_core *content);
int		key_hook1(int keysym, t_core *content);

//draw.c
void	render_background(t_img *img, int color);
void	draw_map(t_img *img, t_grid *map, t_coord offset);
void	img_pix_put(t_img *img, t_coord point);

//maths
t_coord	vector_multiplication(t_mrot matrix, t_coord point);
t_coord	vec_add(t_coord pt1, t_coord pt2);
t_coord	vec_sub(t_coord pt1, t_coord pt2);

//line
int		draw_line(t_img *img, t_coord start, t_coord end);
int		draw_line_low(t_img *img, t_coord start, t_coord end);
int		draw_line_high(t_img *img, t_coord start, t_coord end);

//make_color
int		make_color(t_coord act, t_coord base, t_coord final, t_coord gamma);

//utils
t_grid	*change_map(t_mrot rot, t_grid *map);

//Bonus
void	scale_z(t_core *content, float_t factor);
void	render_instructions(t_core *content, int color);
void	translate(t_grid *map, t_coord offset);
int		key_hook2(int keysym, t_core *content);
void	restore_map(t_core *content);

#endif
