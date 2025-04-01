/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:58:42 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/01 19:55:50 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

void	img_pix_put(t_img *img, t_coord point)
{
	char	*pixel;
	int		x;
	int		y;

	x = round(point.x);
	y = round(point.y);
	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	pixel = img->addr + y * img->line_len + x * (img->bpp / 8);
	*(int *)pixel = point.color;
}

void	draw_map(t_img *img, t_grid *map, t_coord offset)
{
	int		i;
	t_coord	point;
	t_coord	neighbour_right;
	t_coord	neighbour_down;
	t_coord	*act;

	i = 0;
	if (map->arr == NULL || map->axis_x <= 0 || map->axis_y <= 0)
		return (ft_report_void(MAP_D));
	while (i < map->axis_x * map->axis_y)
	{
		act = map->arr + i;
		point = vec_add(*act, offset);
		if ((i + 1) % map->axis_x != 0)
		{
			neighbour_right = vec_add(*(act + 1), offset);
			draw_line(img, point, neighbour_right);
		}
		if (i < map->axis_x * (map->axis_y - 1))
		{
			neighbour_down = vec_add(*(act + map->axis_x), offset);
			draw_line(img, point, neighbour_down);
		}
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
			img_pix_put(img, (t_coord){j, i, 0, color});
			j++;
		}
		i++;
	}
}
