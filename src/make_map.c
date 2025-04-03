/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:11:43 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/03 10:54:19 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

t_grid	*save_grid(t_core *core)
{
	int		total;
	int		i;
	t_coord	*ptr;

	core->map_backup = malloc(sizeof(t_grid));
	if (!core->map_backup)
		return (NULL);
	total = core->render_map->axis_x * core->render_map->axis_y;
	core->map_backup->arr = malloc(sizeof(t_coord) * total);
	if (!core->map_backup->arr)
	{
		free(core->map_backup);
		return (NULL);
	}
	i = 0;
	while (i < total)
	{
		ptr = &core->render_map->arr[i];
		core->map_backup->arr[i] = *ptr;
		i++;
	}
	return (core->map_backup);
}

t_grid	*make_map(t_core *content)
{
	t_grid		*map;

	map = content->render_map;
	map->max_z = 0;
	map->min_z = 0;
	map->i = (t_coord){1, 0, 0, 0x0};
	map->j = (t_coord){0, 1, 0, 0x0};
	map->k = (t_coord){0, 0, 1, 0x0};
	if (map->axis_x <= 0 || map->axis_y <= 0)
	{
		ft_putstr_fd("Error: Invalid map dimensions.\n", 2);
		return (NULL);
	}
	map->arr = malloc(map->axis_x * map-> axis_y * sizeof(t_coord));
	if (map->arr == NULL)
	{
		ft_putstr_fd("Error: Memory allocation failed.\n", 2);
		return (NULL);
	}
	map->dist = 10;
	points_on_map(content, map);
	color_gradient(map, content->palette_id);
	save_grid(content);
	return (map);
}
