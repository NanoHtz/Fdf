/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:47:21 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/03/31 11:25:49 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

t_cds	vector_multiplication(t_mrotacional matrix, t_cds point)
{
	t_cds	r;

	r.x = point.x * matrix.i1j1 + point.y * matrix.i2j1 + point.z * matrix.i3j1;
	r.y = point.x * matrix.i1j2 + point.y * matrix.i2j2 + point.z * matrix.i3j2;
	r.z = point.x * matrix.i1j3 + point.y * matrix.i2j3 + point.z * matrix.i3j3;
	r.color = point.color;
	return (r);
}

t_map	*change_map(t_mrotacional rot, t_map *map)
{
	t_cds	*act;
	int		i;

	i = 0;
	while (i < map->axis_x * map->axis_y)
	{
		act = map->arr + i;
		*act = vector_multiplication(rot, *act);
		i++;
	}
	map->i = vector_multiplication(rot, map->i);
	map->j = vector_multiplication(rot, map->j);
	map->k = vector_multiplication(rot, map->k);
	return (map);
}

void	rot_y(float_t angle, t_map *map)
{
	t_mrotacional	rotating_y;

	rotating_y = (t_mrotacional){
		cos(angle), 0, sin(angle),
		0, 1, 0,
		-sin(angle), 0, cos(angle)};
	change_map(rotating_y, map);
}

void	rot_x(float_t angle, t_map *map)
{
	t_mrotacional	rotating_x;

	rotating_x = (t_mrotacional){
		1, 0, 0,
		0, cos(angle), -sin(angle),
		0, sin(angle), cos(angle)};
	change_map(rotating_x, map);
}

void	isometric(t_map *map)
{
	rot_x(-M_PI_2, map);
	rot_y(M_PI_4, map);
	rot_x(ISO, map);
}
