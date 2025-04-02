/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:11:43 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/02 12:25:02 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

t_grid	*save_original_map(t_core *content)
{
	t_coord	*act;
	int		i;

	content->map_backup = malloc(sizeof(t_grid));
	if (content->map_backup == NULL)
		return (NULL);
	content->map_backup->arr = malloc(content->render_map->axis_x
			* content->render_map->axis_y * sizeof(t_coord));
	if (content->map_backup->arr == NULL)
		return (NULL);
	i = 0;
	while (i < content->render_map->axis_x * content->render_map->axis_y)
	{
		act = content->render_map->arr + i;
		*(content->map_backup->arr + i) = *act;
		i++;
	}
	return (content->map_backup);
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
	save_original_map(content);
	return (map);
}
