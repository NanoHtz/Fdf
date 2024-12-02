/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:11:43 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/11/29 12:12:38 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

t_map	*make_map(t_content *content)
{
	t_map		*map;

	map = content->map;
	map->max_z = 0;
	map->min_z = 0;
	map->i = (t_cds){1, 0, 0, 0x0};
	map->j = (t_cds){0, 1, 0, 0x0};
	map->k = (t_cds){0, 0, 1, 0x0};
	if (map->axis_x <= 0 || map->axis_y <= 0)
	{
		ft_putstr_fd("Error: Invalid map dimensions.\n", 2);
		return (NULL);
	}
	map->arr = malloc(map->axis_x * map-> axis_y * sizeof(t_cds));
	if (map->arr == NULL)
	{
		ft_putstr_fd("Error: Memory allocation failed.\n", 2);
		return (NULL);
	}
	map->space = 10;
	points_on_map(content, map);
	color_gradient(map);
	save_original_map(content);
	return (map);
}

void	z_range(t_map *map, t_cds *act)
{
	if (act->z < map->min_z)
		map->min_z = act->z;
	if (act->z > map->max_z)
		map->max_z = act->z;
}

void	color_gradient(t_map *map)
{
	t_cds	base;
	t_cds	max;
	t_cds	min;
	t_cds	*act;
	int		i;

	base = (t_cds){0, 0, 0, PURPLE};
	max = (t_cds){0, 0, map->max_z, HIGH_PURPLE};
	min = (t_cds){0, 0, map->min_z, LOW_PURPLE};
	i = 0;
	while (i < map->axis_x * map->axis_y)
	{
		act = map->arr + i;
		if (act->z > 0)
			act->color = gradient(*act, base, max);
		if (act->z < 0)
			act->color = gradient(*act, base, min);
		i++;
	}
}
