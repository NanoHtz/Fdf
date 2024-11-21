/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:28:34 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/12 17:39:23 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pix_put(t_img *i, int x, int y, int color)
{
	char	*pixel;

	pixel = i->addr + (y * i->line_len + x * (i->bpp / 8));
	*(int *)pixel = color;
}

void	draw_menu(t_cwin *cw, t_img *i, int color)
{
	int	x;
	int	y;

	i->mlx_img = mlx_new_image(cw->mlx, W_MENU, HEIGHT);
	i->addr = mlx_get_data_addr(i->mlx_img, &i->bpp, &i->line_len, &i->endian);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < W_MENU)
		{
			img_pix_put(i, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cw->mlx, cw->window, i->mlx_img, 0, 0);
	mlx_destroy_image(cw->mlx, i->mlx_img);
}

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
void	menu(t_cwin *cw)
{
	t_img		i;
	char		*font;

	font = "-sony-fixed-medium-r-normal--16-120-100-100-c-80-jisx0201.1976-0";//New font
	mlx_set_font(cw->mlx, cw->window, font);
	draw_menu(cw, &i, 0x323232);
	print_menu(cw);
}
