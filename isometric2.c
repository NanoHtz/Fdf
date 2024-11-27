/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:47:21 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/26 20:32:52 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Podremos cambiar las macros ???

//Make iso view

#include "fdf.h"

void rot_x(float_t angle, t_map *map)
{
	t_mrotacional rotating_x;

	rotating_x = (t_mrotacional){
		1, 0, 0,
		0, cos(angle), -sin(angle),
		0, sin(angle), cos(angle)};
	change_map(rotating_x, map);
}

void rot_y(float_t angle, t_map *map)
{
	t_mrotacional rotating_y;

	rotating_y = (t_mrotacional){
		cos(angle), 0, sin(angle),
		0, 1, 0,
		-sin(angle), 0, cos(angle)};
	change_map(rotating_y, map);
}

void	maxs_and_mins(t_map *map)
{
	t_cds	*act;
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

void	scale(t_map *map)
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

void	restore_map(t_content *content)
{
	int			i;

	i = 0;
	while (i < content->map->axis_x * content->map->axis_y)
	{
		*(content->map->arr + i) = *(content->original_map->arr + i);
		i++;
	}
	content->map->i = (t_cds){1, 0, 0, 0x0};
	content->map->j = (t_cds){0, 1, 0, 0x0};
	content->map->k = (t_cds){0, 0, 1, 0x0};
}

