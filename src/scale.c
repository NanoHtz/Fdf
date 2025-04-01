/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:47:21 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/01 19:48:55 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

void	zoom(t_grid *map, float_t factor)
{
	t_mrot	scale;

	scale = (t_mrot){factor, 0, 0, 0, factor, 0, 0, 0, factor};
	change_map(scale, map);
}

void	maxs_and_mins(t_grid *map)
{
	t_coord	*act;
	int		i;

	i = 0;
	while (i < map->axis_x * map->axis_y)
	{
		act = map->arr + i;
		if (act->x < map->x_min)
			map->x_min = act->x;
		if (act->x > map->x_max)
			map->x_max = act->x;
		if (act->y < map->y_min)
			map->y_min = act->y;
		if (act->y > map->y_max)
			map->y_max = act->y;
		i++;
	}
}

void	scale(t_grid *map)
{
	float_t	x_scaled;
	float_t	y_scaled;

	map->y_min = 0;
	map->y_max = 0;
	map->x_min = 0;
	map->x_max = 0;
	maxs_and_mins(map);
	x_scaled = (WIN_W / 2 - 30) / fmaxf(abs(map->x_max), abs(map->x_min));
	y_scaled = (WIN_H / 2 - 30) / fmaxf(abs(map->y_max), abs(map->y_min));
	zoom(map, fminf(x_scaled, y_scaled));
}
