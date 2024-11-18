/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:28:34 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/12 19:09:56 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*

	Mucho cuidado al usar imagenes, puede dar segmentation fault, si lo que quieres imprimir es mas grande que tu imagen.
	Este es un archivo de prueba básico.

*/
void	draw_line(t_cwin *cw, t_img *im, int color)
{
	int	x;
	int	y;

	im->mlx_img = mlx_new_image(cw->mlx, 100, 100);
	im->addr = mlx_get_data_addr(im->mlx_img, &im->bpp, &im->line_len, &im->endian);
	y = 50;
	x = 0;
	while (x < 100)
	{
		img_pix_put(im, x, y, color);
		x++;
	}
	x = 50;
	y = 0;
	while (y < 100)
	{
		img_pix_put(im, x, y, color);
		y++;
	}
	mlx_put_image_to_window(cw->mlx, cw->window, im->mlx_img, WCENTER, HCENTER);
	mlx_destroy_image(cw->mlx, im->mlx_img);
}

void	line(t_cwin *cw)
{
	t_img		im;
	
	draw_line(cw, &im, RED);
}