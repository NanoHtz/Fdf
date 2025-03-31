/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:46:30 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/03/31 12:25:59 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//dimensions
# define HEIGHT 988 //1995 Altura 988 portatil
# define WIDTH 1905 //3840 Anchura 1905 POrtatil
# define W_MENU 300 //300 Anchura Menu
# define HCENTER 449 //998 ANCHURA CENTRO, 499 portatil
# define WCENTER 960 //1920 Altura Centro, 960 portatil
# define WIN_W	1280
# define WIN_H	720

//añadiendo 0x + https://www.color-hex.com/color/eaeaea
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

//Add Minilibx for linux sistem:
# include "../../minilibx-linux/mlx.h"

//New in this library:
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>

//Add old libraries:
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

typedef struct s_m_rotacional
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
}			t_mrotacional;

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
}			t_cds;

typedef struct s_map
{
	int		axis_y;
	int		axis_x;
	t_cds	i;
	t_cds	j;
	t_cds	k;
	t_cds	*arr;
	int		space;
	int		max_z;
	int		min_z;
	int		y_max;
	int		y_min;
	int		x_max;
	int		x_min;

}			t_map;

typedef struct s_content
{
	void	*mlx;
	void	*window;
	t_map	*map;
	char	**fixed_file;
	int		animate_on;
	t_img	img;
	t_map	*original_map;
}			t_content;

typedef struct s_context
{
	t_content	*content;
	t_map		*map;
	t_cds		point;
	int			i;
}				t_context;

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		read_data(t_content	*content, char *filename);
int		make_color(t_cds act, t_cds base, t_cds final, t_cds gamma);
void	isometric(t_map *map);
void	free_arr(char **arr);
t_map	*make_map(t_content *content);
t_map	*change_map(t_mrotacional rot, t_map *map);
void	scale(t_map *map);
int		start_mlx(t_content *cw);
int		key_hook1(int keysym, t_content *content);
int		close_app(t_content *content);
int		loop_hook(t_content *content);
void	img_pix_put(t_img *img, t_cds point);
void	render_background(t_img *img, int color);
void	draw_map(t_img *img, t_map *map, t_cds offset);
t_cds	vec_add(t_cds pt1, t_cds pt2);
t_cds	vec_sub(t_cds pt1, t_cds pt2);
int		draw_line_low(t_img *img, t_cds start, t_cds end);
int		draw_line_high(t_img *img, t_cds start, t_cds end);
int		draw_line(t_img *img, t_cds start, t_cds end);
int		gradient(t_cds act, t_cds base, t_cds final);
void	maxs_and_mins(t_map *map);
void	zoom(t_map *map, float_t factor);
void	rot_y(float_t angle, t_map *map);
void	rot_x(float_t angle, t_map *map);
t_cds	vector_multiplication(t_mrotacional matrix, t_cds point);
char	*work_on_file(int fd, t_content *content);
int		lines_consistent(int c, t_content *content);
void	add_line(char **line, char **file);
float_t	percent(int base, int final, int act);
int		calc_color(int base, int final, float_t percent);
int		columns(char *str);
void	free_arr(char **arr);
void	put_space(unsigned int i, char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	points_on_map(t_content *content, t_map *map);
void	color_gradient(t_map *map);
t_map	*save_original_map(t_content *content);
void	restore_map(t_content *content);
void	z_range(t_map *map, t_cds *act);
int		draw_line(t_img *img, t_cds start, t_cds end);
t_cds	vector_multiplication(t_mrotacional matrix, t_cds point);
t_cds	vec_sub(t_cds pt1, t_cds pt2);
t_cds	vec_add(t_cds pt1, t_cds pt2);
void	render_instructions(t_content *content, int color);
void	translate(t_map *map, t_cds offset);
int		key_hook2(int keysym, t_content *content);
void	scale_z(t_content *content, float_t factor);

#endif
