/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:48:27 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/01 19:48:27 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

void	restore_map(t_core *content)
{
	int			i;

	i = 0;
	while (i < content->render_map->axis_x * content->render_map->axis_y)
	{
		*(content->render_map->arr + i) = *(content->map_backup->arr + i);
		i++;
	}
	content->render_map->i = (t_coord){1, 0, 0, 0x0};
	content->render_map->j = (t_coord){0, 1, 0, 0x0};
	content->render_map->k = (t_coord){0, 0, 1, 0x0};
	color_gradient(content->render_map, content->palette_id);
}

void	scale_z(t_core *content, float_t factor)
{
	t_mrot	scale_z;
	t_mrot	tmp;
	t_grid	*map;

	map = content->render_map;
	tmp = (t_mrot){map->i.x, map->i.y, map->i.z,
		map->j.x, map->j.y, map->j.z,
		map->k.x, map->k.y, map->k.z};
	scale_z = (t_mrot){1, 0, 0, 0, 1, 0, 0, 0, factor};
	restore_map(content);
	change_map(scale_z, map);
	change_map(tmp, map);
}

void	translate(t_grid *map, t_coord offset)
{
	int		i;
	t_coord	*cur;

	i = 0;
	while (i < map->axis_x * map->axis_y)
	{
		cur = map->arr + i;
		*cur = vec_add(*cur, offset);
		i++;
	}
}

void	render_instructions(t_core *content, int color)
{
	mlx_string_put(content->mlx, content->window, WIN_W - 1250, WIN_H - 30,
		color, "Zoom: Keypad z, x");
	mlx_string_put(content->mlx, content->window, WIN_W - 1100, WIN_H - 30,
		color, "Translate: Up, Down, Left, Right");
	mlx_string_put(content->mlx, content->window, WIN_W - 850, WIN_H - 30,
		color, "Rotate: W, A, S, D");
	mlx_string_put(content->mlx, content->window, WIN_W - 700, WIN_H - 30,
		color, "Change Height: J, K");
	mlx_string_put(content->mlx, content->window, WIN_W - 500, WIN_H - 30,
		color, "Reset Isometric View: R");
	mlx_string_put(content->mlx, content->window, WIN_W - 300, WIN_H - 30,
		color, "Top View: T");
	mlx_string_put(content->mlx, content->window, WIN_W - 200, WIN_H - 30,
		color, "Animate: Space");
	mlx_string_put(content->mlx, content->window, WIN_W - 100, WIN_H - 30,
		color, "Color mode: N");
}
