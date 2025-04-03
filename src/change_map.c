/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:46:54 by fgalvez-          #+#    #+#             */
/*   Updated: 2025/04/01 19:46:54 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/fdf/fdf.h"

t_grid	*change_map(t_mrot rot, t_grid *map)
{
	t_coord	*act;
	int		i;

	i = 0;
	while (i < map->axis_x * map->axis_y)
	{
		act = map->arr + i;
		*act = mult_vec(rot, *act);
		i++;
	}
	map->i = mult_vec(rot, map->i);
	map->j = mult_vec(rot, map->j);
	map->k = mult_vec(rot, map->k);
	return (map);
}
