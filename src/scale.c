/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:47:21 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/02 16:56:32 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

void	zoom(t_grid *map, float_t factor)
{
	t_mrot	scale;

	ft_memset(&scale, 0, sizeof(t_mrot));
	scale.i1j1 = factor;
	scale.i2j2 = factor;
	scale.i3j3 = factor;
	change_map(scale, map);
}

void	maxs_and_mins(t_grid *map)
{
	int		total;
	int		idx;
	t_coord	point;

	idx = 0;
	total = map->axis_x * map->axis_y;
	while (idx < total)
	{
		point = map->arr[idx];
		map->x_min = fminf(map->x_min, point.x);
		map->x_max = fmaxf(map->x_max, point.x);
		map->y_min = fminf(map->y_min, point.y);
		map->y_max = fmaxf(map->y_max, point.y);
		idx++;
	}
}

float_t	compute_axis_scale(float_t min, float_t max, int window_size)
{
	float_t	range;

	range = fmaxf(fabsf(min), fabsf(max));
	if (range == 0)
		return (1.0);
	return ((window_size / 2.0f - 30.0f) / range);
}

float_t	compute_final_scale(t_grid *map)
{
	float_t	scale_x;
	float_t	scale_y;

	scale_x = compute_axis_scale(map->x_min, map->x_max, WIN_W);
	scale_y = compute_axis_scale(map->y_min, map->y_max, WIN_H);
	return (fminf(scale_x, scale_y));
}

void	scale(t_grid *map)
{
	float_t	scale;

	map->x_min = 0;
	map->x_max = 0;
	map->y_min = 0;
	map->y_max = 0;
	maxs_and_mins(map);
	scale = compute_final_scale(map);
	zoom(map, scale);
}
