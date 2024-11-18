/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:46:30 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/12 19:09:21 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//numbers
# define HEIGHT 1995 //2000 Altura 988 portatil
# define WIDTH 3840 //1080 Anchura 1905 POrtatil
# define W_MENU 300 //300 Anchura Menu
# define HCENTER 998
# define WCENTER 1920
# define PRUEBA0 100
# define PRUEBA1 100

//errors
# define MEMORY_ERROR 1 //Errores de memoria
# define ARGS_ERROR 1 //Error en los argumentos
# define FD_ERROR 1 //Error al abrir el archivo

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

#endif
