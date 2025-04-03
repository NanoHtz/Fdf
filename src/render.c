/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:58:42 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/03 09:28:53 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

void	my_pixel_put(t_img *img, t_coord point)
{
	char	*pixel;
	int		x;
	int		y;

	x = round(point.x);
	y = round(point.y);
	if (x < 0 || x >= WIN_W)
		return ;
	if (y < 0 || y >= WIN_H)
		return ;
	pixel = img->addr + y * img->line_len + x * (img->bpp / 8);
	*(int *)pixel = point.color;
}

void	draw_horizontal_lines(t_img *img, t_grid *map, t_coord offset)
{
	int		i;
	t_coord	point;
	t_coord	neighbour_right;
	t_coord	*act;

	i = 0;
	while (i < map->axis_x * map->axis_y)
	{
		if ((i + 1) % map->axis_x != 0)
		{
			act = map->arr + i;
			point = sum_vec(*act, offset);
			neighbour_right = sum_vec(*(act + 1), offset);
			draw_bresenham(img, point, neighbour_right);
		}
		i++;
	}
}

void	draw_vertical_lines(t_img *img, t_grid *map, t_coord offset)
{
	int		i;
	t_coord	point;
	t_coord	neighbour_down;
	t_coord	*act;

	i = 0;
	while (i < map->axis_x * (map->axis_y - 1))
	{
		act = map->arr + i;
		point = sum_vec(*act, offset);
		neighbour_down = sum_vec(*(act + map->axis_x), offset);
		draw_bresenham(img, point, neighbour_down);
		i++;
	}
}

void	fill_row(t_img *img, int y, int color)
{
	int		x;
	t_coord	point;

	x = 0;
	while (x < WIN_W)
	{
		point = (t_coord){x, y, 0, color};
		my_pixel_put(img, point);
		x++;
	}
}

void	fill_layer(t_img *img, int color)
{
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		fill_row(img, y, color);
		y++;
	}
}
