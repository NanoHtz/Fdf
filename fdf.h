/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:46:30 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/21 17:20:34 by fgalvez-         ###   ########.fr       */
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
/*Comprobar dimensiones del menu
PORTATIL:
void	print_menu(t_cwin *cw)
{
	mlx_string_put(cw->mlx, cw->window, 50, 50, WHITE, "MENU");
	mlx_string_put(cw->mlx, cw->window, 50, 600, WHITE, "CONTROLS:");
	mlx_string_put(cw->mlx, cw->window, 50, 630, WHITE, "- PRESS SCAPE:");
	mlx_string_put(cw->mlx, cw->window, 165, 630, GREEN, "EXIT");
	mlx_string_put(cw->mlx, cw->window, 50, 660, WHITE, "- CLICK X:");
	mlx_string_put(cw->mlx, cw->window, 135, 660, GREEN, "EXIT");
	mlx_string_put(cw->mlx, cw->window, 50, 690, WHITE, "- SCROLL:");
	mlx_string_put(cw->mlx, cw->window, 130, 690, GREEN, "ZOOM IN/OUT");
	mlx_string_put(cw->mlx, cw->window, 50, 720, WHITE, "- SPACE:");
	mlx_string_put(cw->mlx, cw->window, 120, 720, GREEN, "**********************");
	mlx_string_put(cw->mlx, cw->window, 50, 750, WHITE, "- LEFT CLICK:");
	mlx_string_put(cw->mlx, cw->window, 160, 750, GREEN, "MOVE");
	mlx_string_put(cw->mlx, cw->window, 50, 780, WHITE, "- ARROWS:");
	mlx_string_put(cw->mlx, cw->window, 128, 780, GREEN, "ROTATE X/Y");
	mlx_string_put(cw->mlx, cw->window, 50, 810, WHITE, "- RIGHT CLICK:");
	mlx_string_put(cw->mlx, cw->window, 165, 810, GREEN, "ROTATE Z");
}
42:
*/

//errors
# define MEMORY_ERROR 1 //Errores de memoria
# define ARGS_ERROR 1 //Error en los argumentos
# define FD_ERROR 1 //Error al abrir el archivo
# define MAP_ERROR 1 //Error al leer el mapa
# define ERROR_READING 1 //Error de lectura

//colors
//añadiendo 0x + https://www.color-hex.com/color/eaeaea
# define WHITE 0xEAEAEA //Blanco
# define GREEN 0x58D68D //Verde
# define RED 0xff0000 //Rojo
//Add Minilibx for linux sistem:
# include "minilibx-linux/mlx.h"

//New in this library:
# include <fcntl.h>
# include <X11/keysym.h>

//Add old libraries:
# include "Inc/get_next_line/get_next_line.h"
# include "Inc/libft/libft.h"

typedef struct connectwindow
{
	void	*mlx;
	void	*window;
}				t_cwin;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct			s_dimension
{
	int		x;
	int		y;
	int		total;
}			t_dim;

typedef struct			s_coords
{
	int		x;
	int		y;
	int		z;
}			t_cords;

//menu
void	img_pix_put(t_img *img, int x, int y, int color);
void	draw_menu(t_cwin *cw, t_img *img, int color);
void	print_menu();
void	menu(t_cwin *cw);
//events
void	events(t_cwin *cw);
int		scape(int keysym, t_cwin *win);
int		out(t_cwin *cw);
int		clean_and_close(t_cwin *cw);
//line
void	draw_line(t_cwin *cw, t_img *i, int color);
void	line(t_cwin *cw);

int read_data(void);

#endif
