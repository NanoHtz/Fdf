/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:11:43 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/03/28 08:58:20 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

t_map	*save_original_map(t_content *content)
{
	t_cds	*act;
	int		i;

	content->original_map = malloc(sizeof(t_map));
	if (content->original_map == NULL)
		return (NULL);
	content->original_map->arr = malloc(content->map->axis_x
			* content->map->axis_y * sizeof(t_cds));
	if (content->original_map->arr == NULL)
		return (NULL);
	i = 0;
	while (i < content->map->axis_x * content->map->axis_y)
	{
		act = content->map->arr + i;
		*(content->original_map->arr + i) = *act;
		i++;
	}
	return (content->original_map);
}

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
