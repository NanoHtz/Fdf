/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:58:42 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/28 10:21:25 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

void	img_pix_put(t_img *img, t_cds point)
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

void	draw_map(t_img *img, t_map *map, t_cds offset)
{
	int		i;
	t_cds	point;
	t_cds	neighbour_right;
	t_cds	neighbour_down;
	t_cds	*act;

	i = 0;
	if (map->arr == NULL || map->axis_x <= 0 || map->axis_y <= 0)
	{
		ft_putstr_fd("Error: Invalid map data.\n", 2);
		return ;
	}
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
			img_pix_put(img, (t_cds){j, i, 0, color});
			j++;
		}
		i++;
	}
}

void	render_instructions(t_content *content, int color)
{
	mlx_string_put(content->mlx, content->window, 30, 30,
		color, "Zoom: Keypad +, -");
	mlx_string_put(content->mlx, content->window, 30, 50,
		color, "Translate: Up, Down, Left, Right");
	mlx_string_put(content->mlx, content->window, 30, 70,
		color, "Rotate: W, A, S, D");
	mlx_string_put(content->mlx, content->window, 30, 90,
		color, "Change Height: J, K");
	mlx_string_put(content->mlx, content->window, 30, 110,
		color, "Reset Isometric View: R");
	mlx_string_put(content->mlx, content->window, 30, 130,
		color, "Top View: T");
	mlx_string_put(content->mlx, content->window, 30, 150,
		color, "Animate: Space");
}
