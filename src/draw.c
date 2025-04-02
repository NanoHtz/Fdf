/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:58:42 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/02 13:25:09 by fgalvez-         ###   ########.fr       */
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
			point = vec_add(*act, offset);
			neighbour_right = vec_add(*(act + 1), offset);
			draw_line(img, point, neighbour_right);
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
		point = vec_add(*act, offset);
		neighbour_down = vec_add(*(act + map->axis_x), offset);
		draw_line(img, point, neighbour_down);
		i++;
	}
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			my_pixel_put(img, (t_coord){j, i, 0, color});
			j++;
		}
		i++;
	}
}
