/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:47:21 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/26 20:59:11 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Podremos cambiar las macros ???

//Make iso view

#include "fdf.h"

void isometric(t_map *map)
{
	rot_x(-M_PI_2, map);
	rot_y(M_PI_4, map);
	rot_x(ISO, map);
}

void	zoom(t_map *map, float_t factor)
{
	t_mrotacional	scale;

	scale = (t_mrotacional){factor, 0, 0, 0, factor, 0, 0, 0, factor};
	change_map(scale, map);
}

t_map *change_map(t_mrotacional rot, t_map *map)
{
	t_cds	*act;
	int		i;

	i = 0;
	while(i < map->axis_x * map->axis_y )
	{
		act = map->arr +i;
		*act = vector_multiplication(rot , *act);
		i++;
	}
	map->i = vector_multiplication(rot , map->i);
	map->j = vector_multiplication(rot , map->j);
	map->k = vector_multiplication(rot , map->k);
	return(map);
}

void	scale_z(t_content *content, float_t factor)
{
	t_mrotacional	scale_z;
	t_mrotacional	tmp;
	t_map		*map;

	map = content->map;
	tmp = (t_mrotacional){map->i.x, map->i.y, map->i.z,
		map->j.x, map->j.y, map->j.z,
		map->k.x, map->k.y, map->k.z};
	scale_z = (t_mrotacional){1, 0, 0, 0, 1, 0, 0, 0, factor};
	restore_map(content);
	change_map(scale_z, map);
	change_map(tmp, map);
}

void	translate(t_map *map, t_cds offset)
{
	int		i;
	t_cds	*cur;

	i = 0;
	while (i < map->axis_x * map->axis_y)
	{
		cur = map->arr + i;
		*cur = vec_add(*cur, offset);
		i++;
	}
}
//scale_z
//traslate
