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

void	rotate_canonic(t_grid *grid, t_mrot rot)
{
	grid->i = mult_vec(rot, grid->i);
	grid->j = mult_vec(rot, grid->j);
	grid->k = mult_vec(rot, grid->k);
}

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
	rotate_canonic(map, rot);
	return (map);
}
